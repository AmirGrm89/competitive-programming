# 609E - Minimum Spanning Tree for Each Edge

**Codeforces Problem:** 609E - Minimum Spanning Tree for Each Edge

## Problem

Given a connected weighted undirected graph, find the minimum possible weight of a spanning tree containing each edge of the graph.

For every edge, output the minimum total weight of a spanning tree that includes that edge.

## Approach

First, construct a **Minimum Spanning Tree (MST)** using **Kruskal's algorithm**.

Then, root the MST at vertex `1` and use **Binary Lifting** to preprocess:

- The `2^k`-th ancestor of each vertex.
- The maximum edge weight on the path to that ancestor.

For each original edge `(u, v, w)`, find the maximum edge weight on the MST path between `u` and `v` using **LCA** and Binary Lifting.

Adding the given edge to the MST creates a cycle. Removing the maximum-weight edge on the path between its endpoints produces a minimum spanning tree containing the given edge.

Therefore, the answer for each edge is:

`MST weight + w - maximum edge weight on the path(u, v)`

## Key Techniques

- Minimum Spanning Tree (MST)
- Kruskal's Algorithm
- Disjoint Set Union (DSU)
- Lowest Common Ancestor (LCA)
- Binary Lifting
- Maximum Edge Query on a Tree Path

## Complexity

- **Time:** `O(m log m + (n + m) log n)`
- **Memory:** `O(n log n + m)`

## Source

[Codeforces - 609E: Minimum Spanning Tree for Each Edge](https://codeforces.com/problemset/problem/609/E)
