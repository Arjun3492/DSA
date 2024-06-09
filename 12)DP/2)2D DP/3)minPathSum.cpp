// Minimum Path Sum
// Problem statement
// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N'
// rows and 'M' columns. Each point in the grid has some cost associated with it.

// Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1)
// which minimizes the sum of the cost of all the numbers along the path. You need to
// tell the minimum sum of that path.

// Link : https://www.naukri.com/code360/problems/minimum-path-sum_985349

// Approach
//  1. We will use a recursive function to calculate the minimum sum of the path from the bottom-right cell to the top-left cell.(bottom-up)
//  2. We will take up and left as the two possible directions to move from the current cell.
//  3. On reaching the destination, we will return the cost of the current cell.
//  4. If we go out of bounds, we will return 1e9.
//  5. At each cell, we will add its cost and call the recursive function for the two possible directions.
//  6. We will return the minimum of the two directions at each cell.

// RECURSIVE MEMOIZED SOLUTION

#include <bits/stdc++.h>
using namespace std;

// Helper function to find the minimum sum path from (i, j) to (N-1, M-1) in the
// matrix
int helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base cases

    // If we are at the top-left corner, the minimum path sum is the value at (0, 0) considering this path
    if (i == 0 && j == 0)
        return matrix[0][0];

    // If we go out of bounds, return a large value
    if (i < 0 || j < 0)
        return 1e9; // Not returing INT_MAX as we are adding the value of the cell to the result, and INT_MAX + cell value will overflow

    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + helper(i - 1, j, matrix, dp);
    int left = matrix[i][j] + helper(i, j - 1, matrix, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, grid, dp);
}

// Time complexity: O(N*M) ,[without memoization O(2^(N+M)) ]
// Space complexity: O(N*M) [dp array] + O((N-1)+(M-1)) [stack space] = O(N*M)

// TABULATION

// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else
            {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}

// Time complexity: O(N*M)
// Space complexity: O(N*M) [dp array]

// SPACE OPTIMIZED TABULATION
//  We can optimize the space complexity of the tabulation approach by using a single array instead of a 2D DP table.
//  as we are only using the previous row to calculate the current row, we can use a prev and curr array to store the values of the previous and current row respectively.

// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<int> prev(m, 0); // Initialize a vector to store the minimum path sum of the previous row

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0); // Initialize a vector to store the minimum path sum of the current row

        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else
            {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += curr[j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in curr[j]
                curr[j] = min(up, left);
            }
        }

        // Update the prev array with the values of the current row
        prev = curr;
    }

    // The final result is stored in the last element of the prev array
    return prev[m - 1];
}

// Time complexity: O(N*M)
// Space complexity: O(M) [prev array] + O(M) [curr array] = O(M)