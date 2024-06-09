//// We will understand the memoization and tabulation approach to solve problems based on DP on STRINGS.

// RECURRENCE
// Steps to convert a problem to reccurence
// 1.Try to represent the problem in terms of indexes. [fn(i,j)]
// 2. Try all possible choices/ways at every index according to the problem statement.[Match and not match state]
// 3. If the question states
// Count all the ways - return sum of all choices/ways. [fn(i,j) = ch1 + ch2]
// Find maximum/minimum- return the choice/way with maximum/minimum output. [fn(i,j) = max(ch1,ch2)]

// Let us consider the example of the DP on STRINGS to understand the memoization and tabulation approach.

// MEMOIZATION
//  To convert a recursive solution to a memoized solution, we will follow the following steps:
//  i. Create a memoization array to store the results of the subproblems.
//  ii. Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
//  iii. If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
//  iv. Return the result.

int fn(int i, int j, string &s1, string &s2, vector<vector<int>> &memo)
{
    // Base case
    if (i == 0 || j == 0)
    {
        return 0;
    }

    // Step 2: Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    // Step 3: If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
    if (s1[i - 1] == s2[j - 1])
    {
        return memo[i][j] = 1 + fn(i - 1, j - 1, s1, s2, memo);
    }
    else
    {
        return memo[i][j] = max(fn(i - 1, j, s1, s2, memo), fn(i, j - 1, s1, s2, memo));
    }
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();
    // Step 1 : Create a memoization array to store the results of the subproblems.
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    cout << fn(m, n, s1, s2, memo) << endl;
    return 0;
}

// TABULATION
// To convert a recursive solution to a tabulated solution, we will follow the following steps:
// i. Create a tabulation array to store the results of the subproblems.
// ii. Initialize the base cases in the tabulation array.
// iii. Fill the tabulation array in a bottom-up manner.
// iv. Return the result.

int fn(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();
    // Create a tabulation array to store the results of the subproblems.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the base cases in the tabulation array.
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // Fill the tabulation array in a bottom-up manner.
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
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
    return dp[m][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << fn(s1, s2) << endl;
    return 0;
}

// The above code snippet demonstrates the memoization and tabulation approach to solve the longest common subsequence problem using dynamic programming on strings. The memoization approach uses a 2D memoization array to store the results of the subproblems, while the tabulation approach uses a 2D DP table to store the results of the subproblems. Both approaches have a time complexity of O(m*n) and a space complexity of O(m*n), where m and n are the lengths of the input strings s1 and s2, respectively.
