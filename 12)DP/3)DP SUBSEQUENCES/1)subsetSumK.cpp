// Subset Sum Equal To K
// Problem statement
// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

// Link : https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

// Approach
// 1. We will use a recursive function to check if there exists a subset in the array with a sum equal to 'K'.
// 2. We will consider two possibilities for each element in the array: either include it in the subset or exclude it.
// 3. At each index if we take its value we will reduce the target sum by the value of the element, and if we don't take the value we will keep the target sum as it is.
// 4. If the target sum becomes 0, we will return true.
// 5. If we reach the end of the array and the target sum is not 0, we will return false.
// 6. We will return the result of the recursive function for the two possibilities.

// RECURSIVE SOLUTION
#include <bits/stdc++.h>

bool helper(int i, int k, int sum, vector<int> &arr)
{
    // Base case
    if (i == arr.size())
    {
        return sum == k;
    }

    // including the ith number in sum
    bool take = helper(i + 1, k, sum + arr[i], arr);

    // excluding the ith number from sum
    bool notTake = helper(i + 1, k, sum, arr);

    // If none of the sequences summed up to k
    return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return helper(0, k, 0, arr);
}

// Time complexity: O(2^N)
// Space complexity: O(N)

// MEMOIZATION

// Recursive function to check if there exists a subset in the array with a sum equal to 'K'
bool helper(int i, int k, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (i == arr.size())
    {
        return sum == k;
    }

    // If the result for this state is already calculated, return it
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    // including the ith number in sum
    bool take = helper(i + 1, k, sum + arr[i], arr, dp);

    // excluding the ith number from sum
    bool notTake = helper(i + 1, k, sum, arr, dp);

    // Store the result in the dp table and return it
    return dp[i][sum] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return helper(0, k, 0, arr, dp);
}

// Time complexity: O(N*K)
// Space complexity: O(N*K)

// TABULATION

// Function to check if there exists a subset in the array with a sum equal to 'K'
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Create a DP table to store the results of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    // Base case: If the sum is 0, then there is always an empty subset
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    // Iterate through the array elements
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            // If the current element is greater than the sum, exclude it
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // Include the current element in the sum
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    // Return the result for the entire array
    return dp[n][k];
}

// Time complexity: O(N*K)
// Space complexity: O(N*K)

// SPACE OPTIMIZED TABULATION

// Function to check if there exists a subset in the array with a sum equal to 'K'
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Create a DP table to store the results of subproblems
    vector<bool> dp(k + 1, false);

    // Base case: If the sum is 0, then there is always an empty subset
    dp[0] = true;

    // Iterate through the array elements
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= arr[i]; j--)
        {
            // Include the current element in the sum
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    // Return the result for the entire array
    return dp[k];
}

// Time complexity: O(N*K)
// Space complexity: O(K)
