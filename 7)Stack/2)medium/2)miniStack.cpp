// Implement Min Stack : O(2N) and O(N) Space Complexity

// Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity.
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Link https://www.naukri.com/code360/problems/min-stack_3843991

// Approach 1: using stack of pairs
// We push elements into stack as pairs while maintaining the minimum element so far as second element of pair.
// Time Complexity: O(1) for all operations
// Space Complexity: O(N) for stack of pairs

#include <bits/stdc++.h>

class minStack
{
public:
    // pair of stack contain: {element as .first} and {smallest element so far as .second}.
    stack<pair<int, int>> stk;

    minStack() {}

    void push(int num)
    {
        if (stk.empty())
        {
            // stack is initially empty. In that case push current as first and minimum as curr_element too.
            stk.push({num, num});
        }
        else
        {
            // fetch the minimum by comparing curr_element & stk.top() pair's second.
            int newMin = min(stk.top().second, num);
            stk.push({num, newMin});
        }
    }

    int pop()
    {
        if (stk.empty())
        {
            return -1;
        }

        int top_ele = stk.top().first;
        stk.pop();
        return top_ele;
    }

    int top()
    {
        if (stk.empty())
        {
            return -1;
        }
        return stk.top().first;
    }

    int getMin()
    {
        if (stk.empty())
        {
            return -1;
        }
        return stk.top().second;
    }
};

// Approach 2: using a variable to store minimum element and pushing modified element into stack if it is minimum.

// Push operation:
// Now if there is a push operation just check whether that number is less than the min number.
// If it is smaller than min we will push a modified value which is a push(2 * Val – min) into the
// stack and will update min to the value of the original number. If it’s not then we will just push it as it is.

// Pop operation:
// While making pop we will check if the top value is lesser than min,
// If it is then we must update our min to its previous value.
// In order to do that min = (2 * min) – (modified value) and we will pop the element.

// Time Complexity: O(1) for all operations
// Space Complexity: O(N) for stack

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = Long.valuevalue;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin()
    {
        return mini;
    }
};