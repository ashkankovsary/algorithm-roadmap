# F005 — Algorithm Analysis (Big-O, Time & Space Complexity)

**Difficulty:** Beginner
**Importance:** ⭐⭐⭐⭐⭐
**Prerequisites:** None (first topic in the roadmap)

---

## Overview

Algorithm Analysis lets us describe how "good" an algorithm is without running it — by estimating how its resource usage (time or memory) grows as the input size (n) grows. It's a hardware- and language-independent way to compare solutions and to know, before writing any code, whether an approach is even feasible.

## Intuition

Compare two ways to check for a duplicate in an array:
- **Nested loop** (compare every pair): work grows roughly with n² — doubling n roughly quadruples the work. This is **O(n²)**.
- **Hash set** (one pass, track seen values): work grows roughly with n — doubling n roughly doubles the work. This is **O(n)**.

For small n the constants involved might make either one look faster, but as n grows large, the one with the better growth rate always wins. This is why Big-O keeps only the **largest term** and drops constants: `3n² + 5n + 100` is written as `O(n²)`, because at large n every other term becomes negligible by comparison.

## Prerequisites

None — only basic programming (loops, arrays, functions).

## When to Use

Always: it's the lens for evaluating every other topic in this roadmap. Before coding, translate a problem's constraints into an expected complexity.

**Constraints cheat sheet** (assuming ~10⁸ operations/sec, 1-2s time limit):

| n | Acceptable complexity |
|---|---|
| ≤ 10 | O(n!), O(2ⁿ·n) |
| ≤ 20 | O(2ⁿ) |
| ≤ 500 | O(n³) |
| ≤ 5,000 | O(n²) |
| ≤ 10⁶ | O(n log n), O(n) |
| ≤ 10⁸ | O(n) (simple ops), O(log n) |

## When NOT to Use

N/A — this isn't an optional technique. The only caution: don't over-rely on asymptotic behavior for very small, fixed input sizes, where constant factors can dominate (see Common Mistakes).

## Pattern Recognition

- Translate stated constraints (n) into expected complexity using the cheat sheet.
- If brute force is far above what constraints allow, look for a different approach rather than micro-optimizing.
- Prefer better asymptotic growth over "looks faster on small tests" whenever n can be large.

## Complexity Analysis

- **Big-O** = upper bound / worst case ("how bad it can get"). **Big-Omega (Ω)** = lower bound ("can't be faster than this"). **Big-Theta (Θ)** = tight bound (both O and Ω). In competitive programming we almost always use Big-O.
- **Rules:** drop constants (`O(5n) = O(n)`); keep only the largest term (`O(n² + n) = O(n²)`); sequential steps add (`O(n) + O(n²) = O(n²)`); nested loops multiply (`O(n) × O(n) = O(n²)`).
- **Growth ranking:** `O(1) < O(log n) < O(√n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)`
- **Time vs. Space:** time = basic operation count; space = *extra* memory used (not the input itself). A fixed number of variables is O(1) space ("in-place"); an auxiliary array of size n is O(n) space. Trading memory for time (or vice versa) is a **Time-Space Tradeoff**, seen later in Hashing, Sparse Tables, and DP.

## Implementation Walkthrough

See `implementation.cpp` for four benchmarked functions (`constantTime`, `linearTime`, `linearithmicTime`, `quadraticTime`) that measure and print their own runtime across increasing input sizes using `clock()`.

Key implementation choices:
- `vector<int>&` is used everywhere except `linearithmicTime`, which takes the vector **by value** on purpose — `sort` mutates it, and we don't want the caller's original array reordered as a side effect. Passing by reference elsewhere avoids an O(n) copy that would otherwise pollute the timing measurements.
- `long long` is used for accumulated sums/counts to avoid `int` overflow on large inputs.

**Sanity check on `arr = [4, 2, 4, 5, 2, 4]` (n = 6):** `constantTime` → `4` (1 step, independent of n). `linearTime` → `21` (6 additions). `linearithmicTime` → `5` (sorts a copy to `[2,2,4,4,4,5]`, ~15-16 comparisons — n log n work). `quadraticTime` → `4` matching pairs, checking all `n(n-1)/2 = 15` pairs — doubling n to 12 would check 66 pairs (~4×, confirming O(n²)).

## Common Mistakes

- Forgetting `&` when passing a `vector` — silently turns every call into an O(n) copy and skews timing results.
- Trusting `clock()` at face value for tiny workloads — its resolution (~10ms on many systems) can report `0` even when real work happened; average over many repeated calls for reliable numbers.
- Using `int` instead of `long long` for sums/counts that can exceed ~2.1 billion.
- Judging complexity from a single runtime measurement instead of testing across multiple input sizes — constant factors can make a worse-complexity algorithm look faster at small n.
- Confusing Best/Average/Worst case: `quadraticTime` is always O(n²) regardless of data, but some algorithms' actual work depends on input shape.
- Edge cases to handle explicitly: empty array (`arr.empty()` checks before indexing) and single-element array (inner loop never runs in `quadraticTime`, which is correct).

## Practice Problems

None recommended yet — this topic is foundational rather than technique-specific. Problems that meaningfully reinforce complexity trade-offs will appear starting with topics like Arrays and Two Pointers.

## Related Algorithms

Every later topic relies on the complexity vocabulary introduced here — notably F010 (STL operation costs), DP (time-space tradeoffs), and advanced data structures (chosen specifically to improve on a naive complexity established here).

## Learning Path

**Previous:** None (roadmap start). **Next:** F010 — C++ STL Essentials.
