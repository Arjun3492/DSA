// Kadane’s Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array arr, find the contiguous subarray
//  (containing at least one number) which has the largest sum and returns its sum and prints the subarray

// BRUTE FORCE APPROACH
// Compute the sum of each subarray

for (int i = 0; i < n; i++)
{
    int sum = 0;
    for (int j = i; j < n; j++)
    {
        sum += arr[j];
        maxi = max(sum, maxi);
    }
}

// KADANE's algo
//  The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0.
//  A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part
//  of the subarray with maximum sum.

// Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable.
// Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray
// with a negative sum. Among all the sums calculated, we will consider the maximum one.

long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long maxi = LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    return maxi;
}

// to find the subarray

int start = 0, end = 0;
vector<int> maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long maxi = LONG_MIN;
    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum > maxi)
        {
            maxi = sum;
            end = i;
        }
    }
    return {arr.begin() + start, arr.begin() + end};
}
