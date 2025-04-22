# Prefix Sum Pattern

## 🔍 1. When Should Prefix Sum Be Used?

### ✅ Use this pattern when:

- You need to **compute the sum of elements in a range [L, R]** in an array repeatedly.
- The problem involves **subarrays** and **you’re being asked about sum, average, or count of elements in a range**.
- You're trying to optimize a **brute-force nested loop** that calculates range sums.

### 🧠 Keywords to watch for in a problem:

- "Find sum from index `i` to `j`"
- "Number of subarrays whose sum is \_\_\_"
- "Range sum queries"
- "Cumulative sum"
- "Sliding window sum but for dynamic ranges"

---

## 💣 2. Brute Force Approach (Without Prefix Sum)

```cpp
int rangeSum(vector<int>& nums, int L, int R) {
    int sum = 0;
    for (int i = L; i <= R; i++) {
        sum += nums[i];
    }
    return sum;
}
```

### ⛔ Time Complexity:

- O(n) per query (or O(n²) total if many queries)

---

## 🛠️ 3. How Prefix Sum Works (With C++ Template)

### 💡 Idea:

You pre-compute an array `prefix[]` where:

```
prefix[i] = sum of elements from nums[0] to nums[i-1]
```

Then, you can calculate any range sum `nums[L..R]` as:

```
prefix[R] - prefix[L-1]
```

### ✅ C++ Template:

```cpp
// Step 1: Build prefix sum array (0-based indexing)
vector<int> buildPrefixSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    return prefix;
}

// Step 2: Use prefix sum to get range sum [L, R]
int getRangeSum(const vector<int>& prefix, int L, int R) {
    if (L == 0) return prefix[R];
    return prefix[R] - prefix[L - 1];
}

```

### ✅ Time Complexity:

- Building prefix array: O(n)
- Each query: O(1)

---

## 📚 4. Common Problems Based on Prefix Sum Pattern

### 🟢 Easy

- [Leetcode 303](https://leetcode.com/problems/range-sum-query-immutable/) - Range Sum Query - Immutable
- [Leetcode 724](https://leetcode.com/problems/find-pivot-index/) - Find Pivot Index
- [Leetcode 1480](https://leetcode.com/problems/running-sum-of-1d-array/) - Running Sum of 1d Array

### 🟡 Medium

- [Leetcode 560](https://leetcode.com/problems/subarray-sum-equals-k/) - Subarray Sum Equals K
- [Leetcode 1248](https://leetcode.com/problems/count-number-of-nice-subarrays/) - Count Number of Nice Subarrays
- [Leetcode 525](https://leetcode.com/problems/contiguous-array/) - Contiguous Array

### 🔴 Hard

- [Leetcode 930](https://leetcode.com/problems/binary-subarrays-with-sum/) - Binary Subarrays With Sum
- [Leetcode 1074](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/) - Number of Submatrices That Sum to Target

