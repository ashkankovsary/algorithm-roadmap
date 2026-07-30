# 0006 - Ternary String

## Problem Information

- **Source:** Codeforces 1354B2
- **Rating:** 1200

Given a string made only of the characters `1`, `2`, and `3`, find the
smallest length of a contiguous substring that contains all three
characters at least once.

## Related Topics

- [F030 - Binary Search on Answer](../../../../topics/fundamentals/F030-binary-search-on-answer/README.md)

## Solution Idea

This is a direct application of the **smallest-true** pattern. For a
candidate window length `k`, `check(k)` slides a window of that length
across the string and asks whether any window of that length contains
all three characters. As `k` grows, it only gets easier to satisfy this
condition, so `check` is monotonic: `false` for small `k`, `true` from
some point onward.

The search starts at `lo = 3` (the smallest length that could possibly
contain three distinct characters) and `hi = n` (the whole string, which
trivially contains every character present in it, if all three are
present at all). Inside `check`, a running count of each character is
maintained with a sliding window, so each call to `check` runs in `O(n)`
regardless of `k`.

## Complexity Analysis

- **Time:** `O(n log n)` — `O(log n)` binary search steps, each costing
  `O(n)` for the sliding-window check.
- **Space:** `O(1)` additional space beyond the input string.
