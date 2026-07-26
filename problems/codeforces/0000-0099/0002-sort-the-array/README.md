# 0002 - Sort the Array

## Problem Information

- **Source:** Codeforces 451B
- **Rating:** ~1500

Given an array of `n` distinct integers, determine whether it is possible
to sort it in increasing order by reversing exactly one contiguous
segment. If possible, output the (1-indexed) start and end of that
segment.

## Related Topics

- [F010 - C++ STL Essentials](../../../../topics/fundamentals/F010-cpp-stl-essentials/README.md)

## Solution Idea

Make a sorted copy of the array using `sort`, then compare it against the
original element by element. The positions where they differ mark the
boundaries of a single mismatched segment (`left`, `right`) — if the array
can be fixed by reversing one segment at all, it must be this exact
segment, since every element outside it is already in its correct sorted
position.

Reverse that segment and check whether the result now matches the sorted
copy. If it does, the answer is "yes" with that segment; otherwise "no".

## Common Mistake Highlighted

An early version of this solution computed the segment's midpoint as
`(right - left) / 2` instead of `(right + left) / 2`. The first formula
gives the segment's **length** divided by two, not its **midpoint index**
— using it to locate the mirrored index during the reversal picks the
wrong element to swap with. The correct midpoint of a range `[left, right]`
is the **average of its two endpoints**, `(left + right) / 2`.

## Complexity Analysis

- **Time:** O(n log n), dominated by the sort.
- **Space:** O(n) for the sorted copy.
