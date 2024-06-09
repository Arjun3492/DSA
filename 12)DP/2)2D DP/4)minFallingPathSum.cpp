// Minimum Falling Path Sum
// Problem statement
// You have been given a square array 'VEC' of integers of size 'N' rows and 'N' columns.
// Your task is to find the minimum sum of a falling path through the square array.
// The number of rows and columns in the given array will be the same.

// A falling path starts at any element in the first row and chooses one element from each row.
// The next row's choice must be in a column that is different from the previous row's column by
// at most one.

// Link : https://www.naukri.com/code360/problems/minimum-falling-path-sum_893012

// Approach
// 1. For each cell in the first row, we will find the minimum sum of the falling path starting from that cell.
// 2. We will use a recursive function to calculate the minimum sum of the falling path starting from the current cell.
// 3. We will return the minimum sum of the falling path starting from the current cell by considering the three possible directions to move in the next row.
// 4. We will store the result in the dp table and return it.
// 5. We will return the minimum of the three possible directions at each cell.

// RECURSIVE MEMOIZED SOLUTION

#include <bits/stdc++.h>

// Function to recursively find the minimum path sum for a given cell
int helper(int i, int j, int m, vector<vector<int>> &matrix,
           vector<vector<int>> &dp)
{
    // Base Conditions
    if (j < 0 || j >= m)
        return 1e9; // A very large  value to represent an invalid path
    if (i == 0)
        return matrix[0][j]; // The minimum path sum for the top row is the value
                             // itself

    if (dp[i][j] != -1)
        return dp[i][j]; // If the result for this cell is already calculated,
                         // return it

    // Calculate the minimum path sum by considering three possible directions:
    // up, left diagonal, and right diagonal
    int up = matrix[i][j] + helper(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + helper(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + helper(i - 1, j + 1, m, matrix, dp);

    // Store the minimum of the three paths in dp
    return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
}
int minFallingPathSum(vector<vector<int>> &matrix, int n)
{

    int m = matrix[0].size(); // Number of columns in the matrix

    // Memoization table to store computed results

    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Initialize the maximum path sum to a very small value
    int mini = INT_MAX;

    // Iterate through each cell in the first row to find the maximum path sum
    // starting from each of them
    for (int j = 0; j < m; j++)
    {
        // Calculate the maximum path sum for the last row

        int ans = helper(n - 1, j, m, matrix, dp);

        // Update the maximum path sum if a larger one is found
        mini = min(mini, ans);
    }

    return mini; // Return the maximum path sum
}

// Time complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix
// Space complexity: O(N*M) for the memoization table

// TABULATION

// Function to find the minimum falling path sum in the given matrix
int minFallingPathSum(vector<vector<int>> &matrix, int n)
{
    int m = matrix[0].size(); // Number of columns in the matrix

    // Create a DP table to store the minimum falling path sum for each cell
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the DP table with the values from the first row
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    // Iterate through the remaining rows to calculate the minimum falling path sum
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Calculate the minimum falling path sum for the current cell
            dp[i][j] = matrix[i][j] + dp[i - 1][j];

            // Check the left diagonal cell
            if (j > 0)
                dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]);

            // Check the right diagonal cell
            if (j < m - 1)
                dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]);
        }
    }

    // Find the minimum falling path sum in the last row
    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }

    return mini; // Return the minimum falling path sum
}

// Time complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix
// Space complexity: O(N*M) for the DP table

// SPACE OPTIMIZED TABULATION

// Function to find the minimum falling path sum in the given matrix
int minFallingPathSum(vector<vector<int>> &matrix, int n)
{
    int m = matrix[0].size(); // Number of columns in the matrix

    // Create two arrays to store the minimum falling path sum for the current and previous rows
    vector<int> curr(m, 0);
    vector<int> prev(m, 0);

    // Initialize the DP arrays with the values from the first row
    for (int j = 0; j < m; j++)
    {
        curr[j] = matrix[0][j];
    }

    // Iterate through the remaining rows to calculate the minimum falling path sum
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Calculate the minimum falling path sum for the current cell
            curr[j] = matrix[i][j] + curr[j];

            // Check the left diagonal cell
            if (j > 0)
                curr[j] = min(curr[j], matrix[i][j] + prev[j - 1]);

            // Check the right diagonal cell
            if (j < m - 1)
                curr[j] = min(curr[j], matrix[i][j] + prev[j + 1]);
        }

        // Update the previous row with the values from the current row
        prev = curr;
    }

    // Find the minimum falling path sum in the last row
    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, curr[j]);
    }

    return mini; // Return the minimum falling path sum
}
