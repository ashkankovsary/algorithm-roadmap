# F010 - C++ STL Essentials

## Overview

The C++ Standard Template Library (STL) is a collection of ready-to-use,
generic data structures and algorithms. Instead of implementing dynamic
arrays, sorting routines, or key-value structures from scratch, competitive
programmers rely on the STL to write correct and efficient code quickly.

This topic covers the STL components used most frequently across the
roadmap: `vector`, `pair`, `tuple`, and `sort`.

Other STL containers (`map`, `set`, `unordered_map`, `unordered_set`,
`priority_queue`) are intentionally **not** covered here. They are
introduced later, in their own dedicated topics (see **Related Algorithms**
below), once their underlying data structures have been properly explained.

---

## When to Use

Use these STL components whenever a problem needs:

- A resizable collection of elements (`vector`).
- Two or three related values grouped together, such as a graph edge or a
  coordinate (`pair`, `tuple`).
- The elements of a collection arranged in a specific order, optionally by
  a custom rule (`sort`).

This covers the vast majority of competitive programming problems — these
four components appear in almost every solution, regardless of topic.

## When NOT to Use

- If a collection needs fast **lookup by key** (not just storage), a plain
  `vector` is the wrong tool — that need is covered later by hash-based or
  ordered containers (`map`, `unordered_map`).
- If a collection needs to repeatedly retrieve the minimum/maximum element
  efficiently while it keeps changing, `sort`-ing repeatedly is wasteful —
  that need is covered later by `priority_queue`.

## Pattern Recognition

- "Group two/three related values together" → `pair` / `tuple`.
- "Order elements to make a later step easier or reveal a property" →
  `sort`, often followed by a linear scan.
- "Keep track of an element's original position after reordering it" →
  `pair<value, index>` (or `tuple`), sorted by the value.

---

## Intuition

### `std::vector` — Dynamic Array

A `vector` behaves like a regular array, except it can grow automatically
when more space is needed. Internally, it stores its elements in a single
contiguous block of memory, which makes element access fast and
cache-friendly.

When a `vector` runs out of capacity, it does not grow by one slot at a
time. Instead, it typically **doubles** its underlying capacity. This is
why appending `n` elements one at a time still costs O(n) in total, rather
than O(n²) — a property known as **amortized O(1)** insertion.

```cpp
vector<int> v;          // empty vector
vector<int> v2(5);      // 5 elements, default-initialized to 0
vector<int> v3(5, -1);  // 5 elements, all initialized to -1

v.push_back(x);       // append to the end — amortized O(1)
v.pop_back();          // remove the last element — O(1)
v.size();              // number of elements
v[i];                  // direct access — O(1), no bounds checking
v.front(); v.back();   // first / last element
```

**Important pitfall:** accessing `v[i]` with an out-of-range index is
undefined behavior — it will not throw a runtime error. Index bounds must
always be checked manually when there is any doubt.

### `std::pair` — Grouping Two Values

A `pair` groups two values together without needing to define a custom
structure. It is commonly used to represent things like coordinates or
unweighted graph edges:

```cpp
pair<int, int> p = {3, 5};
p.first;   // 3
p.second;  // 5
```

`pair` is comparable by default — first by `.first`, then by `.second`.
This means a `vector<pair<int,int>>` can be sorted directly without
writing a custom comparator.

### `std::tuple` — Grouping More Than Two Values

When more than two related values need to be stored together (for example,
a weighted graph edge `(u, v, weight)`), `tuple` extends the idea of `pair`
to any number of elements. Since it has no fixed number of members, it has
no `.first` / `.second` — instead, `get<i>(t)` accesses the i-th member
(0-indexed):

```cpp
tuple<int, int, int> edge = {u, v, weight};
get<0>(edge); // u
get<2>(edge); // weight — the third member

auto [u, v, w] = edge; // structured bindings unpack the tuple
```

### `std::sort` — Generic Sorting

`sort` works on any range defined by a pair of iterators (most commonly
`v.begin()` and `v.end()` for a `vector`). By default it sorts in ascending
order, but a custom comparator can change that behavior:

```cpp
sort(v.begin(), v.end());                    // ascending
sort(v.begin(), v.end(), greater<int>());     // descending
sort(v.begin(), v.end(), [](int a, int b) {   // custom comparator
    return a > b;
});
```

Iterators (`.begin()` / `.end()`) and lambda expressions are covered in
detail in a later topic — for now, it is enough to know that a lambda is
an unnamed function defined inline, and that `.begin()`/`.end()` mark the
start and end of the range being sorted.

---

## Prerequisites

- F005 — Algorithm Analysis

---

## Complexity Analysis

| Operation | Time Complexity | Notes |
|---|---|---|
| `v[i]` | O(1) | Direct memory access |
| `push_back` | Amortized O(1) | Occasional O(n) reallocation, doubled capacity |
| `pop_back` | O(1) | |
| `insert`/`erase` (middle) | O(n) | Later elements must shift |
| `pair`/`tuple` access & comparison | O(1) | Fixed number of members |
| `sort` | O(n log n) | Worst case; not guaranteed stable |

`sort` does not guarantee that equal elements keep their relative order.
When that matters, `stable_sort` should be used instead (also O(n log n),
but with that guarantee).

---

## Implementation Walkthrough

See [`implementation.cpp`](./implementation.cpp) for a complete, runnable
example that builds a `vector`, sorts it both ascending and descending,
sorts a `vector<pair<int,int>>` of unweighted edges using the default
comparator, and sorts a `vector<tuple<int,int,int>>` of weighted edges by
weight using a custom comparator with structured bindings.

Two design choices are worth calling out:

- The custom comparators take their parameters as `const auto&` rather
  than by value. Passing by reference avoids copying each `pair`/`tuple`
  on every comparison — a small saving here, but a habit that matters
  once elements get larger or `sort` is called on millions of elements.
- Sorting the weighted edges needs an explicit comparator (`get<2>(a) <
  get<2>(b)`) because the default `tuple` ordering compares `u` first,
  not `weight` — the field actually being optimized for.

---

## Common Mistakes

**Implementation mistakes:**

- Accessing `v[i]` out of bounds — no exception is thrown; the behavior is
  undefined. Always check `i < v.size()` when in doubt.
- Passing `pair`/`tuple` comparator parameters by value instead of
  `const auto&`, causing unnecessary copies on every comparison.
- Using `get<i>` with an out-of-range index — `tuple` indices are
  0-based, so a 3-element tuple only has valid indices `0`, `1`, `2`.
- Calling `sort(v)` instead of `sort(v.begin(), v.end())` — `sort` is a
  free function that operates on a range, not a container method.

**Logical mistakes:**

- Writing the comparator backwards (e.g. `a < b` when a descending order
  was intended).
- Relying on `tuple`'s default lexicographic order when the intent was to
  sort by one specific member — this compiles and runs, but silently
  produces the wrong order.

**Edge cases:**

- `sort` on an empty `vector` is safe; `v.front()`/`v.back()` on an empty
  `vector` is undefined behavior.
- When multiple elements are equal, their relative order after `sort` is
  not guaranteed — use `stable_sort` if that order must be preserved.

---

## Practice Problems

- [0001 - Circle of Apple Trees](../../../problems/codeforces/0000-0099/0001-circle-of-apple-trees/README.md) — uses `sort` as an analysis tool (to count distinct values), not just for ordering output.
- [0002 - Sort the Array](../../../problems/codeforces/0000-0099/0002-sort-the-array/README.md) — compares a sorted copy of the array against the original to locate a mismatched segment; also highlights a common midpoint-calculation mistake.

---

## Related Algorithms

The following STL containers build on ideas introduced here and are
covered as dedicated topics later in the roadmap:

- **DS047 — Priority Queue / Heap**
- **DS050 — Hash Tables (Map, Set, Frequency Counting)**

## Learning Path

F010 is a prerequisite for most subsequent topics in the roadmap, since
`vector`, `pair`, `tuple`, and `sort` are used throughout Data Structures,
Graph, and Dynamic Programming topics.
