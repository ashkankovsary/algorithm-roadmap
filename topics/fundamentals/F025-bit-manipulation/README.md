# F025 - Bit Manipulation

## Overview

Bit manipulation is the technique of working directly with the binary
representation of a number instead of treating it purely as an
arithmetic value. Because computers store every value in binary, and
CPUs execute bitwise instructions (AND, OR, XOR, shifts) natively in a
single cycle, these operations are extremely fast and form the basis
for compact state representation, fast flag checking, and subset
enumeration.

## When to Use

- Checking, setting, clearing, or toggling individual flags without
  using an array of booleans.
- Representing a subset of a small collection (typically `n ≤ 20-25`)
  as a single integer, so all `2^n` subsets can be enumerated.
- Performing fast numeric checks such as parity, powers of two, or
  isolating the lowest set bit.
- Compressing state in dynamic programming (see Bitmask DP).

## When NOT to Use

- When the number of elements to represent as flags is large (a
  `std::vector<bool>` or `std::bitset` may be clearer, and a plain
  integer mask no longer fits in a machine word).
- When readability matters more than the small constant-factor speedup,
  and a boolean array already expresses the intent clearly.

## Pattern Recognition

- The problem statement mentions "subsets", "AND", "OR", "XOR", or
  binary representations directly.
- Constraints show a small `n` (roughly ≤ 20-25), hinting at enumerating
  all `2^n` subsets.
- The problem involves toggling or querying independent binary states.

---

## Intuition

An integer can be seen as a fixed-size row of switches (bits), where
bit `i` contributes `2^i` to the value if it is on. Because each bit is
independent of the others, a bitwise operation acts on all of them at
once, which is what makes these operations fast and useful for encoding
independent binary decisions.

Most single-bit operations rely on building a **mask**: an integer that
has a `1` only at the position of interest and `0` everywhere else.
Combining the original number with this mask via AND, OR, or XOR reads
or modifies exactly that bit without touching the rest.

XOR has an additional useful property: `x ^ x = 0` and `x ^ 0 = x`.
Applying XOR with the same value twice cancels out, which is the basis
for tricks such as finding the single number that appears an odd number
of times in an array.

## Prerequisites

- **F010 - C++ STL Essentials**: needed to work comfortably with the
  basic integer types (`int`, `long long`, `unsigned`) and simple loops
  used in every implementation in this topic.

---

## Complexity Analysis

| Operation | Complexity | Notes |
|---|---|---|
| Check / set / clear / toggle a single bit | O(1) | A single bitwise instruction |
| Count set bits (manual loop) | O(number of bits) | One pass over every bit |
| Count set bits (`__builtin_popcount`) | O(1) effectively | Maps to a dedicated CPU instruction |
| Enumerate all subsets of an n-element set | O(2^n) | There are `2^n` possible subsets |

- **Space:** representing `n` boolean flags as bits in an integer uses
  `O(n / 32)` or `O(n / 64)` machine words instead of `O(n)` bytes.

---

## Implementation Walkthrough

See `implementation.cpp` for the reference implementation. It provides
independent helper functions: `checkBit`, `setBit`, `clearBit`,
`toggleBit`, `countSetBits`, `isPowerOfTwo`, and `lowestSetBit`.

A few design decisions worth calling out:

- `clearBit` uses `~(1 << i)` rather than manually flipping bits, so the
  rest of the number is guaranteed to be left untouched by the AND
  operation.
- `isPowerOfTwo` relies on the identity that subtracting `1` from a
  number flips its lowest set bit to `0` and every bit after it to `1`;
  ANDing the original value with this result is `0` only when exactly
  one bit was set.
- `lowestSetBit` uses `x & (-x)`, which relies on the two's complement
  representation of negative numbers to isolate the rightmost `1` bit.

---

## Common Mistakes

**Implementation mistakes:**

- Using `&&` / `||` (logical operators) instead of `&` / `|` (bitwise
  operators). Both compile without error, since C++ treats any nonzero
  value as `true`, so the bug can easily go unnoticed.
- Omitting parentheses around shifts, e.g. writing `x & 1 << i` instead
  of `x & (1 << i)`. Operator precedence may not do what is expected.
- Using `int` when the required bit count or value exceeds 31 bits,
  e.g. `1 << 35` on an `int` is undefined behavior; use `1LL << 35`.
- Forgetting that `~x` flips the sign bit too on signed types, which can
  produce an unexpectedly negative result.

**Logical mistakes:**

- Assuming a left shift is always equivalent to multiplication without
  considering overflow.
- Forgetting that bit indices start at `0` (the least significant bit),
  not `1`.
- Using `x & (x - 1) == 0` to test "power of two" without separately
  excluding `x == 0`, since it also evaluates to `0` for `x == 0`.

**Edge case(s):**

- `x == 0`: most operations behave correctly, but functions like
  `isPowerOfTwo` or `lowestSetBit` must handle it explicitly.
- Negative numbers: because of two's complement, operations like `~`
  and `>>` can behave unexpectedly (right shift on a signed negative
  value is typically an arithmetic shift that preserves the sign bit).
- The maximum representable value of a type: shifting it left easily
  overflows.

---

## Practice Problems

- [0005 - Petr and a Combination Lock](../../../problems/codeforces/0000-0099/0005-petr-and-a-combination-lock/README.md) — uses a bitmask to enumerate every combination of sign choices.

---

## Related Algorithms

No stored topics reference this one yet. Bit Manipulation is a direct
prerequisite of **DP045 - Bitmask DP**, which will link back here once
that topic is covered.

## Learning Path

Next topic in the roadmap: **F030 - Binary Search on Answer**.
