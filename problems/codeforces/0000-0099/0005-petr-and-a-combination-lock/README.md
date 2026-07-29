# 0005 - Petr and a Combination Lock

## Problem Information

- **Source:** Codeforces 1097B
- **Rating:** 1200
- A lock's pointer starts at 0 on a 360-degree scale. It must be rotated
  exactly `n` times, and for each rotation a fixed angle is given but
  its direction (clockwise or counter-clockwise) can be chosen freely.
  The task is to decide whether some combination of directions brings
  the pointer back to exactly 0 (modulo 360).

## Related Topics

- [F025 - Bit Manipulation](../../../../topics/fundamentals/F025-bit-manipulation/README.md)

## Solution Idea

Since `n` is small, every combination of directions can be represented
as an `n`-bit mask: bit `i` set means the `i`-th rotation is added,
bit `i` clear means it is subtracted. Enumerating all `2^n` masks and
checking whether the resulting signed sum is divisible by 360 covers
every possible outcome, so if none of them works the answer is "NO".

## Complexity Analysis

- **Time:** O(2^n · n) — every one of the `2^n` masks requires an O(n) pass to compute the signed sum.
- **Space:** O(n) — for storing the input angles.
