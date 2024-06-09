// Rod cutting problem
// Problem statement
// Given a rod of length ‘N’ units. The rod can be cut into different sizes and
// each size has a cost associated with it. Determine the maximum cost obtained
// by cutting the rod and selling its pieces.

// Note:
// 1. The sizes will range from 1 to ‘N’ and will be integers.
// 2. The sum of the pieces cut should be equal to ‘N’.
// 3. Consider 1-based indexing.

// Link :https://www.naukri.com/code360/problems/rod-cutting-problem_800284

// APPROACH
//  We will follow a bottom up approach and will try to find the maximum cost
//  We will try to form the rod of the given length using the given pieces
//  For each piece lenght we will follow the take and not take approach
//  If we take the piece then we will add the cost of the piece and will reduce the length of the rod by the length of the piece
//  If we do not take the piece then we will not add the cost of the piece and will not reduce the length of the rod
//  Base case will be when the length of the rod is 1 then the cost will be (current Length of rod * cost of the piece of length 1)

// RECURSIVE MEMOIZED APPROACH
#include <bits/stdc++.h>
using namespace std;

// Function to solve the rod cutting problem using dynamic programming
int helper(int currentIndex, int rodLength, vector<int> &pricePerLength, vector<vector<int>> &dpTable)
{
    // Base case: if we're at the first length
    if (currentIndex == 0)
    {
        // Calculate and return the maximum revenue for the given rod length
        return rodLength * pricePerLength[0];
    }

    // If the result for this index and rod length is already calculated, return it
    if (dpTable[currentIndex][rodLength] != -1)
    {
        return dpTable[currentIndex][rodLength];
    }

    // Calculate the maximum revenue without cutting the current length
    int revenueWithoutCutting = 0 + helper(currentIndex - 1, rodLength, pricePerLength, dpTable);

    // Calculate the maximum revenue by cutting the current length
    int revenueWithCutting = INT_MIN;
    int currentLength = currentIndex + 1;
    if (currentLength <= rodLength)
    {
        revenueWithCutting = pricePerLength[currentIndex] + helper(currentIndex, rodLength - currentLength, pricePerLength, dpTable);
    }

    // Store the maximum revenue in the DP table and return it
    return dpTable[currentIndex][rodLength] = max(revenueWithoutCutting, revenueWithCutting);
}

int cutRod(vector<int> &pricePerLength, int rodLength)
{
    // Create a DP table
    vector<vector<int>> dpTable(rodLength, vector<int>(rodLength + 1, -1));

    // Call the utility function to calculate the maximum revenue
    return helper(rodLength - 1, rodLength, pricePerLength, dpTable);
}

// Time complexity: O(N*N) using memoization
// Space complexity: O(N*N) where N is the length of the rod

// TABULATION APPROACH

int cutRod(vector<int> &pricePerLength, int rodLength)
{
    // Create a DP table
    vector<vector<int>> dpTable(rodLength, vector<int>(rodLength + 1, 0));

    // Initialize the base cases
    for (int i = 0; i < rodLength; i++)
    {
        dpTable[i][0] = 0;
    }

    // Fill the DP table in a bottom-up manner
    for (int i = 0; i < rodLength; i++)
    {
        for (int j = 1; j <= rodLength; j++)
        {
            int revenueWithoutCutting = 0;
            if (i > 0)
            {
                revenueWithoutCutting = dpTable[i - 1][j];
            }

            int revenueWithCutting = INT_MIN;
            int currentLength = i + 1;
            if (currentLength <= j)
            {
                revenueWithCutting = pricePerLength[i] + dpTable[i][j - currentLength];
            }

            dpTable[i][j] = max(revenueWithoutCutting, revenueWithCutting);
        }
    }

    // Return the maximum revenue
    return dpTable[rodLength - 1][rodLength];
}

// Time complexity: O(N*N) using tabulation
// Space complexity: O(N*N) where N is the length of the rod

// SPACE OPTIMIZED TABULATION APPROACH
// We will use a 1D dp array to store the maximum cost for each length of the rod
int cutRod(vector<int> &pricePerLength, int rodLength)
{
    // Create a DP table
    vector<int> dpTable(rodLength + 1, 0);

    // Fill the DP table in a bottom-up manner
    for (int i = 1; i <= rodLength; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dpTable[i] = max(dpTable[i], pricePerLength[j] + dpTable[i - j - 1]);
        }
    }

    // Return the maximum revenue
    return dpTable[rodLength];
}
