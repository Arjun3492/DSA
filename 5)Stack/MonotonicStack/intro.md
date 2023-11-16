# Monotonic Stack in C++

## Definition

A monotonic stack is a data structure that maintains a monotonic sequence, either non-increasing or non-decreasing, as elements are added or removed.

## Applications

- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
- [Previous Greater Element I](https://leetcode.com/problems/previous-greater-element-i/)

- [Next Smaller Element I](https://leetcode.com/problems/next-smaller-element-i/)
- [Previous Smaller Element I](https://leetcode.com/problems/previous-smaller-element-i/)

## Usage

For next greater /

## Implementation

```cpp
//Approach1: Starting from the start of the array
// If at any point the top of the stack is less than the current element ,
// then the current element is the "next greater element" for top element of the stack .(since we are traversing from the start)

// example: 1 2 3 4 5 6 7
// lets say we are at 2 and the stack is 1
// now we see that 2>1 so 2 is the next greater element for 1
// so we pop 1 and push 2
// now we are at 3 and the stack is 2 and we see that 3>2 so 3 is the next greater element for 2 and so on
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            //increasing monotonic stack
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

//Approach2: Starting from the end of the array
// If at any point the top of the stack is less than the current element ,
//we pop the top of the stack until the top of the stack is greater than the current element
//once we have popped all the elements greater than the current element , now if the stack is non empty
//then the top of the stack is the "next greater element" for the current element,
//else there is no "next greater element" for the current element
//(as we are traversing from right to left)

// example:  1 7 8 4 2 5
// lets say we are at element 2 and the stack is 5
// now we see that 5!<2 so the top of the stack is the next greater element for 2
// and then we push 2 as well
// now we are at 4 and the stack is 2 5
// now we see that 2<4 so we pop 2 and now the stack is 5
// now we see that 5!<4 so 5 is the next greater element for 4

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {

            st.pop();
        }
        if (!st.empty()) {
            res[i] = nums[st.top()];
        }
        st.push(i);
    }
    return res;
}


```

```cpp

void prevGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[i]<nums[st.top()] ) {
            //decreasing monotonic stack
            res[i] = nums[st.top()];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

```

```cpp

void prevSmallerElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[st.top()]<nums[i] ) {
            // top of the stack is prev smaller element of current element
            //increasing monotonic stack
            res[i] = nums[st.top()];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

```

```cpp

void nextSmallerElement(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            // top of the stack is next smaller element of current element
            //decreasing monotonic stack
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

```
