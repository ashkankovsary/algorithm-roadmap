# 0003 - Good Array

## Problem Information

- **Source:** Codeforces 1077C
- **Rating:** ~1300

An array is called *good* if it contains an element equal to the sum of
all its other elements. Given an array of `n` integers, find every index
`j` such that removing the `j`-th element makes the remaining array good
(a *nice* index).

## Related Topics

- [F015 - Fast Input / Output](../../../../topics/fundamentals/F015-fast-input-output/README.md) — `n` can be up to 2×10^5, so unoptimized `cin`/`cout` alone can be enough to cause a TLE even with a correct O(N) solution.

## Solution Idea

Track only the two largest values in the array (`m1`, the maximum, and
`m2`, the second largest) along with their original indices, in a single
linear pass — no full sort is required.

- If the array is already good, the maximum element must equal the sum
  of all the others (`sum - m1 == m1`).
- If not, removing the maximum element changes the "target" the
  remaining elements must sum to. Whether the array can become good, and
  which elements are valid to remove, follows from comparing `m1` and
  `m2` against the total sum.
- Care is needed when `m1`'s value is duplicated in the array (removing
  one occurrence does not remove the maximum from the remaining array)
  and when checking the same index more than once, which would
  otherwise produce duplicate entries in the output.

## Common Mistake Highlighted

An early version of this solution declared `vector<pair<int,int>> a(n);`
before `n` had been read from input (`cin >> n;` was missing). Using an
uninitialized `n` this way produced a `vector` of an unpredictable size,
which led to a segmentation fault.

A second, more subtle bug came from storing `c = sum - m1.first` in an
`int`. With `n` up to 2×10^5 and each element up to 10^6, `sum` can
exceed the range of a 32-bit integer, so it must be stored in a
`long long` — otherwise the value silently overflows/truncates instead
of raising an error.

## Complexity Analysis

- **Time:** O(n), one pass to find `m1`/`m2` and the total sum, and one
  more pass to collect matching indices.
- **Space:** O(n), for storing the array with its original indices.
