# Sliding Window Pattern

## 🔍 1. When Should Sliding Window Be Used?

### ✅ Use this pattern when:
- You need to **analyze contiguous blocks** of data (subarrays or substrings).
- You're given a **window size (k)** and need to:
  - Find **max/min/sum/average** of every subarray of size `k`.
  - Find **longest/shortest subarray** meeting some condition.

### 🧠 Keywords to watch for:
- “Contiguous subarray” or “contiguous substring”
- “Fixed size window”
- “Longest/shortest subarray with condition”
- “At most / at least k distinct elements”
- “Maximum sum of subarray of length k”

---

## 💣 2. Brute Force Approach

### Example: Max sum of subarray of size k

```cpp
int maxSum(vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
```

### ⛔ Time Complexity: `O(n * k)`

---

## 🛠️ 3. How Sliding Window Works (With C++ Template)

### 💡 Idea:
You maintain a **window of size `k`** and move it one step at a time by:
- **Adding the new element at the right**
- **Removing the leftmost element**

---

### ✅ C++ Template (Fixed-size window)

```cpp
int maxSum(vector<int>& nums, int k) {
    int n = nums.size();
    int windowSum = 0, maxSum = 0;

    // Build initial window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
```

### ✅ Time Complexity: `O(n)`

---

### ✅ C++ Template (Variable-size window – e.g., longest subarray with sum ≤ target)

```cpp
int longestSubarray(vector<int>& nums, int target) {
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        // Shrink window until valid
        while (sum > target) {
            sum -= nums[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

---

## 📚 4. Common Problems Based on Sliding Window Pattern

### 🟢 Easy
- [Leetcode 643](https://leetcode.com/problems/maximum-average-subarray-i/) – Maximum Average Subarray I
- [Leetcode 567](https://leetcode.com/problems/permutation-in-string/) – Permutation in String

### 🟡 Medium
- [Leetcode 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) – Longest Substring Without Repeating Characters
- [Leetcode 424](https://leetcode.com/problems/longest-repeating-character-replacement/) – Longest Repeating Character Replacement
- [Leetcode 438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) – Find All Anagrams in a String

### 🔴 Hard
- [Leetcode 76](https://leetcode.com/problems/minimum-window-substring/) – Minimum Window Substring
- [Leetcode 239](https://leetcode.com/problems/sliding-window-maximum/) – Sliding Window Maximum (uses deque)

---

Would you like to practice one of these problems interactively or dive into the next DSA pattern like **Fast & Slow Pointers** or **Binary Search on Answer**?