# F020 - Recursion

## Overview

Recursion is a technique where a function solves a problem by calling
itself on a smaller instance of the same problem. Every recursive
function is built from two parts: a **base case**, which is the
simplest version of the problem and is solved directly, and a
**recursive case**, which reduces the problem and calls the function
again on that smaller version.

Recursion exists because many problems have a naturally self-similar
structure — the solution to the full problem depends directly on the
solution to a smaller version of itself. Examples include factorial,
tree traversal, divide-and-conquer algorithms, and backtracking.

## When to Use

- The problem can naturally be defined as "solve this = combine the
  solutions of smaller versions of the same problem" (a recurrence
  relation).
- The data or structure being processed is itself recursive (trees,
  nested structures, divide-and-conquer splits).
- The problem involves exploring all possibilities (backtracking,
  generating subsets/permutations).

## When NOT to Use

- The problem has a simple linear structure where a loop is clearer
  and avoids function-call overhead.
- The recursion depth could be very large (hundreds of thousands of
  calls), risking a stack overflow.

## Pattern Recognition

Look for problems that can be phrased as: "If I already had the answer
for a smaller input, how would I get the answer for the current
input?" A recurrence relation you can write on paper, such as
`f(n) = n + f(n - 1)`, is a strong signal that recursion fits.

---

## Intuition

Recursion is built on a "leap of faith": trust that the function
already works correctly on a smaller input, and only worry about how
to build the current step on top of that trusted result.

Every recursive call goes through two phases:

1. **Descent** — the function keeps calling itself with a smaller
   input, without doing any real computation yet, until it reaches the
   base case.
2. **Unwind** — once the base case returns a value, each waiting call
   resumes, combines its own step with the result it received, and
   returns that combined value to the caller above it.

For example, with `sum(n) = n + sum(n - 1)` and `sum(0) = 0`, the calls
descend from `sum(4)` down to `sum(0)`, and only on the way back up do
the additions actually happen: `sum(0) = 0`, `sum(1) = 1`, `sum(2) = 3`,
and so on, until `sum(4) = 10`.

## Prerequisites

- [F010 - C++ STL Essentials](../F010-cpp-stl-essentials/README.md) —
  recursion only requires being comfortable with defining and calling
  functions, passing parameters, and basic conditionals, all of which
  are covered in F010. No data structure or other algorithm is required
  beforehand.

---

## Complexity Analysis

- **Time:** Determined by the total number of calls in the recursion
  tree multiplied by the work done per call (excluding further
  recursive calls). A function that makes exactly one recursive call
  per invocation (linear recursion) costs O(depth); a function that
  makes multiple recursive calls per invocation can cost significantly
  more, e.g. O(2ⁿ) for naive Fibonacci.
- **Space:** Determined by the maximum recursion depth, since every
  pending call keeps its stack frame in memory until it returns. A
  function that recurses to depth `n` uses O(n) additional space, even
  if its time complexity is smaller.

---

## Implementation Walkthrough

See [`implementation.cpp`](./implementation.cpp) for a complete,
runnable example with a `main()` that demonstrates each function. It
contains three examples:

- `sum(n)` — the canonical linear recursion example, matching the
  recurrence discussed above.
- `power(base, exp)` — computes `baseᵉˣᵖ` recursively; uses `long long`
  for the base and return type since results overflow `int` quickly.
- `sumVector(v, index)` — sums the elements of a `std::vector`, passed
  by `const&` to avoid copying the container on every call, since
  copying a container (unlike a plain `int`) is not free.

The only non-obvious design choice across these examples is the use of
`const std::vector<int>&` in `sumVector`: passing containers by
reference avoids an O(size) copy on every recursive call, which would
otherwise turn a linear-time function into a quadratic-time one.

---

## Common Mistakes

**Implementation mistakes:**

- Forgetting the base case entirely, or writing a condition that is
  never reached, causing infinite recursion and a stack overflow.
- Failing to actually shrink the problem in the recursive call (e.g.
  calling `sum(n)` instead of `sum(n - 1)`), which also leads to
  infinite recursion.
- Letting results overflow their data type (e.g. using `int` for
  `power` results that exceed its range).

**Logical mistakes:**

- Getting the order of combination wrong for non-commutative operations
  (e.g. confusing `n op f(n-1)` with `f(n-1) op n`).
- Assuming a value is implicitly passed between recursive layers
  instead of explicitly returning it.
- Trying to mentally trace the entire call chain instead of trusting
  the recursive leap of faith, which makes more complex recursive
  problems feel harder than they are.

**Edge case(s):**

- Inputs that are already the base case (e.g. `sum(0)`) must return the
  correct value with no extra recursive calls.
- Invalid inputs (e.g. a negative exponent in `power`) are not handled
  by the basic version shown here and can cause infinite recursion.
- Very large inputs can cause a stack overflow purely from recursion
  depth, even when the logic is otherwise correct.

---

## Practice Problems

- [0004 - Right-Left Cipher](../../../problems/codeforces/0000-0099/0004-right-left-cipher/README.md)

---

## Related Algorithms

Recursion is a foundation for many topics later in the roadmap,
including Dynamic Programming Fundamentals (DP005), Merge Sort
(SA010), Backtracking (SP015), Depth-First Search (G010), and Tree
Traversal (T010).

## Learning Path

F020 follows F010 (C++ STL Essentials) and precedes every topic listed
above under Related Algorithms, since all of them build directly on
the idea of a function calling itself on a smaller instance of the
problem.
