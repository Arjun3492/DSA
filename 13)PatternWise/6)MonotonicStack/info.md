# Monotonic Stack Pattern

## 🔍 1. When Should Monotonic Stack Be Used?

### ✅ Use this pattern when:
- You need to find:
  - **Next Greater Element (NGE)**
  - **Previous Smaller Element (PSE)**
  - **Next Smaller Element (NSE)**
  - **Previous Greater Element (PGE)**
- You’re asked for **span**, **ranges**, or **distances** in arrays.
- You’re dealing with problems that involve **heights**, **temperatures**, or **prices**, often in **1D array** form.

### 🧠 Keywords to look for:
- “Next greater/smaller element”
- “Previous greater/smaller element”
- “Span of stocks”
- “Histogram”
- “Days until warmer temperature”
- “Largest rectangle”

---

## 💣 2. Brute Force Approach

### Example: Next Greater Element

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (nums[j] > nums[i]) {
                res[i] = nums[j];
                break;
            }
        }
    }

    return res;
}
```

### ⛔ Time: `O(n^2)`, Space: `O(n)`

---

## 🛠️ 3. How Monotonic Stack Works (C++ Template)

### 💡 Idea:
Maintain a **monotonic increasing or decreasing stack** of **indices** (not values). As you iterate, pop elements that violate the order, then process accordingly.

---

### ✅ Template: Next Greater Element (Monotonic Decreasing Stack)

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return res;
}
```

---

### ✅ Template: Previous Smaller Element (Monotonic Increasing Stack)

```cpp
vector<int> prevSmallerElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) res[i] = nums[st.top()];
        st.push(i);
    }

    return res;
}
```

---

### ✅ Template: Largest Rectangle in Histogram

```cpp
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); // sentinel
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
}
```

---

## 📚 4. Common Problems Based on Monotonic Stack

### 🟢 Easy
- [Leetcode 496](https://leetcode.com/problems/next-greater-element-i/) – Next Greater Element I
- [Leetcode 1475](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) – Final Prices With a Special Discount

### 🟡 Medium
- [Leetcode 739](https://leetcode.com/problems/daily-temperatures/) – Daily Temperatures
- [Leetcode 901](https://leetcode.com/problems/online-stock-span/) – Online Stock Span

### 🔴 Hard
- [Leetcode 84](https://leetcode.com/problems/largest-rectangle-in-histogram/) – Largest Rectangle in Histogram
- [Leetcode 85](https://leetcode.com/problems/maximal-rectangle/) – Maximal Rectangle
- [Leetcode 316](https://leetcode.com/problems/remove-duplicate-letters/) – Remove Duplicate Letters

