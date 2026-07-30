# 0007 - Hard Process

## Problem Information

- **Source:** Codeforces 660C
- **Rating:** 1600

Given a binary array and a budget of at most `k` zeroes that may be
changed to ones, find the maximum possible length of a contiguous
subsegment consisting only of ones, and print one array that achieves it.

## Related Topics

- [F030 - Binary Search on Answer](../../../../topics/fundamentals/F030-binary-search-on-answer/README.md)

## Solution Idea

This is a direct application of the **largest-true** pattern. For a
candidate length `x`, `check(x)` slides a window of that length across
the array and asks whether some window of length `x` contains at most
`k` zeroes. As `x` grows, this only gets harder to satisfy, so `check` is
monotonic: `true` for small `x`, `false` from some point onward.

Inside `check`, a running count of zeroes in the current window is
maintained with a sliding window, and the starting index of the first
window found to be feasible is recorded (in a shared variable) so that
the final array can be printed once the optimal length is known.

## Common Mistake Highlighted

The first version of this solution started the search at `lo = 1`
instead of `lo = 0`. The largest-true pattern requires `check(lo)` to
always be true at the start of the search; `check(0)` is trivially true
(an empty window has zero zeroes, which is always within budget), but
`check(1)` is not guaranteed to be true — for example, an array of all
zeroes with `k = 0` has no valid window of length 1. Starting at
`lo = 1` produced a wrong answer on exactly this kind of input, since the
search silently assumed a length-1 window was always achievable.

## Complexity Analysis

- **Time:** `O(n log n)` — `O(log n)` binary search steps, each costing
  `O(n)` for the sliding-window check.
- **Space:** `O(n)` for the output array (no extra space is needed for
  the search itself beyond `O(1)`).
