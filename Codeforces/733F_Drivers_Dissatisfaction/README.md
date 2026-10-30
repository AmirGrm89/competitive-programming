# 733F - Drivers Dissatisfaction

**Codeforces Problem:** 733F - Drivers Dissatisfaction

## Problem

Given a connected weighted undirected graph, choose a spanning tree with minimum total edge weight after spending a limited budget to reduce the dissatisfaction values of some edges.

Each edge has:
- An initial weight `w[i]`.
- A reduction cost `c[i]`, representing the budget required to decrease its weight by one.

The total budget is `S`. Edge weights are allowed to become zero or negative.

Find the minimum possible total weight of the resulting spanning tree and output its edges with their final weights.

## Approach

First, construct a Minimum Spanning Tree (MST) using **Kruskal's Algorithm** with the original edge weights.

The key observation is that, for a fixed spanning tree, the budget should be spent on an edge with the minimum reduction cost among the selected edges.

Therefore, consider each edge `i` as the edge receiving the budget.

Its weight can be reduced by:

`S / c[i]`

Adding this edge to the original MST creates a cycle. To obtain the minimum-weight spanning tree containing this edge, remove the maximum-weight edge on the MST path between its endpoints.

Use **LCA with Binary Lifting** to find this maximum-weight edge efficiently.

For each candidate edge, calculate:

`MST weight - maximum path edge + w[i] - S / c[i]`

Choose the candidate with the minimum total weight, replace the corresponding edge in the original MST, and apply the reduction to the selected edge.

## Key Techniques

- Minimum Spanning Tree (MST)
- Kruskal's Algorithm
- Disjoint Set Union (DSU)
- Lowest Common Ancestor (LCA)
- Binary Lifting
- Maximum Edge Query on a Tree Path
- MST Edge Replacement
- Greedy Optimization

## Complexity

- **Time:** `O(m log m + (n + m) log n)`
- **Memory:** `O(n log n + m)`

## Source

[Codeforces - 733F: Drivers Dissatisfaction](https://codeforces.com/problemset/problem/733/F)
