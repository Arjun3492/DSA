// Matrix Chain Multiplication
// Problem statement
// Given a chain of matrices A1, A2, A3,.....An.
// Your task is to find out the minimum cost to multiply these matrices.
// The cost of matrix multiplication is defined as the number of scalar multiplications.
// A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’
// where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.

// For example:
// For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

// Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

// Link : https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344

// APPROACH:
// We will use a recursive helper function to solve this problem.
// The helper function will take the array of matrices, the starting index, and the ending index as input.
// At first we will start with taking the entire matrix as a whole and then keep on dividing it into two parts and find the best possible answer.
// We will run a loop to try all possible partitions and then take the best possible answer of the two partitions.
// We will return the answer.
// We will memoize the results of the subproblems to avoid recomputation.

// NOTE: A two matrices of dimensions a*b and b*c can be multiplied in a*b*c scalar multiplications.

#include <bits/stdc++.h>
using namespace std;

// f(arr,i,j,dp) returns the minimum cost to multiply the matrices from i to j (both inclusive)
// where i is the ith matrix and j is the jth matrix
int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{

    // base condition, single matrix
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {
        int currentCost = arr[i - 1] * arr[k] * arr[j];
        // currentCost + cost of the left partition + cost of the right partition
        int ans = currentCost + f(arr, i, k, dp) + f(arr, k + 1, j, dp);

        mini = min(mini, ans);
    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{

    vector<vector<int>> dp(N, vector<int>(N, -1));

    // i is the ith matrix and j is the jth matrix
    // dimensions of ith matrix = arr[i-1]*arr[i]
    // dimensions of jth matrix = arr[j-1]*arr[j]
    int i = 1;
    int j = N - 1;

    return f(arr, i, j, dp);
}

// Time complexity: O(N^3)
// Reason: There are N*N states and we explicitly run a loop
// inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

// Space complexity: O(N^2)
// Reason: We are using an auxiliary recursion stack space(O(N))and a 2D array ( O(N*N)).

// TABULATION APPROACH

// Function to find the minimum number of operations for matrix multiplication
int matrixMultiplication(vector<int> &arr, int N)
{
    // Create a DP table to store the minimum number of operations
    vector<vector<int>> dp(N, vector<int>(N, -1));

    // Initialize the diagonal elements of the DP table to 0
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    // Loop for the length of the chain
    for (int len = 2; len < N; len++)
    {
        for (int i = 1; i < N - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try different partition points to find the minimum
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}

// Time Complexity: O(N*N*N)

// Reason: There are N*N states and we explicitly run a loop inside the function
// which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

// Space Complexity: O(N*N)

// Reason: We are using a 2D array ( O(N*N)) space.