# 310 - D. A Simple Task

**Original Source:** SGU 310 - D. A Simple Task

## Problem

Given a simple undirected graph, count the number of simple cycles in it.

A simple cycle is a cycle with no repeated vertices or edges.

## Approach

Use **Bitmask DP** to count simple cycles.

Define `dp[mask][v]` as the number of paths that use exactly the vertices in `mask` and end at vertex `v`.

To avoid counting the same cycle multiple times from different starting vertices, let `small` be the smallest-numbered vertex in the current `mask`.

When extending a path, only add vertices whose index is greater than `small`.

If the current endpoint is connected to `small` and the path contains at least three vertices, a simple cycle is formed.

Every cycle is counted in both directions, so the final result is divided by `2`.

## Key Techniques

* Bitmask DP
* Subset DP
* Graph DP
* Simple Cycle Counting

## Complexity

* **Time:** `O(2^n · (n + m))`
* **Memory:** `O(2^n · n)`

where `n ≤ 19`.

## Source

[SGU 310 - D. A Simple Task](https://acmp.ru/index.asp?main=task&id_task=310)
