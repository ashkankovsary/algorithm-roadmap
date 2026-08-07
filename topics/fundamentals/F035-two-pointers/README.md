# F035 - Two Pointers

## Overview

Two Pointers is a technique where two (or occasionally more) indices are
maintained over a linear structure, usually a sorted array or string, and
moved according to a rule instead of using nested loops. Many problems
that a brute-force approach would solve in `O(n^2)` can be solved in a
single `O(n)` pass once the data is sorted and the search space has a
monotonic property.

## When to Use

- The input is sorted, or can be sorted without losing information the
  problem needs.
- Advancing one pointer never makes the answer worse, only better or
  unchanged (the monotonic property).
- The problem asks for a pair, a subarray, or a merge-like combination of
  elements under some sum, difference, or matching condition.

## When NOT to Use

- The data cannot be sorted (or sorting destroys information the problem
  depends on, such as original indices, without extra bookkeeping).
- The feasibility of a candidate position is not monotonic, so moving a
  pointer forward could skip a valid answer.
- The relationship between elements requires looking arbitrarily far
  backward and forward at the same time, better suited to a different
  technique.

## Pattern Recognition

Look for phrasing such as "find a pair that sums to ...", "remove
duplicates from a sorted array", "merge two sorted sequences", or
"longest/shortest subarray satisfying ...". These often hide one of two
underlying shapes: two pointers starting at opposite ends of the same
array and moving toward each other, or two pointers starting together
and moving in the same direction at different speeds.

---

## Intuition

Consider finding a pair in a sorted array whose sum equals a target
value. A brute-force search checks every pair, but sorting exposes a
shortcut: placing one pointer at each end of the array, the sum can only
be too small or too large. If it is too small, the left pointer must
move right, since even the largest remaining value cannot help make a
smaller left value into a valid pair without doing so. If it is too
large, the right pointer must move left, by symmetric reasoning. Each
move discards a set of candidates that provably cannot contain a valid
answer, so no move can accidentally skip the answer.

This is the same monotonic idea in two shapes:

- **Opposite direction**: pointers start at the two ends of one array and
  move toward each other (e.g. sorted pair-sum problems).
- **Same direction**: pointers start together and move forward at
  different speeds, one exploring ahead while the other marks the last
  valid position (e.g. removing duplicates from a sorted array).

A third common shape merges two separately sorted sequences using one
pointer per sequence, advancing whichever pointer currently points to the
smaller element.

## Prerequisites

- **F010 - C++ STL Essentials**: used for `std::vector` indexing and
  `std::sort`, since most Two Pointers problems assume sorted input (or
  require sorting it first).

---

## Complexity Analysis

- **Time:** `O(n)`. In every variant, each pointer advances at most `n`
  times over the course of the algorithm; the total work is the sum of
  pointer movements, not their product, which is what allows the
  technique to beat an `O(n^2)` brute-force search.
- **Space:** `O(1)` additional space beyond the input itself — only a
  constant number of index variables are needed.

---

## Implementation Walkthrough

Two representative patterns are implemented:

- `twoSumSorted(arr, target)` uses the opposite-direction pattern. It
  keeps a `left` and `right` index and, depending on whether the current
  sum is below or above `target`, advances `left` or retreats `right`,
  narrowing the search space by exactly one element every step.
- `removeDuplicates(arr)` uses the same-direction pattern. A `slow` index
  marks the last unique element written so far, while a `fast` index
  scans ahead; whenever `fast` finds a new value, it is copied into the
  position right after `slow`. The function modifies the array in place
  and returns the new logical length — elements beyond that length are
  left in an unspecified state and must not be read by the caller.

See `implementation.cpp` for the full code and two runnable examples.

---

## Common Mistakes

**Implementation mistakes:**

- Forgetting that `removeDuplicates` is in-place: only indices `0` to
  `newLength - 1` are valid afterward. Reading past that point returns an
  unspecified value rather than a clear error, which makes the bug easy
  to miss.
- Passing the array by value instead of by reference to a function meant
  to modify it in place, silently operating on a copy instead of the
  caller's array.
- Using `left <= right` instead of `left < right` in the
  opposite-direction pattern, which allows an element to be paired with
  itself.
- Applying Two Pointers to unsorted data without sorting first, or
  sorting without preserving original indices when the problem needs
  them.

**Logical mistakes:**

- Assuming the technique always finds an optimal answer without checking
  that the problem's condition is actually monotonic.
- Starting the `slow` index anywhere other than `0` in the same-direction
  pattern, when the first element is always unique by definition.
- Moving the wrong pointer relative to the comparison result, which
  breaks the monotonic argument the algorithm depends on.

**Edge case(s):**

- An empty array, which must be handled before any indexing happens.
- An array with a single element.
- No valid pair or no duplicates at all.
- An array where every element is identical.

---

## Practice Problems

- [0008 - BerSU Ball](../../../problems/codeforces/0000-0099/0008-bersu-ball/README.md) — opposite-direction pointers matching two separately sorted arrays.
- [0009 - Books](../../../problems/codeforces/0000-0099/0009-books/README.md) — same-direction pointers as a sliding window bounded by a running sum.

---

## Related Algorithms

- F030 - Binary Search on Answer, which relies on a similar monotonicity
  idea but searches an answer space instead of sliding a window.
- F040 - Sliding Window, a direct generalization of the same-direction
  pattern introduced here.

## Learning Path

This topic builds directly on F010 and leads naturally into F040
(Sliding Window), which generalizes the same-direction pointer pattern
into windows of varying size governed by a broader class of conditions.
