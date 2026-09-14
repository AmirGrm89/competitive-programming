# 977E - Cyclic Components

**Codeforces Problem:** 977E - Cyclic Components

## Problem

Given an undirected graph, find the number of connected components that are cycles.

A connected component is a cycle if every vertex in that component has degree exactly `2`.

## Approach

First, find all connected components using **BFS**.

Each vertex is assigned a component ID during the BFS.

Then, for every vertex, check its degree:

* If its degree is not `2`, its connected component cannot be a cycle.
* After checking all vertices, count the components that were never marked as invalid.

Therefore, a connected component is counted exactly when every vertex in it has degree `2`.

## Algorithm

1. Build the graph using an adjacency list.
2. Run BFS to find all connected components.
3. Assign a unique ID to each component.
4. For every vertex, check whether its degree is exactly `2`.
5. Mark the component of every vertex whose degree is not `2`.
6. Count the components that were never marked.

## Complexity

* **Time:** `O(n + m)`
* **Memory:** `O(n + m)`

## Source

[Codeforces - 977E: Cyclic Components](https://codeforces.com/problemset/problem/977/E)
