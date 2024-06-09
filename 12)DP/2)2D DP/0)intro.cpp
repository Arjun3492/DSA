// We will understand the memoization and tabulation approach to solve problems based on 2D DP.

// RECURRENCE
// Steps to convert a problem to reccurence
// 1.Try to represent the problem in terms of indexes. [fn(i,j)]
// 2. Try all possible choices/ways at every index according to the problem statement.
// 3. If the question states
// Count all the ways - return sum of all choices/ways. [fn(i,j) = ch1 + ch2]
// Find maximum/minimum- return the choice/way with maximum/minimum output. [fn(i,j) = max(ch1,ch2)]

// Let us consider the example of the 2D DP to understand the memoization and tabulation approach.

// MEMOIZATION
//  To convert a recursive solution to a memoized solution, we will follow the following steps:
//  i. Create a memoization array to store the results of the subproblems.
//  ii. Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
//  iii. If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
//  iv. Return the result.

int fn(int i, int j, vector<vector<int>> &memo)
{
    // Base case
    if (i == 0 && j == 0)
    {
        return 1;
    }

    // Step 2: Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    // Step 3: If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
    int left = 0, right = 0;
    if (i > 0)
    {
        left = fn(i - 1, j, memo);
    }
    if (j > 0)
    {
        right = fn(i, j - 1, memo);
    }
    return memo[i][j] = left + right;

    // The  steps 3-4 can be combined into a single line as follows:
    // return memo[i][j] = (i > 0 ? fn(i - 1, j, memo) : 0) + (j > 0 ? fn(i, j - 1, memo) : 0);
}

int main()
{
    int m = 3, n = 3;
    // Step 1 : Create a memoization array to store the results of the subproblems.
    vector<vector<int>> memo(m, vector<int>(n, -1));
    cout << fn(m - 1, n - 1, memo) << endl;
    return 0;
}

// TABULATION
// To convert a recursive solution to a tabulated solution, we will follow the following steps:
// i. Create a tabulation array to store the results of the subproblems.
// ii. Initialize the base cases in the tabulation array.
// iii. Iterate over the subproblems in a bottom-up manner and calculate the result for each subproblem.
// iv. Return the result.

int fn(int m, int n)
{
    // Step 1: Create a tabulation array to store the results of the subproblems.
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Step 2: Initialize the base cases in the tabulation array.
    dp[0][0] = 1;

    // Step 3: Iterate over the subproblems in a bottom-up manner and calculate the result for each subproblem.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    // Step 4: Return the result.
    return dp[m - 1][n - 1];
}