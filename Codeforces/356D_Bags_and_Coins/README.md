# 356D - Bags and Coins

**Codeforces Problem:** 356D - Bags and Coins

## Problem

Given `n` bags, each containing a known total number of coins, construct a valid arrangement of bags inside other bags so that the total number of coins is exactly `s`.

For each bag, the number of coins it contains must equal its given value, including the coins inside its nested bags.

If no valid arrangement exists, output `-1`.

## Approach

Use **Bitset-Optimized Subset Sum DP** combined with a constructive strategy.

First, choose one bag with the maximum number of coins. At least one such bag must be at the top level of the arrangement.

The remaining top-level bags must have a total value of:

`target = s - max(a[i])`

Use Bitset DP to determine whether a subset of the remaining bags can achieve this target.

Define `dp[x]` to indicate whether a sum `x` is achievable.

For each bag, update the reachable sums using a bitset shift:

`dp |= (dp << a[i])`

The newly reachable states are extracted using `dp XOR previous_dp`. For each new state, store the index of the bag that first made it reachable in `fir`, allowing the selected subset to be reconstructed.

If the target cannot be achieved, output `-1`.

Otherwise:

1. Keep the selected bags as separate top-level bags.
2. Sort all unselected bags in descending order of their values.
3. Nest these bags one by one inside the maximum-valued bag, forming a chain.
4. Set the number of directly contained coins in each bag to the difference between its value and the value of its child.

This guarantees that every bag has the required total number of coins.

## Key Techniques

- Bitset Optimization
- Subset Sum DP
- Dynamic Programming Reconstruction
- Greedy Ordering
- Constructive Algorithms

## Complexity

Let `S` be the maximum possible target sum.

- **Time:** `O(n log n + nS / 64 + S)`
- **Memory:** `O(n + S / 64)`

## Source

[Codeforces - 356D: Bags and Coins](https://codeforces.com/problemset/problem/356/D)
