// Ways To Make Coin Change
// Problem statement
// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
// You need to figure out the total number of ways W, in which you can make a change for value V using
// coins of denominations from D. Print 0, if a change isn't possible.

// Link : https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471

// Approach
// We will follow a bottom up approach to solve this problem.
// We Will check if with the given denomination we can form the given money value.
// For each denomination, we will choose the take and not take approach.
// If we take the denomination, we will reduce the value by the denomination and check if we can form the remaining value with the same denomination.
// If we don't take the denomination, we will check if we can form the value with the remaining denominations.
// We will return the sum of the two possibilities.
// We will store the result in the dp table and return it.

// RECURSIVE MEMOIZED SOLUTION

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long helper(int *arr, int ind, int T, vector<vector<long>> &dp)
{
    // Base case: if we're at the first element
    if (ind == 0)
    {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }

    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];

    // Calculate the number of ways without taking the current element
    long notTaken = helper(arr, ind - 1, T, dp);

    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = helper(arr, ind, T - arr[ind], dp);

    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}

// Function to count the number of ways to make change for the target sum

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1)); // Create a DP table

    // Call the utility function to calculate the answer
    return helper(denominations, n - 1, value, dp);
}

// Time complexity: O(N*V)
// Space complexity: O(N*V) [dp array] + O(N) [stack space] = O(N*V)

// TABULATION

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0)); // Create a DP table

    // Initialize the base case: there is one way to make change for 0
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    // Loop through the denominations
    for (int i = 0; i < n; i++)
    {
        // Loop through the target sum
        for (int j = 1; j <= value; j++)
        {
            // Calculate the number of ways without taking the current element
            long notTaken = (i > 0) ? dp[i - 1][j] : 0;

            // Calculate the number of ways by taking the current element
            long taken = (denominations[i] <= j) ? dp[i][j - denominations[i]] : 0;

            // Store the sum of ways in the DP table
            dp[i][j] = notTaken + taken;
        }
    }

    // Return the result
    return dp[n - 1][value];
}

// Time complexity: O(N*V)
// Space complexity: O(N*V)

// SPACE OPTIMIZED TABULATION
// We can optimize the space complexity of the above tabulation solution by using previous and current 1D arrays instead of a 2D DP table.

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value + 1, 0); // Initialize the previous row
    vector<long> curr(value + 1, 0); // Initialize the current row

    // Initialize the base case: there is one way to make change for 0
    for (int i = 0; i < n; i++)
        prev[0] = 1;

    // Loop through the denominations
    for (int i = 0; i < n; i++)
    {
        // Loop through the target sum
        for (int j = 1; j <= value; j++)
        {
            // Calculate the number of ways without taking the current element
            long notTaken = (i > 0) ? prev[j] : 0;

            // Calculate the number of ways by taking the current element
            long taken = (denominations[i] <= j) ? curr[j - denominations[i]] : 0;

            // Store the sum of ways in the current row
            curr[j] = notTaken + taken;
        }

        // Copy the current row to the previous row for the next iteration
        prev = curr;
    }

    // Return the result
    return curr[value];
}