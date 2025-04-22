# Modified Binary Search

## 🔍 1. When Should Modified Binary Search Be Used?

### ✅ Use this pattern when:
- The array is **sorted or partially sorted**, rotated, or has **duplicate values**, or you're working with **search-based decision making**.
- You need to search for:
  - A specific element in a **rotated sorted array**
  - **First/last occurrence** of a target (handling duplicates)
  - **Boundary conditions** (e.g., floor/ceil of a number)
  - **Peak elements**, or **min/max in valleys/mountains**
  - Problems that say: “find the minimum value that satisfies a condition” → also called **Binary Search on the Answer**

### 🧠 Keywords to look for:
- “Rotated sorted array”
- “Find first/last occurrence”
- “Element greater/smaller than target”
- “Minimum in rotated array”
- “Peak element”
- “Search a value in mountain/valley array”
- “Binary Search + condition”

---

## 💣 2. Brute Force Approach

### Example: Search in Rotated Sorted Array

```cpp
int search(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) return i;
    }
    return -1;
}
```

### ⛔ Time: `O(n)` — This ignores the sorted structure!

---

## 🛠️ 3. How Modified Binary Search Works + C++ Template

### 💡 Key Ideas:
- Start with basic binary search: `left`, `right`, `mid`
- Add logic to determine **which part is sorted** or **how to move the pointers** based on the condition
- Common variations include:
  - Adjusting based on **duplicates**
  - Using **value comparisons instead of equality**
  - **Mid-value condition checks** for more complex problems

---

### ✅ Template: Search in Rotated Sorted Array

```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        // Left part is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // target is in left part
            } else {
                left = mid + 1;
            }
        }
        // Right part is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;  // target is in right part
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}
```

---

### ✅ Template: Find First Occurrence of a Target

```cpp
int firstOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;       // possible answer, but continue left
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
```

---

### ✅ Template: Binary Search on the Answer (e.g., minimum speed to deliver packages)

```cpp
int findMinSpeed(vector<int>& weights, int days) {
    int left = 1, right = *max_element(weights.begin(), weights.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, mid, days)) {
            result = mid;        // try a smaller speed
            right = mid - 1;
        } else {
            left = mid + 1;      // need a bigger speed
        }
    }

    return result;
}
```

Helper function `canShip` would simulate the shipping to check feasibility.

---

## 📚 4. Common Problems Using Modified Binary Search

### 🟢 Easy
- [Leetcode 704](https://leetcode.com/problems/binary-search/) – Binary Search
- [Leetcode 852](https://leetcode.com/problems/peak-index-in-a-mountain-array/) – Peak Index in a Mountain Array

### 🟡 Medium
- [Leetcode 33](https://leetcode.com/problems/search-in-rotated-sorted-array/) – Search in Rotated Sorted Array
- [Leetcode 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) – First and Last Position
- [Leetcode 162](https://leetcode.com/problems/find-peak-element/) – Find Peak Element
- [Leetcode 875](https://leetcode.com/problems/koko-eating-bananas/) – Koko Eating Bananas (Binary Search on Answer)
- [Leetcode 1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) – Capacity to Ship Packages

### 🔴 Hard
- [Leetcode 410](https://leetcode.com/problems/split-array-largest-sum/) – Split Array Largest Sum
- [Leetcode 154](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) – Min in Rotated Sorted Array II (with duplicates)
- [Leetcode 1095](https://leetcode.com/problems/find-in-mountain-array/) – Find in Mountain Array

