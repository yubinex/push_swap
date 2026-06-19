# push_swap checklist

## Foundation

### Stack structure
- [] Define node type (value, next, prev)
- [ ] Define stack type (top, bottom, size)
- [ ] `stack_new` — allocate and return empty stack
- [ ] `stack_push` — push a value to the top
- [ ] `stack_pop` — remove and return the top value
- [ ] `stack_peek` — return top value without removing
- [ ] `stack_free` — free all nodes and the stack

### 11 operations
Each must manipulate the stack(s) AND print its name to stdout.
- [ ] `sa` — swap top two of a
- [ ] `sb` — swap top two of b
- [ ] `ss` — sa and sb simultaneously
- [ ] `pa` — push top of b onto a
- [ ] `pb` — push top of a onto b
- [ ] `ra` — rotate a (top goes to bottom)
- [ ] `rb` — rotate b
- [ ] `rr` — ra and rb simultaneously
- [ ] `rra` — reverse rotate a (bottom goes to top)
- [ ] `rrb` — reverse rotate b
- [ ] `rrr` — rra and rrb simultaneously

### Input parsing
- [ ] Detect and store `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` flags
- [ ] Collect integer arguments (skip flags)
- [ ] Reject non-integers → print `Error\n` to stderr and exit
- [ ] Reject integers outside int range → same
- [ ] Reject duplicate values → same
- [ ] If no integers given, exit silently

### Disorder metric
- [ ] Implement `compute_disorder` (count inversion pairs, divide by total pairs)
- [ ] Call it **before** any stack moves

### Main flow
- [ ] Parse flags and integers
- [ ] If already sorted, output nothing and exit
- [ ] Compute disorder
- [ ] Dispatch to selected algorithm (default: adaptive)
- [ ] If `--bench`, print to stderr after sorting:
  - [ ] `[bench] disorder:  XX.XX%`
  - [ ] `[bench] strategy:  Name / O(...)`
  - [ ] `[bench] total_ops:  N`
  - [ ] `[bench] sa: N  sb: N  ss: N  pa: N  pb: N`
  - [ ] `[bench] ra: N  rb: N  rr: N  rra: N  rrb: N  rrr: N`

---

## Algorithms

### Simple — O(n²)
- [ ] Implement (e.g. selection sort, insertion sort, bubble sort)

### Medium — O(n√n)
- [ ] Implement (e.g. chunk-based sort with √n chunks)

### Complex — O(n log n)
- [ ] Implement (e.g. LSD radix sort, merge sort adaptation)

### Adaptive
- [ ] If disorder < 0.2 → use simple
- [ ] If disorder 0.2–0.5 → use medium
- [ ] If disorder ≥ 0.5 → use complex

---

## Performance targets (verified by checker)
- [ ] 100 numbers < 700 ops (excellent) / < 1500 (good) / < 2000 (pass)
- [ ] 500 numbers < 5500 ops (excellent) / < 8000 (good) / < 12000 (pass)
