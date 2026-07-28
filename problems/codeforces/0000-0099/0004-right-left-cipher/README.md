# 0004 - Right-Left Cipher

## Problem Information

- **Source:** Codeforces 1085A
- **Rating:** 1300

Given an encoded string produced by an unknown original string through
an alternating left/right insertion process, the task is to reconstruct
the original string.

## Related Topics

- [F020 - Recursion](../../../topics/fundamentals/F020-recursion/README.md)

## Solution Idea

The encoding process alternates between appending characters to the left
and to the right of a growing string, starting with a right insertion.
This means the *last* character added to the encoded string is always
known: if the encoded string has odd length, the last character added
was placed on the left end; if it has even length, it was placed on the
right end.

This observation gives a natural recursive definition: peel off the
character that was added last (front or back, depending on parity),
recurse on the remaining substring to decode it, and append the peeled
character to the result. The base case is a string of length 1, which
decodes to itself.

## Complexity Analysis

- **Time:** O(n²) — each recursive call creates a new substring of
  length one less than before, and substring creation itself costs
  O(n), giving a total of O(n) calls × O(n) work each.
- **Space:** O(n) for the recursion depth (one call per character),
  plus O(n) for the strings built along the way.
