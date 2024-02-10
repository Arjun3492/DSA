// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers,
// we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Link:https://www.codingninjas.com/studio/problems/longest-subarray-with-zero-sum_6783450

//  Example:
//  Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
//  Output: 5
//  Explanation: The longest subarray with zero sum is {-2, 2, -8, 1, 7}

// BRUTE FORCE APPROACH
// We will use nested loop to compute all the possible subarrays, and for each subarray we will
// compute the sum and check if it is zero

// Time complexity: O(n^2)
// Space complexity: O(1)

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// OPTIMAL APPROACH
//  We will use a hash map to store the prefix sum of the array
//  We will iterate over the array and keep adding the elements to the sum
//  If the sum is zero, then the length of the subarray will be i+1
//  If the sum is not zero, then we will check if the sum is already present in the hash map
//  If it is present, then the length of the subarray will be i - hash[sum]
//  If it is not present, then we will store the sum in the hash map

// Time complexity: O(n)
// Space complexity: O(n)

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> hashMap;
    int maxLen = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }
        if (hashMap.find(sum) != hashMap.end())
        {
            maxLen = max(maxLen, i - hashMap[sum]);
        }
        else
        {
            hashMap[sum] = i;
        }
    }
    return maxLen;
}
