# 0008 - BerSU Ball

## Problem Information

- **Source:** Codeforces 489B
- **Rating:** 1200

Given the dancing skill of `n` boys and `m` girls, form the maximum
possible number of boy-girl pairs such that each pair's skill values
differ by at most 1, and no person is used in more than one pair.

## Related Topics

- [F035 - Two Pointers](../../../../topics/fundamentals/F035-two-pointers/README.md)

## Solution Idea

Both arrays are sorted first. Two pointers then start at the beginning
of each sorted array: if the boy and girl currently pointed at can be
paired (their skill difference is at most 1), both pointers advance and
a match is counted. Otherwise, whichever value is smaller can never be
matched with anything before the other array's current pointer either
(since both arrays are sorted, the gap can only grow), so that pointer
alone advances. This is the opposite-direction pattern applied across
two separate sequences rather than within a single one.

## Complexity Analysis

- **Time:** `O(n log n + m log m)` for sorting both arrays; the two
  pointer scan itself is `O(n + m)`.
- **Space:** `O(1)` additional space beyond the input arrays.
