# 580C - Kefa and Park

**Codeforces Problem:** 580C - Kefa and Park

## Problem

Given a rooted tree, count the number of leaf vertices that can be reached from the root without encountering more than `m` consecutive vertices containing cats.

## Approach

Use **BFS** starting from the root.

For every visited vertex, keep track of the number of consecutive cat vertices on the path from the root to that vertex.

* If the current vertex has a cat, increase the consecutive-cat count.
* If it does not have a cat, reset the count to `0`.
* If moving to a cat vertex would make the consecutive-cat count greater than `m`, do not visit that vertex.

After the BFS, count the visited vertices that are leaves.

## Complexity

* **Time:** `O(n)`
* **Memory:** `O(n)`

## Source

[Codeforces - 580C: Kefa and Park](https://codeforces.com/problemset/problem/580/C)
