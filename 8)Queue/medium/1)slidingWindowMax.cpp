// Sliding window maximum
// Problem statement:You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right. You can only see the k numbers
// in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

// Link : https://www.naukri.com/code360/problems/sliding-window-maximum_980226

// Approach: Naive approach
// Taking two pointers left and right,left pointing to the first element of the window and right pointing to the last element of the window.
// We will find the maximum element in the window and push it to the vector.
// Time complexity: O(n*k) , where n is the size of the array and k is the size of the window.
// Space complexity: O(1) , as we are not using any extra space.

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    int left = 0, right = 0;
    vector<int> ans;

    while (right < k - 1)
    {
        right++;
    }
    while (right < n)
    {
        int maxi = INT_MIN;
        for (int i = left; i <= right; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        ans.push_back(maxi);
        left++;
        right++;
    }
    return ans;
}

// Time complexity: O(n*k)
// Space complexity: O(1)

// Approach: Using deque(Monotonic queue)
// We will use a deque to store the indices of the elements of the window.
// We will maintain the deque in such a way that the front of the deque will always contain the maximum element of the window.
// We will push the elements of the window to the deque and pop the elements from the back of the deque if they are smaller than the current element.
// We will push the front of the deque to the vector.

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            // if the front of the deque is out of the window, we pop it.(if front of the deque is equal to i-k, it means deque consist of k elements , and the i-k element is the maximum element of the previous window. So we pop it.)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            // if the back of the deque is smaller than the current element, we pop it.
            dq.pop_back();
        }
        // we push the current element to the deque.
        dq.push_back(i);

        if (i >= k - 1)
            // starting from the kth element, we push the front of the deque to the vector.
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}