// Next Greater Element Using Stack
// Problem Statement: Given a integer array arr, return the next greater element for every element in arr.
// The next greater element for an element x is the first element greater than x that we come across while traversing
// the array on the rightside of x. If it doesn’t exist, return -1 for this element.

// Input: arr = [1, 2, 3, 4, 5, 6, 7]
// Output: [2, 3, 4, 5, 6, 7, -1]

// BRUTE FORCE APPROACH
// Steps:
// 1. Create an empty vector of size n and initialize all elements with -1.
// 2. For each element in the array, check if there is any element greater than the current element on the right side.
// 3. If there is any element greater than the current element, then update the GRE of the current element in the ans vector.
// 4. Return the ans vector.

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// OPTIMAL APPROACH
// Stack approach
// In this approach, a monotonic stack is used.
// In the case to find the next greater element, decreasing monotonic stack is used.

// In a decreasing monotonic stack, the top element is removed if the element to be inserted is greater than the top
// element. This procedure is repeated until the monotonic stack becomes empty or the top element is greater than the
// item to be inserted.

// Steps:

// // Initialize a stack and array.
// Traverse the array from the end.
// Update the monotonic stack as explained above.
// Add the next greater element in the array. If the stack is empty, i.e., no element is present, then add -1.
// Add the current element to the stack.

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i > -1; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

// Approach2.1:Starting from the start of the array
// if at any point the top of the stack is less than the current element ,
// then the current element is the "next greater element" for top element of the stack .(since we are traversing from the start)

// example: 1 2 3 4 5 6 7
// lets say we are at 2 and the stack is 1
// now we see that 2>1 so 2 is the next greater element for 1
// so we pop 1 and push 2
// now we are at 3 and the stack is 2 and we see that 3>2 so 3 is the next greater element for 2 and so on
vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            ans[i] = st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    return ans;
}