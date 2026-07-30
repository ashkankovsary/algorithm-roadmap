# F030 - Binary Search on Answer

## Overview

Binary Search on Answer is a technique that applies the idea of binary
search not to a sorted array, but to the space of possible answers to a
problem. Instead of searching for a value inside a data structure, the
algorithm searches for the smallest (or largest) value that satisfies a
given condition, relying on that condition being monotonic across the
answer space.

## When to Use

- The question asks for an optimal numeric answer such as "minimum X such
  that ..." or "maximum X such that ...".
- There exists a way to check, for a fixed candidate answer, whether it is
  feasible (a `check` function).
- The feasibility of candidate answers is monotonic: once a candidate
  works, every "easier" candidate on one side of it also works (and vice
  versa).

## When NOT to Use

- The feasibility condition is not monotonic in the candidate answer.
- The `check` function itself is too expensive to call `O(log R)` times
  within the time limit, where `R` is the size of the answer space.
- The answer is not numeric or does not have a well-defined ordered
  search space.

## Pattern Recognition

Look for phrasing such as "minimize the maximum ...", "maximize the
minimum ...", "smallest value such that ...", or "is it possible to
achieve X with a budget of at most k operations". These often hide a
monotonic `check` function underneath.

---

## Intuition

A normal binary search relies on an array being sorted: the array itself
provides the monotonic structure. Binary Search on Answer replaces the
array with a boolean sequence produced by a `check` function evaluated
over a range of candidate answers.

Two mirror-image patterns show up in practice:

- **Smallest true**: the sequence of `check` results looks like
  `false, false, ..., false, true, true, ..., true`, and the goal is to
  find the first `true`.
- **Largest true**: the sequence looks like
  `true, true, ..., true, false, false, ..., false`, and the goal is to
  find the last `true`.

Recognizing which of these two shapes a problem has determines how the
search boundaries are updated.

## Prerequisites

- **F010 - C++ STL Essentials**: used for basic containers (`std::vector`)
  and simple STL algorithms (e.g. finding the maximum element to build an
  initial search boundary).

---

## Complexity Analysis

- **Time:** `O(log R * C)`, where `R` is the size of the answer search
  space and `C` is the cost of a single call to `check`.
- **Space:** `O(1)` additional space, beyond whatever the `check`
  function itself requires.

---

## Implementation Walkthrough

The implementation provides two small generic functions:

- `binarySearchSmallestTrue(lo, hi, check)` finds the smallest value in
  `[lo, hi]` for which `check` returns `true`, assuming the sequence of
  results is `false...false, true...true`. The midpoint is rounded down
  (`mid = lo + (hi - lo) / 2`) and, on a `true` result, the upper bound is
  narrowed to `mid` (not `mid - 1`), since `mid` itself might be the
  answer.
- `binarySearchLargestTrue(lo, hi, check)` finds the largest value in
  `[lo, hi]` for which `check` returns `true`, assuming the sequence of
  results is `true...true, false...false`. The midpoint is rounded **up**
  (`mid = lo + (hi - lo + 1) / 2`) because the lower bound advances to
  `mid` on a `true` result; rounding down here would leave `lo` unchanged
  whenever `lo` and `hi` are one apart, causing an infinite loop.

Both functions take the boundaries as a closed interval `[lo, hi]` and
assume the caller has already established that a valid answer exists
somewhere in that interval.

See `implementation.cpp` for the full generic code and two worked
examples, one for each pattern.

---

## Common Mistakes

**Implementation mistakes:**

- Computing the midpoint as `(lo + hi) / 2` instead of
  `lo + (hi - lo) / 2`, which can overflow when both bounds are large.
- Using the wrong loop condition (`lo <= hi` instead of `lo < hi`), which
  does not match the convergence logic used here and can loop forever.
- Using the wrong rounding direction for the midpoint: rounding down when
  searching for the largest `true` (pattern `lo = mid`) can freeze the
  search when `lo` and `hi` are exactly one apart.
- Choosing an initial `lo` (for the largest-true pattern) or an initial
  `hi` (for the smallest-true pattern) that is not guaranteed to satisfy
  `check`, which silently produces a wrong answer instead of an error.

**Logical mistakes:**

- Assuming a `check` function is monotonic without verifying it. If it
  is not, the search still runs and still returns *something*, but that
  something is not necessarily correct.
- Mixing up the "smallest true" and "largest true" patterns, which use
  opposite update rules for `lo` and `hi`.

**Edge case(s):**

- A search space where no candidate is feasible (the condition should be
  detected before or during the search, not assumed away).
- A search space that already contains a single candidate (`lo == hi`
  from the start).

---

## Practice Problems

- [0006 - Ternary String](../../../problems/codeforces/0000-0099/0006-ternary-string/README.md) — a direct application of the smallest-true pattern.
- [0007 - Hard Process](../../../problems/codeforces/0000-0099/0007-hard-process/README.md) — a largest-true application that also highlights a common boundary mistake.

---

## Related Algorithms

- F035 - Two Pointers, which relies on a similar monotonicity idea but
  slides a window instead of searching an answer space.
- SA035 - Meet in the Middle, which can be combined with this technique
  in some problems.

## Learning Path

This topic builds directly on F010 and leads naturally into F035 (Two
Pointers), which explores a related but distinct way of exploiting
monotonic structure in a problem.
