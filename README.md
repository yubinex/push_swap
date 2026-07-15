*This project has been created as part of the 42 curriculum by jhauck, jubaur.*

# push_swap

Sort data on a stack using the lowest possible number of operations.

## Description

**push_swap** is a sorting algorithm project that operates under tight constraints: you have two stacks (`a` and `b`), a fixed set of 11 operations, and the goal is to sort the integers in stack `a` in ascending order using as few operations as possible.

The program reads a list of integers as arguments, computes the optimal sequence of Push_swap operations, and prints them one per line to stdout. The project requires implementing **four distinct sorting strategies** that target different complexity classes, plus an adaptive mode that selects the best strategy based on a measured disorder metric.

### Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top two elements of stack a |
| `sb` | Swap the top two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of b onto a |
| `pb` | Push top of a onto b |
| `ra` | Rotate a upward (top becomes bottom) |
| `rb` | Rotate b upward (top becomes bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate a (bottom becomes top) |
| `rrb` | Reverse rotate b (bottom becomes top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Instructions

### Compilation

```sh
make
```

This produces the `push_swap` binary. Standard Makefile rules are available:

```sh
make        # build
make clean  # remove object files
make fclean # remove objects and binary
make re     # full rebuild
```

### Usage

```sh
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

**Strategy flags** (optional, default is `--adaptive`):

| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Bubble sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | LSD radix sort | O(n log n) |
| `--adaptive` | Auto-selects based on disorder | varies |

**Other flags:**

- `--bench` — print performance metrics to stderr after sorting (disorder, strategy used, total ops, per-operation counts)

**Examples:**

```sh
# Sort 5 numbers with the default adaptive strategy
./push_swap 2 1 3 6 5 8

# Force the O(n log n) radix sort
./push_swap --complex 5 4 3 2 1

# Count operations for 500 random numbers
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l

# Verify correctness with the checker
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG

# Run with benchmark output redirected to a file
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt

# Save operations to a file
./push_swap 5 4 3 2 1 > ops.txt
cat ops.txt
```

**Error handling:**

The program prints `Error` to stderr and exits with status 1 for:
- Arguments that are not integers
- Integers outside the int range
- Duplicate values

## Algorithms

### Disorder metric

Before any sorting begins, the program computes a **disorder score** between 0 and 1 that measures how far the stack is from sorted order. It counts all pairs `(i, j)` where `i < j` but `a[i] > a[j]` (inversions) and divides by the total number of pairs:

```
disorder = inversions / total_pairs
```

A disorder of `0` means already sorted; `1` means fully reversed. This score is computed once before any moves and drives the adaptive strategy selection.

### Strategy 1 — Simple: Bubble Sort — O(n²)

**When used:** disorder < 0.2 (nearly sorted input)

A bubble sort adaptation on the two stacks. The algorithm repeatedly finds the next element out of place and uses rotate operations to bring it to the top, swapping as needed. For nearly-sorted inputs this terminates quickly with very few operations since most elements are already in position.

**Complexity argument:** Each pass over n elements costs at most n rotates. In the worst case this is O(n²) operations, but for low-disorder inputs the constant factor is very small.

### Strategy 2 — Medium: Chunk-based Sort — O(n√n)

**When used:** 0.2 ≤ disorder < 0.5 (partially shuffled input)

The stack is partitioned into √n equally-sized chunks by rank. Each chunk is pushed from stack `a` to stack `b` in order: for each chunk, we find the nearest element belonging to that chunk (rotating forward or backward, whichever is shorter), push it to `b`, and optionally rotate `b` to keep the larger half of each chunk on top. After all chunks are pushed, elements are pulled back from `b` to `a` by always finding and rotating the maximum to the top.

**Complexity argument:** There are √n chunks, and processing each chunk requires at most O(n) rotations to locate and push all its elements, giving O(n√n) total Push_swap operations. The pull-back phase is also O(n) rotations for n elements.

### Strategy 3 — Complex: LSD Radix Sort — O(n log n)

**When used:** disorder ≥ 0.5 (highly disordered input)

Elements are first assigned rank indices (0 to n-1) so they can be treated as binary numbers. The algorithm then performs log₂(n) passes over the stack, one per bit from least significant to most significant. In each pass, elements whose current bit is 0 are pushed to `b`, and elements whose bit is 1 are rotated to the back of `a`. After each pass all elements are pulled back from `b` to `a`, leaving them sorted by the bits processed so far.

**Complexity argument:** There are ⌈log₂(n)⌉ passes, each touching all n elements with exactly n push/rotate operations and n pull-back operations — giving O(n log n) total operations.

### Strategy 4 — Adaptive (default)

Selects among the three strategies above based on the pre-computed disorder score:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | Simple (bubble sort) | O(n²) |
| 0.2 – 0.5 | Medium (chunk-based) | O(n√n) |
| ≥ 0.5 | Complex (LSD radix) | O(n log n) |

**Threshold rationale:** The 0.2 threshold reflects that bubble sort is competitive when fewer than 20% of pairs are inverted — the expected number of rotations stays low. Above 0.5 (more than half the pairs are inverted) the input is effectively random and radix sort's guaranteed O(n log n) outperforms chunk-based methods. The middle band benefits from chunk-based sorting, which has a lower constant factor than radix in practice for partially ordered data.

### Tiny sort (≤ 5 elements)

When `--adaptive` is selected (the default) and the input has 5 or fewer elements, a dedicated hand-optimized routine is used instead of the three main strategies. Explicit flags (`--simple`, `--medium`, `--complex`) bypass this and run the named algorithm on any input size.

The routine handles each size with the minimum possible operations:

- **Size 2:** swap if out of order (`sa`). At most 1 operation.
- **Size 3:** a decision tree covers all 6 permutations in at most 2 operations — one rotation to move the maximum to the bottom, then one swap if the top two are still inverted.
- **Size 4:** push the minimum to `b` (at most 2 rotates + `pb`), sort the remaining 3 with the size-3 routine, push the minimum back (`pa`). At most 6 operations.
- **Size 5:** push the two smallest to `b` in order (at most 4 rotates + 2× `pb`), sort the remaining 3, push both back (`pa pa`). At most 12 operations.

**Complexity argument:** The input size is bounded by a constant (5), so the number of operations is bounded by a constant regardless of input. This is O(1) in the Push_swap operation model.

## Performance targets

| Input size | Pass | Good | Excellent |
|------------|------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

## Contributions

| Contributor | Responsibilities |
|-------------|-----------------|
| **jhauck** | Core infrastructure (stack, all 11 operations, argument parsing, error handling), disorder metric, benchmark output (`--bench`), LSD radix sort (`--complex`), tiny sort routine |
| **jubaur** | Strategy dispatcher and main entry point, bubble sort (`--simple`), chunk-based sort (`--medium`), rank index assignment, adaptive threshold logic |

Both contributors were present for and contributed to the design of the overall architecture and the selection of algorithms. All code was reviewed and understood by both before being merged.

## Resources

- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching* — foundational reference on sorting algorithms and complexity
- Wikipedia — [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) — LSD/MSD radix sort explanation
- Wikipedia — [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) — basis for the disorder metric
- 42 Push_swap subject (v1.1) — `en.subject.pdf` in this repository

### AI usage

All generated suggestions were reviewed, tested, and understood before being integrated. No code was copy-pasted without verification.
