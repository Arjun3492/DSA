// Edit Distance
// Problem statement
// You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively.
// Find the "Edit Distance" between the strings.

// Edit Distance of two strings is the minimum number of steps required to make
// one string equal to the other. In order to do so, you can perform the following three operations:

// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character

// You need to find the minimum number of steps required to convert string 'S' to string 'T'.

// Link : https://www.naukri.com/code360/problems/edit-distance_630420

// APPROACH
// Since we can perform three operations, we will consider all three operations for each index pair if they are not matching
// Replace : reduce both the indices by 1
// Insert : reduce the index of string 'T' by 1 as we are inserting a character in string 'S' and we want to stay at the same index of string 'T'
// Delete : reduce the index of string 'S' by 1 as we are deleting a character from string 'S'

// RECURSIVE MEMOIZED APPROACH

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int helper(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{
    // Base cases
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match, no operation is needed
    if (S1[i] == S2[j])
        return dp[i][j] = 0 + helper(S1, S2, i - 1, j - 1, dp);

    // Minimum of three choices:
    // 1. Replace the character at S1[i] with the character at S2[j]
    // 2. Delete the character at S1[i]
    // 3. Insert the character at S2[j] into S1
    else
        return dp[i][j] = 1 + min(helper(S1, S2, i - 1, j - 1, dp),
                                  min(helper(S1, S2, i - 1, j, dp),
                                      helper(S1, S2, i, j - 1, dp)));
}

// Function to calculate the minimum number of operations required to transform S1 into S2
int editDistance(string S1, string S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Call the utility function with the last indices of both strings
    return helper(S1, S2, n - 1, m - 1, dp);
}

// Time complexity: O(N*M) where N and M are the lengths of the input strings S1 and S2, respectively.
// Space complexity: O(N*M) where N and M are the lengths of the input strings S1 and S2, respectively.

// TABULATION APPROACH

int editDistance(string S1, string S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    // Fill the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If the characters at the current positions match, no operation is needed
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // Minimum of three choices:
            // 1. Replace the character at S1[i] with the character at S2[j]
            // 2. Delete the character at S1[i]
            // 3. Insert the character at S2[j] into S1
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                   min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // Return the result
    return dp[n][m];
}

// Time complexity: O(N*M) where N and M are the lengths of the input strings S1 and S2, respectively.
// Space complexity: O(N*M) where N and M are the lengths of the input strings S1 and S2, respectively.

// SPACE OPTIMIZED TABULATION APPROACH

int editDistance(string S1, string S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to store the results of subproblems
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    // Initialize the base cases
    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }

    // Fill the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            // If the characters at the current positions match, no operation is needed
            if (S1[i - 1] == S2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            // Minimum of three choices:
            // 1. Replace the character at S1[i] with the character at S2[j]
            // 2. Delete the character at S1[i]
            // 3. Insert the character at S2[j] into S1
            else
            {
                curr[j] = 1 + min(prev[j - 1],
                                  min(prev[j], curr[j - 1]));
            }
        }
        prev = curr;
    }

    // Return the result
    return curr[m];
}
