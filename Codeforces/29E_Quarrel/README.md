# 29E - Quarrel

**Codeforces Problem:** 29E - Quarrel

## Problem

Given an undirected graph, find the shortest routes for Bob and Alex from vertices `1` to `n` and from `n` to `1`, respectively, such that they never appear at the same vertex at the same time.

Both routes must have the same length. The two people are allowed to meet while passing each other on an edge.

## Approach

Consider the positions of Bob and Alex simultaneously as a single state:

`(u, v)`

where:

* `u` is Bob's current vertex.
* `v` is Alex's current vertex.

The initial state is `(1, n)` and the target state is `(n, 1)`.

From a state `(u, v)`, try every pair of moves:

* Bob moves from `u` to a neighbor `nu`.
* Alex moves from `v` to a neighbor `nv`.

The transition is valid only if:

`nu != nv`

because they cannot be at the same vertex at the same time.

We perform BFS on these states. Since every transition represents exactly one street for both people, the first time we reach `(n, 1)` gives the minimum possible route length.

Parent states are stored to reconstruct both routes.

## Complexity

* **Time:** `O(m²)`
* **Memory:** `O(n²)`

## Source

[Codeforces - 29E: Quarrel](https://codeforces.com/problemset/problem/29/E)
