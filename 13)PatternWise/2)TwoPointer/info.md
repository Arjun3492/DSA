# Two Pointer Pattern

## 🔍 1. When Should Two Pointer Approach Be Used?

### ✅ Use this pattern when:
- You are working with **sorted arrays** or strings.
- You need to **find pairs**, **move inwards from both ends**, or **search for subarrays** that satisfy a condition.
- Problems ask for **in-place operations** like removing duplicates, reversing, or partitioning.

### 🧠 Keywords to watch for in a problem:
- “Find pair / triplet with sum = ___”
- “Remove duplicates in-place”
- “Reverse array / string”
- “Sorted array / list”
- “Merge two sorted arrays”
- “Subarray / substring with condition”

---

## 💣 2. Brute Force Approach (Without Two Pointers)

### Example: Find if any pair in a sorted array adds up to a target

```cpp
bool hasPairWithSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return true;
            }
        }
    }
    return false;
}
```

### ⛔ Time Complexity: `O(n^2)`

---

## 🛠️ 3. How Two Pointers Work (With C++ Template)

### 💡 Idea:
You use **two indices**, usually `left` and `right`, and **move them towards each other or along the array** based on conditions.

---

### ✅ Generic C++ Template (0-based indexing)

```cpp
bool hasPairWithSum(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
```
---

## 📚 4. Common Problems Based on Two Pointer Pattern

### 🟢 Easy
- [Leetcode 125](https://leetcode.com/problems/valid-palindrome/) – Valid Palindrome
- [Leetcode 344](https://leetcode.com/problems/reverse-string/) – Reverse String
- [Leetcode 26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) – Remove Duplicates from Sorted Array

### 🟡 Medium
- [Leetcode 167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) – Two Sum II (Sorted Array)
- [Leetcode 11](https://leetcode.com/problems/container-with-most-water/) – Container With Most Water
- [Leetcode 15](https://leetcode.com/problems/3sum/) – 3Sum

### 🔴 Hard
- [Leetcode 42](https://leetcode.com/problems/trapping-rain-water/) – Trapping Rain Water
- [Leetcode 76](https://leetcode.com/problems/minimum-window-substring/) – Minimum Window Substring (uses two pointers + hashmap)