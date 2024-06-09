// Longest Common Subsequence
// Problem statement
// You have been given two Strings “STR1” and “STR2” of characters.
// Your task is to find the length of the longest common subsequence.

// A String ‘a’ is a subsequence of a String ‘b’ if ‘a’ can be obtained from ‘b’ by deletion
// of several (possibly, zero or all) characters. A common subsequence of two Strings is a
// subsequence that is common to both Strings.

// Link : https://www.naukri.com/code360/problems/longest-common-subsequence_1063255

// Approach:
// To follow problem based on dp strings
// We will express the problem in terms of indexes
// Will will have a match and a mismatch case in the problem and call for subproblems

// RECURSIVE MEMOIZED APPROACH

#include <bits/stdc++.h>

using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int helper(string &s1, string &s2, int ind1, int ind2,
           vector<vector<int>> &dp)
{
    // Base case: If either string reaches the end, return 0
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // If the result for this pair of indices is already calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // MATCH CONDITION: If the characters at the current indices match, increment
    // the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + helper(s1, s2, ind1 - 1, ind2 - 1, dp);
    // NOT MATCH CONDITION
    else
        // If the characters don't match, consider two options: moving either left
        // or up in the strings
        return dp[ind1][ind2] = max(helper(s1, s2, ind1, ind2 - 1, dp),
                                    helper(s1, s2, ind1 - 1, ind2, dp));
}

// Function to calculate the length of the Longest Common Subsequence

int getLengthOfLCS(string &s1, string &s2)
{
    // Write your code here.
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
    return helper(s1, s2, n - 1, m - 1, dp);
}

// Time Complexity: O(n*m), where n and m are the lengths of the input strings s1 and s2, respectively.
// Space Complexity: O(n*m), where n and m are the lengths of the input strings s1 and s2, respectively.

// TABULATION APPROACH
// To convert a recursive solution to a tabulated solution, we will follow the following steps:
// i. Create a tabulation array to store the results of the subproblems.
// ii. Initialize the base cases in the tabulation array. (since we can't express negative indexes in tabulation, we will do a 1 based indexing)
// iii. Fill the tabulation array in a bottom-up manner.
// iv. Return the result.

int getLengthOfLCS(string &s1, string &s2)
{
    // Write your code here.
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Create a DP table

    // Initialize the base cases in the tabulation array.

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    // Fill the tabulation array in a bottom-up manner.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1]) // left shift by 1, as we have taken 1 based indexing
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the result.
    return dp[n][m];
}

// Time Complexity: O(n*m), where n and m are the lengths of the input strings s1 and s2, respectively.
// Space Complexity: O(n*m), where n and m are the lengths of the input strings s1 and s2, respectively.

// SPACE OPTIMIZED TABULATION APPROACH
// We will use a prev and a curr array to store the results of the subproblems.
// prev= dp[i-1]
// curr= dp[i]

int getLengthOfLCS(string &s1, string &s2)
{
    // Write your code here.
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0); // Create a DP table
    vector<int> curr(m + 1, 0); // Create a DP table

    // Fill the tabulation array in a bottom-up manner.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1]) // left shift by 1, as we have taken 1 based indexing
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    // Return the result.
    return curr[m];
}
