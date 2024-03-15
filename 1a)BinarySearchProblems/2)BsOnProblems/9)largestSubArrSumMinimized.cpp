// Largest Subarray Sum Minimized
// Problem statement
// Given an integer array ‘A’ of size ‘N’ and an integer ‘K'.
// Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
// Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Example:
// Input: ‘N’ = 5, ‘A’ = [1, 2, 3, 4, 5], ‘K’ = 3
// Output: 6
// Explanation: There are many ways to split the array ‘A’ into K consecutive subarrays. The best way to do this is to split the array ‘A’ into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

// Link : https://www.codingninjas.com/studio/problems/largest-subarray-sum-minimized_7461751

// Intuition
// We are given an array of integers and we have to split the array into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
// We know that the minimum possible value of the largest sum of any subarray will be the maximum number in the array and the maximum possible value of the largest sum of any subarray will be the sum of all the elements in the array.
// So for each possible value within the minimum and maximum value of the largest sum of any subarray, we will check if it is possible to split the array into ‘K’ non-empty subarrays such that the largest sum of any subarray is the current value.

// Utility function to check if it is possible to split the array into ‘K’ non-empty subarrays such that the largest sum of any subarray is the current value.
bool isPossible(vector<int> a, int k, int maxSum)
{
    int currSum = 0;
    int subarraysFormed = 1;
    for (int i : a)
    {
        if (currSum + i <= maxSum)
        {
            // add element to curr subarray
            currSum += i;
        }
        else
        {
            // move to new subarray
            currSum = i;
            subarraysFormed++;
            if (subarraysFormed > k) // Check if the subarraysFormed exceed the given limit
                return false;
        }
    }
    return true;
}

// BRUTE FORCE
// We will iterate over the possible values of the largest sum of any subarray and for each value, we will check if it is possible to split the array into ‘K’ non-empty subarrays such that the largest sum of any subarray is the current value.
// If possible we will update the answer and if not then we will keep on checking the same.
// Time complexity: O(n^2)
// Space complexity: O(1)

int largestSubarraySumMinimized(vector<int> a, int k)
{
    int n = a.size();
    if (k > n + 1) // i.e. k> number of elements
        return -1;
    // min sum of subarrays that can be(if each element is divided into a
    // subarray i.e. k=n)
    int low = *max_element(a.begin(), a.end());
    // max sum of subarrays that can be(if whole of the array is taken as a
    // subarray i.e. k=1)

    int high = accumulate(a.begin(), a.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (isPossible(a, k, i))
        {
            return i; // since we need the minimum sum , we will return the first possible value
        }
    }
}

// OPTIMAL APPROACH
// We will apply BS with the possible values of the largest sum of any subarray.
// For each mid, we will check if it is possible to split the array into ‘K’ non-empty subarrays such that the largest sum of any subarray is the current value.
// If it is possible then we will try to minimize the largest sum and if it is not possible then we will try to move to right half.
// Time complexity: O(nlog(n))
// Space complexity: O(1)

int largestSubarraySumMinimized(vector<int> a, int k)
{

    int n = a.size();
    if (k > n + 1) // i.e. k> number of elements
        return -1;
    // min sum of subarrays that can be(if each element is divided into a
    // subarray i.e. k=n)
    int low = *max_element(a.begin(), a.end());
    // max sum of subarrays that can be(if whole of the array is taken as a
    // subarray i.e. k=1)

    int high = accumulate(a.begin(), a.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        if (isPossible(a, k, mid))
        {
            ans = mid;
            high = mid - 1; // check for a smaller possible maxsum
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
