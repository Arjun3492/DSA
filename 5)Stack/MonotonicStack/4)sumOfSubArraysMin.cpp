// Problem Statement: Find the sum of min of all subarrays of an array.

// Example: arr = [3, 1, 2, 4]
// Subarrays: [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]
// Min of all subarrays: 3, 1, 2, 4, 1, 1, 2, 1, 1, 1
// Sum of min of all subarrays: 17

// Naive Approach: Generate all subarrays and find the min of each subarray and add it to the sum. Time Complexity: O(n^3)
// or O(n^2) if we find the min while generating the subarrays.

int sumSubarrayMins(vector<int> &arr)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            sum += mini;
        }
    }
    return sum % mod;
}
// Optimal Approach: Use a monotonic stack to find the min of all subarrays. Time Complexity: O(n)

// Steps:
// 1. Create a vector previousSmaller and nextSmaller of size n to store the index of the next smaller element to the previousSmaller and nextSmaller of the current element.
// 2. Create a monotonic stack to store the indices of the elements in the array.
// 3. Traverse the array from left to right and update the previousSmaller vector.
// 4. Traverse the array from right to left and update the nextSmaller vector.
// 5. For each element in the array, the number of subarrays in which it is the minimum element is equal to (nextSmaller[i] - previousSmaller[i] + 1).
// 6. Add the product of the current element and the number of subarrays in which it is the minimum element to the sum.
// 7. Return the sum.

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> previousSmaller(n), nextSmaller(n);
    stack<int> st;
    // handling base case
    for (int i = 0; i < n; i++)
    {
        // if no previous smaller element is found
        previousSmaller[i] = i;
        // if no next smaller element is found
        nextSmaller[i] = n - 1 - i;
    }

    // find the previous smaller element bound
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            previousSmaller[i] = i - st.top() - 1;

        st.push(i);
    }
    // clearing stack
    while (!st.empty())
        st.pop();

    // find the next smaller element bound
    for (int i = n - 1; i > -1; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            nextSmaller[i] = st.top() - i - 1;
        st.push(i);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int leftBoundary = previousSmaller[i] + 1;
        int rightBoundary = nextSmaller[i] + 1;
        sum += (arr[i] * leftBoundary * rightBoundary);
    }
    return sum % mod;
}