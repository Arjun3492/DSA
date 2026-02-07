## 1. PrefixSum
### 1. PrefixSum for Query
**When to use:** When need to compute sum of queries in constant time

## 🪟 Sliding Window

**When to use:** Subarrays, window-based constraints

* ⬜ **Longest Substring Without Repeating Characters**
  🔗 [https://leetcode.com/problems/longest-substring-without-repeating-characters/](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
  🧠 Insight: shrink window on duplicate

* ⬜ **Maximum Sum Subarray of Size K**
  🔗 [https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k/](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k/)
  🧠 Insight: fixed window sum

* ⬜ **Minimum Window Substring**
  🔗 [https://leetcode.com/problems/minimum-window-substring/](https://leetcode.com/problems/minimum-window-substring/)
  🧠 Insight: variable window + frequency

---

## 👉 Two Pointers

**When to use:** Sorted arrays, pairs, in-place operations

* ⬜ **Two Sum II**
  🔗 [https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
  🧠 Insight: move pointers based on sum

* ⬜ **Container With Most Water**
  🔗 [https://leetcode.com/problems/container-with-most-water/](https://leetcode.com/problems/container-with-most-water/)
  🧠 Insight: move smaller height pointer

---

## 🔍 Binary Search

**When to use:** Sorted data or monotonic answer space

* ⬜ **Binary Search**
  🔗 [https://leetcode.com/problems/binary-search/](https://leetcode.com/problems/binary-search/)
  🧠 Insight: standard template

* ⬜ **Search in Rotated Sorted Array**
  🔗 [https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)
  🧠 Insight: one side always sorted

* ⬜ **Koko Eating Bananas**
  🔗 [https://leetcode.com/problems/koko-eating-bananas/](https://leetcode.com/problems/koko-eating-bananas/)
  🧠 Insight: binary search on answer

---

## 📚 Stack

**When to use:** Matching, previous states

* ⬜ **Valid Parentheses**
  🔗 [https://leetcode.com/problems/valid-parentheses/](https://leetcode.com/problems/valid-parentheses/)
  🧠 Insight: LIFO matching

* ⬜ **Min Stack**
  🔗 [https://leetcode.com/problems/min-stack/](https://leetcode.com/problems/min-stack/)
  🧠 Insight: auxiliary stack

---

## 📉 Monotonic Stack

**When to use:** Next greater/smaller elements

* ⬜ **Next Greater Element I**
  🔗 [https://leetcode.com/problems/next-greater-element-i/](https://leetcode.com/problems/next-greater-element-i/)
  🧠 Insight: decreasing stack

* ⬜ **Daily Temperatures**
  🔗 [https://leetcode.com/problems/daily-temperatures/](https://leetcode.com/problems/daily-temperatures/)
  🧠 Insight: index-based stack

* ⬜ **Largest Rectangle in Histogram**
  🔗 [https://leetcode.com/problems/largest-rectangle-in-histogram/](https://leetcode.com/problems/largest-rectangle-in-histogram/)
  🧠 Insight: nearest smaller boundaries

---

## 🧠 Dynamic Programming

**When to use:** Overlapping subproblems

* ⬜ **Climbing Stairs**
  🔗 [https://leetcode.com/problems/climbing-stairs/](https://leetcode.com/problems/climbing-stairs/)
  🧠 Insight: Fibonacci DP

* ⬜ **House Robber**
  🔗 [https://leetcode.com/problems/house-robber/](https://leetcode.com/problems/house-robber/)
  🧠 Insight: pick vs skip

* ⬜ **Longest Common Subsequence**
  🔗 [https://leetcode.com/problems/longest-common-subsequence/](https://leetcode.com/problems/longest-common-subsequence/)
  🧠 Insight: 2D DP

---

## 🌳 Trees

**When to use:** Hierarchical structure

* ⬜ **Maximum Depth of Binary Tree**
  🔗 [https://leetcode.com/problems/maximum-depth-of-binary-tree/](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
  🧠 Insight: DFS height

* ⬜ **Diameter of Binary Tree**
  🔗 [https://leetcode.com/problems/diameter-of-binary-tree/](https://leetcode.com/problems/diameter-of-binary-tree/)
  🧠 Insight: height + global max

---

## 🌐 Graphs

**When to use:** Connectivity, cycles

* ⬜ **Number of Islands**
  🔗 [https://leetcode.com/problems/number-of-islands/](https://leetcode.com/problems/number-of-islands/)
  🧠 Insight: DFS/BFS traversal

* ⬜ **Course Schedule**
  🔗 [https://leetcode.com/problems/course-schedule/](https://leetcode.com/problems/course-schedule/)
  🧠 Insight: cycle detection / topo sort

---

## 🧮 Heaps / Priority Queue

**When to use:** K largest/smallest

* ⬜ **Kth Largest Element in an Array**
  🔗 [https://leetcode.com/problems/kth-largest-element-in-an-array/](https://leetcode.com/problems/kth-largest-element-in-an-array/)
  🧠 Insight: min heap of size k

* ⬜ **Merge K Sorted Lists**
  🔗 [https://leetcode.com/problems/merge-k-sorted-lists/](https://leetcode.com/problems/merge-k-sorted-lists/)
  🧠 Insight: PQ over heads

