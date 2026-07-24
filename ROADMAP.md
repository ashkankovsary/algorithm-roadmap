# Algorithm Roadmap

This roadmap is organized by **prerequisites**, not by difficulty.

The goal is to build a strong foundation in Algorithms, Data Structures, and Competitive Programming. Every topic should be learned only after its prerequisites.

---

## Difficulty Levels

| Level | Meaning |
| ------ | ------- |
| Beginner | No prior knowledge required |
| Easy | Basic programming knowledge |
| Medium | Requires understanding of previous topics |
| Hard | Advanced problem-solving skills |
| Expert | Mostly used in high-level competitive programming |

---

## Importance

| Rating | Meaning |
| ------- | ------- |
| ⭐⭐⭐⭐⭐ | Essential |
| ⭐⭐⭐⭐ | Very Important |
| ⭐⭐⭐ | Useful |
| ⭐⭐ | Occasionally Used |
| ⭐ | Specialized |

---

# Fundamentals (8 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| F005 | Algorithm Analysis (Big-O, Time & Space Complexity, Asymptotic Analysis) | Beginner | ⭐⭐⭐⭐⭐ | — |
| F010 | C++ STL Essentials | Beginner | ⭐⭐⭐⭐⭐ | F005 |
| F015 | Fast Input / Output | Beginner | ⭐⭐⭐⭐ | F010 |
| F020 | Recursion | Easy | ⭐⭐⭐⭐⭐ | F010 |
| F025 | Bit Manipulation | Easy | ⭐⭐⭐⭐⭐ | F010 |
| F030 | Binary Search on Answer | Easy | ⭐⭐⭐⭐⭐ | F010 |
| F035 | Two Pointers | Easy | ⭐⭐⭐⭐⭐ | F010 |
| F040 | Sliding Window | Easy | ⭐⭐⭐⭐⭐ | F035 |

---

# Data Structures (19 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| DS005 | Arrays | Beginner | ⭐⭐⭐⭐⭐ | F010 |
| DS010 | Prefix Sum | Easy | ⭐⭐⭐⭐⭐ | DS005 |
| DS015 | Prefix XOR | Easy | ⭐⭐⭐⭐ | DS010 |
| DS020 | Difference Array | Easy | ⭐⭐⭐⭐ | DS010 |
| DS025 | Stack | Easy | ⭐⭐⭐⭐⭐ | DS005 |
| DS030 | Monotonic Stack | Medium | ⭐⭐⭐⭐ | DS025 |
| DS035 | Queue | Easy | ⭐⭐⭐⭐⭐ | DS005 |
| DS040 | Monotonic Queue | Medium | ⭐⭐⭐⭐ | DS035 |
| DS045 | Deque | Easy | ⭐⭐⭐⭐ | DS035 |
| DS047 | Priority Queue / Heap | Easy | ⭐⭐⭐⭐⭐ | DS035 |
| DS050 | Hash Tables (Map, Set, Frequency Counting) | Easy | ⭐⭐⭐⭐⭐ | DS005 |
| DS055 | Coordinate Compression | Medium | ⭐⭐⭐⭐ | DS050 |
| DS060 | Sparse Table | Medium | ⭐⭐⭐⭐ | DS010 |
| DS065 | Fenwick Tree (Binary Indexed Tree) | Medium | ⭐⭐⭐⭐⭐ | DS010 |
| DS070 | Segment Tree | Medium | ⭐⭐⭐⭐⭐ | DS010 |
| DS075 | Lazy Propagation | Hard | ⭐⭐⭐⭐ | DS070 |
| DS080 | Disjoint Set Union (Union-Find) | Medium | ⭐⭐⭐⭐⭐ | DS005 |
| DS085 | Trie | Medium | ⭐⭐⭐⭐ | DS050 |
| DS090 | Policy-Based Data Structures (PBDS) | Hard | ⭐⭐⭐ | DS050 |

---

# Searching & Sorting (7 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| SA005 | Binary Search | Easy | ⭐⭐⭐⭐⭐ | F030 |
| SA010 | Merge Sort | Easy | ⭐⭐⭐⭐ | F020 |
| SA015 | Quick Sort | Easy | ⭐⭐⭐ | SA010 |
| SA020 | Counting Sort | Easy | ⭐⭐⭐ | SA010 |
| SA025 | Radix Sort | Medium | ⭐⭐ | SA020 |
| SA030 | Custom Sorting & Comparators | Easy | ⭐⭐⭐⭐ | SA010 |
| SA035 | Meet in the Middle | Hard | ⭐⭐⭐⭐ | SA005 |

---

# Greedy (6 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| GR005 | Greedy Basics | Easy | ⭐⭐⭐⭐⭐ | SA030 |
| GR010 | Greedy with Sorting | Easy | ⭐⭐⭐⭐⭐ | GR005 |
| GR015 | Greedy with Priority Queue | Medium | ⭐⭐⭐⭐⭐ | DS047 |
| GR020 | Interval Scheduling | Medium | ⭐⭐⭐⭐ | GR010 |
| GR025 | Greedy on Intervals | Medium | ⭐⭐⭐⭐ | GR020 |
| GR030 | Sweep Line | Hard | ⭐⭐⭐ | GR025 |

---

# Graph (25 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| G005 | Graph Representation | Easy | ⭐⭐⭐⭐⭐ | DS005 |
| G010 | Depth-First Search (DFS) | Easy | ⭐⭐⭐⭐⭐ | G005 |
| G015 | Breadth-First Search (BFS) | Easy | ⭐⭐⭐⭐⭐ | G005 |
| G020 | Connected Components | Easy | ⭐⭐⭐⭐⭐ | G010 |
| G025 | Flood Fill | Easy | ⭐⭐⭐⭐ | G010 |
| G030 | Bipartite Graph | Medium | ⭐⭐⭐⭐ | G015 |
| G035 | Cycle Detection | Medium | ⭐⭐⭐⭐⭐ | G010 |
| G040 | Topological Sort | Medium | ⭐⭐⭐⭐⭐ | G010 |
| G045 | Directed Acyclic Graph (DAG) | Medium | ⭐⭐⭐⭐ | G040 |
| G050 | Shortest Path (Unweighted Graph) | Easy | ⭐⭐⭐⭐ | G015 |
| G055 | 0-1 BFS | Medium | ⭐⭐⭐⭐ | G050 |
| G060 | Dijkstra's Algorithm | Medium | ⭐⭐⭐⭐⭐ | G050, DS047 |
| G065 | Bellman-Ford Algorithm | Medium | ⭐⭐⭐⭐ | G060 |
| G070 | Floyd-Warshall Algorithm | Medium | ⭐⭐⭐ | G065 |
| G075 | Minimum Spanning Tree | Medium | ⭐⭐⭐⭐⭐ | DS080 |
| G080 | Kruskal's Algorithm | Medium | ⭐⭐⭐⭐⭐ | G075 |
| G085 | Prim's Algorithm | Medium | ⭐⭐⭐⭐ | G075, DS047 |
| G090 | Kosaraju's Algorithm | Hard | ⭐⭐⭐⭐ | G040 |
| G095 | Tarjan's Algorithm | Hard | ⭐⭐⭐⭐ | G040 |
| G100 | Bridges & Articulation Points | Hard | ⭐⭐⭐⭐ | G095 |
| G105 | Euler Tour Technique | Hard | ⭐⭐⭐⭐ | G010 |
| G110 | Lowest Common Ancestor (Binary Lifting) | Hard | ⭐⭐⭐⭐⭐ | G105 |
| G115 | Functional Graphs | Medium | ⭐⭐⭐ | G010 |
| G120 | Maximum Bipartite Matching | Hard | ⭐⭐⭐⭐ | G030 |
| G125 | Network Flow | Expert | ⭐⭐⭐ | G120 |

---

# Trees (6 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| T005 | Tree Basics | Easy | ⭐⭐⭐⭐⭐ | G010 |
| T010 | Tree Traversal | Easy | ⭐⭐⭐⭐⭐ | T005 |
| T015 | Tree Diameter | Easy | ⭐⭐⭐⭐ | T010 |
| T020 | Heavy-Light Decomposition | Expert | ⭐⭐⭐⭐ | G110, DS070 |
| T025 | DSU on Tree (Small-to-Large) | Expert | ⭐⭐⭐⭐ | T010, DS080 |
| T030 | Centroid Decomposition | Expert | ⭐⭐⭐ | T010 |

---

# Dynamic Programming (14 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| DP005 | Dynamic Programming Fundamentals | Medium | ⭐⭐⭐⭐⭐ | F020 |
| DP010 | Memoization vs Tabulation | Medium | ⭐⭐⭐⭐⭐ | DP005 |
| DP015 | 0/1 Knapsack | Medium | ⭐⭐⭐⭐⭐ | DP010 |
| DP020 | Unbounded Knapsack | Medium | ⭐⭐⭐⭐ | DP015 |
| DP025 | Longest Increasing Subsequence (LIS) | Medium | ⭐⭐⭐⭐⭐ | DP010 |
| DP030 | Longest Common Subsequence (LCS) | Medium | ⭐⭐⭐⭐⭐ | DP010 |
| DP035 | Edit Distance | Medium | ⭐⭐⭐⭐ | DP030 |
| DP040 | Tree DP | Hard | ⭐⭐⭐⭐⭐ | DP010, T010 |
| DP045 | Bitmask DP | Hard | ⭐⭐⭐⭐⭐ | DP015, F025 |
| DP050 | Digit DP | Hard | ⭐⭐⭐⭐ | DP010 |
| DP055 | Interval DP | Hard | ⭐⭐⭐⭐ | DP010 |
| DP060 | Graph DP | Hard | ⭐⭐⭐⭐ | DP010, G045 |
| DP065 | Divide & Conquer DP | Expert | ⭐⭐⭐ | DP055 |
| DP070 | Convex Hull Trick Optimization | Expert | ⭐⭐⭐ | DP055 |

---

# Strings (10 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| S005 | String Basics | Beginner | ⭐⭐⭐⭐⭐ | F010 |
| S010 | Prefix Function (KMP) | Medium | ⭐⭐⭐⭐⭐ | S005 |
| S015 | Z Algorithm | Medium | ⭐⭐⭐⭐ | S005 |
| S020 | Rabin-Karp | Medium | ⭐⭐⭐ | S005 |
| S025 | Polynomial Rolling Hash | Medium | ⭐⭐⭐⭐⭐ | S020 |
| S030 | Trie Applications | Medium | ⭐⭐⭐⭐ | DS085 |
| S035 | Aho-Corasick | Hard | ⭐⭐⭐⭐ | S030 |
| S040 | Manacher's Algorithm | Hard | ⭐⭐⭐ | S005 |
| S045 | Suffix Array | Expert | ⭐⭐⭐⭐ | S025 |
| S050 | Suffix Automaton | Expert | ⭐⭐⭐ | S045 |

---

# Mathematics (17 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| M005 | Number Theory Fundamentals | Easy | ⭐⭐⭐⭐⭐ | F005 |
| M010 | GCD & LCM | Easy | ⭐⭐⭐⭐⭐ | M005 |
| M015 | Euclidean Algorithm | Easy | ⭐⭐⭐⭐⭐ | M010 |
| M020 | Extended Euclidean Algorithm | Medium | ⭐⭐⭐⭐ | M015 |
| M025 | Fast Exponentiation | Easy | ⭐⭐⭐⭐⭐ | M005 |
| M030 | Modular Arithmetic | Medium | ⭐⭐⭐⭐⭐ | M025 |
| M035 | Modular Inverse | Medium | ⭐⭐⭐⭐ | M030 |
| M040 | Prime Numbers | Easy | ⭐⭐⭐⭐⭐ | M005 |
| M045 | Sieve of Eratosthenes | Easy | ⭐⭐⭐⭐⭐ | M040 |
| M050 | Linear Sieve | Medium | ⭐⭐⭐ | M045 |
| M055 | Prime Factorization | Medium | ⭐⭐⭐⭐ | M045 |
| M060 | Combinatorics | Medium | ⭐⭐⭐⭐⭐ | M030 |
| M065 | Binomial Coefficients | Medium | ⭐⭐⭐⭐ | M060 |
| M070 | Inclusion-Exclusion Principle | Hard | ⭐⭐⭐⭐ | M060 |
| M075 | Euler's Totient Function | Hard | ⭐⭐⭐ | M055 |
| M080 | Matrix Exponentiation | Hard | ⭐⭐⭐⭐ | M025 |
| M085 | Chinese Remainder Theorem | Expert | ⭐⭐ | M035 |

---

# Geometry (6 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| GE005 | Geometry Basics | Medium | ⭐⭐⭐ | F005 |
| GE010 | Points & Vectors | Medium | ⭐⭐⭐⭐ | GE005 |
| GE015 | Dot & Cross Product | Medium | ⭐⭐⭐⭐ | GE010 |
| GE020 | Line & Segment Intersection | Hard | ⭐⭐⭐ | GE015 |
| GE025 | Polygon Geometry (Area, Convex Polygon) | Hard | ⭐⭐⭐⭐ | GE020 |
| GE030 | Convex Hull | Hard | ⭐⭐⭐⭐ | GE025 |

---

# Advanced (12 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| ADV005 | Square Root Decomposition | Hard | ⭐⭐⭐⭐ | DS010 |
| ADV010 | Mo's Algorithm | Hard | ⭐⭐⭐⭐⭐ | ADV005 |
| ADV015 | Persistent Segment Tree | Expert | ⭐⭐⭐⭐ | DS070 |
| ADV020 | Implicit Segment Tree | Expert | ⭐⭐⭐ | DS070 |
| ADV025 | Merge Sort Tree | Hard | ⭐⭐⭐ | DS070 |
| ADV030 | Wavelet Tree | Expert | ⭐⭐ | ADV025 |
| ADV035 | Treap | Expert | ⭐⭐⭐ | DS090 |
| ADV040 | Splay Tree | Expert | ⭐⭐ | ADV035 |
| ADV045 | Link-Cut Tree | Expert | ⭐ | T020 |
| ADV050 | Fast Fourier Transform (FFT) | Expert | ⭐⭐⭐ | M080 |
| ADV055 | Number Theoretic Transform (NTT) | Expert | ⭐⭐ | ADV050 |
| ADV060 | Randomized Data Structures & Algorithms | Hard | ⭐⭐⭐ | ADV035 |

---

# Special Topics (11 Topics)

| ID | Topic | Difficulty | Importance | Prerequisites |
|----|-------|------------|------------|---------------|
| SP005 | Brute Force | Beginner | ⭐⭐⭐⭐⭐ | F010 |
| SP010 | Simulation | Beginner | ⭐⭐⭐⭐⭐ | SP005 |
| SP015 | Backtracking | Medium | ⭐⭐⭐⭐ | F020 |
| SP020 | Complete Search | Medium | ⭐⭐⭐ | SP015 |
| SP025 | Constructive Algorithms | Medium | ⭐⭐⭐⭐ | GR005 |
| SP030 | Offline Queries | Hard | ⭐⭐⭐⭐ | DS070 |
| SP035 | Online Queries | Hard | ⭐⭐⭐ | DS070 |
| SP040 | Interactive Problems | Medium | ⭐⭐⭐⭐ | SP010 |
| SP045 | Game Theory | Hard | ⭐⭐⭐ | M060 |
| SP050 | Probability & Expected Value | Hard | ⭐⭐⭐⭐ | M060 |
| SP055 | Parallel Binary Search | Expert | ⭐⭐⭐ | SA005 |

---

# Roadmap Summary

| Category | Topics |
|----------|-------:|
| Fundamentals | 8 |
| Data Structures | 19 |
| Searching & Sorting | 7 |
| Greedy | 6 |
| Graph | 25 |
| Trees | 6 |
| Dynamic Programming | 14 |
| Strings | 10 |
| Mathematics | 17 |
| Geometry | 6 |
| Advanced | 12 |
| Special Topics | 11 |
| **Total** | **141** |

---

# Learning Order

```
Fundamentals
    ↓
Data Structures
    ↓
Searching & Sorting
    ↓
Greedy
    ↓
Graph
    ↓
Trees
    ↓
Dynamic Programming
    ↓
Strings
    ↓
Mathematics
    ↓
Geometry
    ↓
Advanced
    ↓
Special Topics
```