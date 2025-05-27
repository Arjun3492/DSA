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

## Note:

**For previous greater / smaller element we need to traverse the array from left to right**

**For next greater / smaller element we need to traverse the array from right to left**

___

## Usage

### For previous / next smaller use a decreasing monotonic stack

```cpp
// decreasing monotonic stack for next / previous smaller element
for (int i = 0; i < n; i++) {
    //previous smaller element
              while(!s1.empty() && nums[s1.top()]>=nums[i]){
                s1.pop();
            }
            if(!s1.empty())cout<<"The previous smaller element of "<<nums[i]<<"is"<<  nums[s1.top()];
            s1.push(i);
  }

for (int i = n-1; i >=0; i--) {
    //next smaller element
              while(!s2.empty() && nums[s2.top()]>=nums[i]){
                s2.pop();
            }
            if(!s2.empty())cout<<"The next smaller element of "<<nums[i]<<"is"<<  nums[s2.top()];
            s2.push(i);
  }
```

### For next / previous greater use a increasing monotonic stack

```cpp

// increasing monotonic stack for next greater element / previous greater element
for (int i = 0; i < n; i++) {
    //previous greater element
              while(!s1.empty() && nums[s1.top()]<=nums[i]){
                s1.pop();
            }
            if(!s1.empty())cout<<"The previous greater element of "<<nums[i]<<"is"<<  nums[s1.top()];
            s1.push(i);
  }

for (int i = n-1; i >=0; i--) {
    //next greater element
              while(!s2.empty() && nums[s2.top()]<=nums[i]){
                s2.pop();
            }
            if(!s2.empty())cout<<"The next greater element of "<<nums[i]<<"is"<<  nums[s2.top()];
            s2.push(i);
  }
```

---

### ✅ Template: Largest Rectangle in Histogram

```cpp
/*
We go through the histogram from left to right, keeping a monotonic increasing stack of indices — that means the heights of the bars at those indices are always in increasing order.

For each new bar we look at:


If it's shorter than the bar on top of the stack, then:

This new bar is the "next smaller" bar for the one at the top.

So we pop the top bar, and:

The bar now at the top of the stack (after popping) is the "previous smaller" for the bar we just removed.

With both previous and next smaller bars known, we can calculate the maximum rectangle area for the popped bar.

Push the current bar index onto the stack.

We also add a 0 at the end of the list as a sentinel.
This ensures that all bars in the stack get processed(popped), even if the histogram ends with increasing heights.
*/
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

