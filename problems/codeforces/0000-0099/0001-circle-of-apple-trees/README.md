# 0001 - Circle of Apple Trees

## Problem Information

- **Source:** Codeforces 2153A
- **Rating:** 800

There are `n` apple trees arranged in a circle, each with an apple of a
given beauty value. Starting at tree 1 and moving around the circle
indefinitely, an apple may only be eaten if its beauty is strictly greater
than the beauty of the last apple eaten. Find the maximum number of apples
that can be eaten.

## Related Topics

- [F010 - C++ STL Essentials](../../../../topics/fundamentals/F010-cpp-stl-essentials/README.md)

## Solution Idea

Sorting the beauty values reveals the key insight: exactly one apple of
each **distinct** beauty value can always be eaten, one per lap around the
circle, in increasing order. Beauty values that repeat cannot contribute
more than once, since a repeated value is never strictly greater than an
already-eaten apple of the same value.

The answer is therefore simply the number of distinct beauty values in the
array. Sorting the array first makes counting distinct values a single
linear pass, since equal values become adjacent.

## Complexity Analysis

- **Time:** O(n log n), dominated by the sort.
- **Space:** O(n) for the array.
