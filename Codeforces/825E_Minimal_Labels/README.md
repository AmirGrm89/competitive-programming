# 825E - Minimal Labels

**Codeforces Problem:** 825E - Minimal Labels

## Problem

Given a directed acyclic graph (DAG), assign a distinct label from `1` to `n` to each vertex such that for every directed edge `u → v`:

`label[u] < label[v]`

Find the lexicographically smallest valid labeling.

## Approach

Use **Reverse Topological Sorting** with a Greedy strategy.

First, reverse all edges. In the reversed graph, vertices with zero in-degree correspond to sinks in the original graph.

Maintain all currently available vertices in an ordered set.

At each step:

1. Select the vertex with the largest index among the available vertices.
2. Assign it the largest remaining label.
3. Remove it from the graph.
4. Update the in-degrees of its neighbors and insert newly available vertices into the set.

Choosing the largest available vertex first while assigning labels in decreasing order produces the lexicographically smallest valid labeling.

Finally, store each `(vertex, label)` pair and output the labels in increasing order of vertex indices.

## Key Techniques

- Topological Sorting
- Greedy
- Reverse Graph
- Ordered Set
- Lexicographical Optimization

## Complexity

- **Time:** `O((n + m) log n)`
- **Memory:** `O(n + m)`

## Source

[Codeforces - 825E: Minimal Labels](https://codeforces.com/problemset/problem/825/E)
