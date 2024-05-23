// Next Greater Element Using Stack
// Problem Statement: Given a circular integer array A, return the next greater element for every element in A.
// The next greater element for an element x is the first element greater than x that we come across while traversing
// the array in a clockwise manner. If it doesn’t exist, return -1 for this element.

// Link : https://www.naukri.com/code360/problems/next-greater-element-ii_6212757

//  Stack approach
//  Steps:
//  Similar to previous problem, we use a monotonic stack.
//  In this case, we traverse the array twice to mimic the circular traversal.

// Function to find the Next Greater Element in a given circular array
vector<int> nextGreaterElementII(vector<int> &a)
{
    int n = a.size();
    vector<int> ans(n, -1); // Initialize result vector with -1 for elements without a greater element
    stack<int> st;          // Stack to store indices of elements in the circular array

    // For circular array, we traverse the array twice to mimic the circular traversal
    for (int i = 2 * n - 1; i > -1; i--)
    {
        // While the stack is not empty and the top element of the stack is less than or equal to the current element
        while (!st.empty() && st.top() <= a[i % n])
        {
            // Pop elements from the stack if they are less than or equal to the current element
            st.pop();
        }

        // If the stack is not empty after the while loop, update the result with the top element of the stack
        if (!st.empty())
        {
            ans[i % n] = st.top();
        }

        // Push the current element's value onto the stack
        st.push(a[i % n]);
    }

    return ans; // Return the vector containing the Next Greater Elements in the circular array
}
