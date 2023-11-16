// Subarray Range Sum
// Problem Statement: You are given an integer array nums.
// The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example: nums = [1, 2, 3, 4]
// Subarrays: [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4], [1, 2, 3, 4]
// Range of subarrays: 0, 0, 0, 0, 1, 1, 1, 2, 2, 3
// Sum of all subarray ranges: 10

// Naive Approach: Generate all subarrays and find the range of each subarray and add it to the sum. Time Complexity: O(n^3)
// or O(n^2) if we find the range while generating the subarrays.

int rangeSum(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            sum += maxi - mini;
        }
    }
    return sum;
}

// Optimal Approach: Use a monotonic stack to find the range of all subarrays. Time Complexity: O(n)

int rangeSum(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s1, s2;
    vector<pair<int, int>> leftBound(n), rightBound(n);

    // handling base case
    for (int i = 0; i < n; i++)
    {
        // if no left bound is found
        leftBound[i] = {i, i};
        // if no right bound is found
        rightBound[i] = {n - 1 - i, n - 1 - i};
    }

    // For prev greater / prev smaller iterating from left to right
    for (int i = 0; i < n; i++)
    {
        // for previous smaller ,using a decreasing monotonic stack
        while (!s1.empty() && nums[s1.top()] >= nums[i])
        {
            s1.pop();
        }
        if (!s1.empty())
        {
            // the top of the stack is the left smaller element of the current index
            // element
            leftBound[i].first = i - s1.top() - 1;
        }
        s1.push(i);

        // for previous greater using a incresing monotonic stack
        while (!s2.empty() && nums[s2.top()] <= nums[i])
        {
            s2.pop();
        }
        if (!s2.empty())
        {
            // the top of the stack is the left greater element of the current index
            // element
            leftBound[i].second = i - s2.top() - 1;
        }
        s2.push(i);
    }

    // clearing stack
    while (!s1.empty())
    {
        s1.pop();
    }
    while (!s2.empty())
    {
        s2.pop();
    }

    // For next smaller / next greater  iterating from right to left

    // increasing monotonic stack for next smaller element / previous greater
    // element
    for (int i = n - 1; i >= 0; i--)
    {
        // next greater element,using a increasing monotonic stack
        while (!s1.empty() && nums[s1.top()] < nums[i])
        {
            s1.pop();
        }
        if (!s1.empty())
        {
            // the top of the stack index element is the next greater element of the
            // current index element
            rightBound[i].second = s1.top() - i - 1;
        }

        s1.push(i);

        // next smaller element ,using a decreasing monotonic stack
        while (!s2.empty() && nums[s2.top()] > nums[i])
        {
            s2.pop();
        }
        if (!s2.empty())
        {
            // the top of the stack index element is the next smaller element of the
            // current index element
            rightBound[i].first = s2.top() - i - 1;
        }
        s2.push(i);
    }

    int sumSubMax = 0;
    int sumSubMin = 0;
    for (int i = 0; i < n; i++)
    {
        sumSubMax +=
            nums[i] * (leftBound[i].second + 1) * (rightBound[i].second + 1);
        sumSubMin += nums[i] * (leftBound[i].first + 1) * (rightBound[i].first + 1);
    }
    return sumSubMax - sumSubMin;
}
