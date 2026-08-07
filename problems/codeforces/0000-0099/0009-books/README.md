# 0009 - Books

## Problem Information

- **Source:** Codeforces 279B
- **Rating:** 1400

Given `n` books arranged in a row, each requiring a certain number of
minutes to read, and a total time budget `t`, find the maximum number of
books that can be read if they must be a contiguous block starting from
any position and read from left to right without skipping any of them.

## Related Topics

- [F035 - Two Pointers](../../../../topics/fundamentals/F035-two-pointers/README.md)

## Solution Idea

This is the same-direction pointer pattern used as a sliding window. A
`right` pointer extends the window by one book at a time, subtracting
that book's time from the remaining budget `t`. Whenever `t` becomes
negative, the window has grown too large, so a `left` pointer shrinks it
from the front, adding that book's time back to `t`, until the window is
valid again. The best window length seen while `t` stays non-negative is
the answer. Because every book's reading time only ever gets added or
subtracted once per pointer movement, the total remaining budget
directly reflects the current window's cost at every step.

## Common Mistake Highlighted

An early version of this solution advanced `right` and then
unconditionally read `a[right]` to update `t`, even when `right` had just
moved past the last valid index (`n - 1`). This reads one element past
the end of the array, which is undefined behavior. It happened to work
on Codeforces because the loop condition (`right < n`) stops the loop
immediately afterward, before the corrupted value of `t` is ever used —
but relying on that is fragile and can behave differently under a
stricter compiler or a sanitizer. The fix is to only update `t` when
`right < n` still holds after incrementing it.

## Complexity Analysis

- **Time:** `O(n)`. Both `left` and `right` move forward at most `n`
  times in total across the whole run.
- **Space:** `O(1)` additional space beyond the input array.
