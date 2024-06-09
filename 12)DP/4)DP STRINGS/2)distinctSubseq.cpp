// Distinct Subsequences
// Problem statement

// A Subsequence of a string is the string that is obtained by deleting 0
// or more letters from the string and keeping the rest of the letters in the same order.
// We are given two strings, 'str' and 'sub'.
// Find the number of subsequences of 'str' which are equal to 'sub'.
// Since the answer can be very large, print it modulo 10 ^ 9 + 7.

// Link : https://www.naukri.com/code360/problems/subsequence-counting_3755256

// Approach:
// In this problem, we are given two strings, 'str' and 'sub'.
// For each index pointer 'i' in the string 'str' and 'j' in the string 'sub',
// we have two choices:
// If the characters match, consider two options: EITHER leave one character in both str and sub
// OR leave one character in str and continue matching sub
// If the characters don't match, we can only leave one character in str and continue matching sub
// We will use a recursive approach to solve this problem.
// We will define a recursive function 'helper' that will take the following parameters:
// 'i' and 'j' representing the current index in the strings 'str' and 'sub', respectively
// 'str' and 'sub' representing the input strings
// 'dp' representing the memoization table to store the results of subproblems
// The base case for the recursive function will be:
// If the index 'j' reaches the end of the string 'sub', return 1
// If the index 'i' reaches the end of the string 'str', return 0

// RECURSIVE MEMOIZED APPROACH
#include <bits/stdc++.h>

using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of sub in str
int helper(string str, string sub, int ind1, int ind2,
           vector<vector<int>> &dp)
{
    // If sub has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;

    // If str has been completely traversed but sub hasn't, return 0
    if (ind1 < 0)
        return 0;

    // If the result for this state has already been calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character
    // in str and sub or leave one character in str and continue matching sub
    if (str[ind1] == sub[ind2])
    {
        int leaveOne = helper(str, sub, ind1 - 1, ind2 - 1, dp);
        int stay = helper(str, sub, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    }
    else
    {
        // If characters don't match, just leave one character in str and continue
        // matching sub
        result = helper(str, sub, ind1 - 1, ind2, dp);
    }

    // Store the result and return it
    dp[ind1][ind2] = result;
    return result;
}

// Function to count the number of distinct subsequences of sub in str

int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int lt = sub.size();
    int ls = str.size();
    vector<vector<int>> dp(ls, vector<int>(lt, -1));
    return helper(str, sub, ls - 1, lt - 1, dp);
}

// Time complexity: O(n*m)
// Space complexity: O(n*m)

// TABULATION APPROACH

int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int lt = sub.size();
    int ls = str.size();
    vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, 0));

    // Initialize the base cases
    for (int i = 0; i <= ls; i++)
    {
        dp[i][0] = 1;
    }

    // Fill the DP table in a bottom-up manner
    for (int i = 1; i <= ls; i++)
    {
        for (int j = 1; j <= lt; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the result
    return dp[ls][lt];
}

// Time complexity: O(n*m)
// Space complexity: O(n*m)

// SPACE OPTIMIZED TABULATION APPROACH

// If we need only two values from the prev row, there is no need to store an entire row.
// We can work a bit smarter.

// We can use the cur row itself to store the required value in the following way:

// We take a single row ‘prev’.
// We initialize it to the base condition.
// Whenever we want to compute a value of the cell prev[j], we take the already existing value (prev[j] before new computation) and prev[j-1] (if required, in case of character match).
// We perform the above step on all the indexes.
// So we see how we can space optimize using a single row itself.

#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m)
{
    // Create an array to store the count of distinct subsequences for each character in s2
    vector<int> prev(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = 1;

    // Iterate through s1 and s2 to calculate the counts
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        { // Iterate in reverse direction to avoid overwriting values prematurely
            if (s1[i - 1] == s2[j - 1])
            {
                // If the characters match, we have two options:
                // 1. Match the current characters and add to the previous count (prev[j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
            // No need for an else statement since we can simply leave the previous count as is
        }
    }

    // The value at prev[m] contains the count of distinct subsequences
    return prev[m];
}
