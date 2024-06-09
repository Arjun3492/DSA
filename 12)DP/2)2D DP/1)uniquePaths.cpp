// // Unique Paths
// Problem statement
// You are present at point ‘A’ which is the top-left cell of an M X N matrix,
// your destination is point ‘B’, which is the bottom-right cell of the same matrix.
// Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
// In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’,
// your task is to find the total number of unique paths from the cell MATRIX[0][0] to
// MATRIX['M' - 1]['N' - 1].

// To traverse in the matrix, you can either move Right or Down at each step.
// For example in a given point MATRIX[i][j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

// Link : https://www.naukri.com/code360/problems/total-unique-paths_1081470

//  APPRAOCH
//   1. We will use a recursive function to calculate the number of ways to reach the source from the destination(bottom-up).
//  2. We will take left and up as the two possible directions to move from the current cell.
//  3. On reaching the source, we will return 1.
//  4. If we go out of bounds or reach a blocked cell, we will return 0.

// RECURSIVE SOLUTION

#include <bits/stdc++.h>

// Recursive function to count the number of ways to reach (i, j) from (0, 0)
// in a grid of size m x n
int helper(int i, int j, vector<vector<int>> &dp)
{
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    // Calculate the number of ways by moving up and left recursively.
    int up = helper(i - 1, j, dp);
    int left = helper(i, j - 1, dp);

    // Store the result in the dp table and return it.
    return up + left;
}

int uniquePaths(int m, int n)
{
    return helper(m - 1, n - 1, dp);
}

// Time complexity: O(2^(m+n))
// Space complexity: O(m+n) , where m and n are the dimensions of the matrix.(Steps traversed in the recursion tree)

// MEMOIZATION

// Recursive function to count the number of ways to reach (i, j) from (0, 0)
// in a grid of size m x n
int helper(int i, int j, vector<vector<int>> &dp)
{
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    // If the result is already calculated, return it from the dp table.
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the number of ways by moving up and left recursively.
    int up = helper(i - 1, j, dp);
    int left = helper(i, j - 1, dp);

    // Store the result in the dp table and return it.
    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n)
{
    // Create a dp table to store the results of subproblems
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(m - 1, n - 1, dp);
}

// Time complexity: O(m*n)
// Space complexity: O(m*n) , where m and n are the dimensions of the matrix.

// TABULATION
// We will follow a top-down approach to fill the dp table.

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int uniquePaths(int m, int n)
{
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Base case: There is one way to reach the top-left cell (0, 0).
    dp[0][0] = 1;

    // Loop through the grid using two nested loops
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Base condition: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                continue; // Skip the rest of the loop and continue with the next iteration.
            }

            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
            if (i > 0)
                up = dp[i - 1][j];

            // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
            if (j > 0)
                left = dp[i][j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    }

    // The result is stored in the bottom-right cell (m-1, n-1).
    return dp[m - 1][n - 1];
}

// Time complexity: O(m*n)
// Space complexity: O(m*n) , where m and n are the dimensions of the matrix.

// SPACE OPTIMIZED TABULATION
//  We can optimize the space complexity of the tabulation approach by using a single array instead of a 2D array.
//  As we only need the values from the previous row to calculate the current row, we can use a single array to store these values.

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int uniquePaths(int m, int n)
{
    // Create a vector to represent the previous row of the grid.
    vector<int> prev(n, 0);

    // Base case: There is one way to reach the top-left cell (0, 0).
    prev[0] = 1;

    // Iterate through the rows of the grid.
    for (int i = 0; i < m; i++)
    {
        // Create a temporary vector to represent the current row.
        vector<int> temp(n, 0);

        // Iterate through the columns of the grid.
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the previous row.
            if (i > 0)
                up = prev[j];

            // If we are not at the first column (j > 0), update 'left' with the value from the current row.
            if (j > 0)
                left = temp[j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            temp[j] = up + left;
        }

        // Update the previous row with the values calculated for the current row.
        prev = temp;
    }

    // The result is stored in the last cell of the previous row (n-1).
    return prev[n - 1];
}
