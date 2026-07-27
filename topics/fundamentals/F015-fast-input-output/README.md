# F015 - Fast Input / Output

## Overview

By default, C++'s `cin`/`cout` streams are synchronized with C's `stdio`
(`scanf`/`printf`), and `cin` automatically flushes `cout` before every
read. These defaults exist for safety and interoperability, but they add
a constant-factor overhead to every I/O operation.

When a program has to read or write a large number of values (commonly
10^5 or more), this overhead can be large enough to cause a correct,
efficiently-designed algorithm to fail with a Time Limit Exceeded (TLE)
verdict. Fast Input/Output is not an algorithm — it is a small, standard
setup used at the start of a program to remove this overhead.

---

## When to Use

Use this setup whenever a problem needs:

- A large volume of input or output (roughly ≥ 10^5 lines/values).
- An algorithm whose time complexity is already correct and efficient,
  where I/O overhead alone could still cause a TLE.

## When NOT to Use

- In **interactive problems**, where the program must flush output and
  wait for a judge's response — untying `cin` from `cout` can delay
  output and make the interaction fail.
- When the program mixes `cin`/`cout` with `scanf`/`printf` in the same
  run — disabling synchronization makes the relative order of
  reads/writes between the two mechanisms unreliable.

## Pattern Recognition

- "The algorithm's complexity is correct, but the solution still gets
  TLE" → suspect I/O overhead, not the algorithm.
- "Input/output size is large (≥ 10^5)" → apply Fast I/O as a default
  habit, regardless of the algorithm used.

---

## Intuition

Two independent C++ defaults can be disabled when a program only uses
`cin`/`cout` and does not need interactive flushing:

- **Synchronization with C `stdio`**: disabling it removes the
  bookkeeping needed to keep `cin`/`cout` and `scanf`/`printf`
  interchangeable.
- **Tying `cin` to `cout`**: disabling it removes the automatic flush of
  `cout` that normally happens before every `cin` read.

```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

Both are pure setup steps: they change how fast the streams behave, not
what the program computes.

## Prerequisites

- F010 - C++ STL Essentials

---

## Complexity Analysis

| Aspect | Complexity | Notes |
|---|---|---|
| Reading/writing N values | O(N) | Unchanged — this is a constant-factor optimization, not a Big-O improvement |
| Extra space | O(1) | Only a couple of internal flags are changed |

Even though the Big-O stays the same, in Competitive Programming the
constant factor removed here can be the difference between Accepted and
TLE.

---

## Implementation Walkthrough

See [`implementation.cpp`](./implementation.cpp) for the full reference
code. Two design points are worth calling out:

- `ios_base::sync_with_stdio(false);` and `cin.tie(nullptr);` must be the
  very first statements in `main`, before any read or write — calling
  them after some I/O has already happened is undefined behavior.
- `'\n'` is used instead of `endl` when printing: `endl` forces a buffer
  flush on every call, which is expensive in loops with heavy output,
  while `'\n'` only inserts a newline character.

---

## Common Mistakes

**Implementation mistakes:**

- Mixing `cin`/`cout` with `scanf`/`printf` after disabling
  synchronization, causing reads/writes to interleave incorrectly.
- Calling the setup lines after some I/O has already occurred instead of
  at the very start of `main`.
- Using `endl` instead of `'\n'` inside output-heavy loops, which
  cancels out most of the benefit of Fast I/O.
- Forgetting the setup entirely and misdiagnosing the resulting TLE as
  an algorithmic issue.

**Logical mistakes:**

- Assuming this technique improves algorithmic complexity — it only
  reduces a constant factor. An algorithm with poor complexity (e.g.
  O(N^2) with large N) will still fail regardless of I/O speed.
- Applying it in interactive problems without adjusting flushing
  behavior, which can make the program appear to hang.

**Edge case:**

- For extremely large input (e.g. ~10^7 values), even Fast I/O may not
  be enough, and reading the whole input into a buffer manually may be
  required — this is beyond what is normally needed in typical
  Competitive Programming problems.

---

## Practice Problems

- [0003 - Good Array](../../../problems/codeforces/0000-0099/0003-good-array/README.md) — large input size where I/O overhead alone can be enough to cause a TLE if Fast I/O is not enabled.

---

## Related Algorithms

- **F010 - C++ STL Essentials**

## Learning Path

This setup is independent of algorithmic difficulty and is applied from
this point onward in every subsequent topic. The next topic in the
roadmap is **F020 - Recursion**.
