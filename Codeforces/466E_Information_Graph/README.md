# 466E - Information Graph

**Codeforces Problem:** 466E - Information Graph

## Problem

Process a sequence of events in a company hierarchy where employees may receive bosses, document packets travel upward through the management chain, and queries ask whether a specific employee signed a particular packet.

The hierarchy always remains a forest.

## Approach

The company hierarchy is first constructed as a forest.

Each document packet receives a unique ID.

During a DFS from every root, each subtree maintains a set of active document packets.

The sets are merged using the **Small-to-Large** technique:

* always merge the smaller set into the larger one,
* each packet moves only a limited number of times.

Queries attached to each employee are answered while visiting that employee.

Before returning from a subtree, packets that should not affect higher ancestors are removed.

## Key Techniques

* Disjoint Set Union (DSU)
* DFS
* Small-to-Large (DSU on Tree)
* Set Merging
* Offline Query Processing

## Complexity

* **Time:** `O((n + m) log n)`
* **Memory:** `O(n log n)`

## Source

Codeforces 466E — Information Graph
