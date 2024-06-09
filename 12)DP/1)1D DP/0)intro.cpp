// We will understand the memoization and tabulation approach of the fibonacci series

// RECURSION
//   Steps to convert a problem to reccurence
//  1.Try to represent the problem in terms of indexes.
//  2. Try all possible choices/ways at every index according to the problem statement.
//  3. If the question states
//  Count all the ways - return sum of all choices/ways.
//  Find maximum/minimum- return the choice/way with maximum/minimum output.

// Let us consider the example of the fibonacci series to understand the memoization and tabulation approach.

// 1. Memoization is a top-down approach where we store the result of the subproblems in an array and use them when needed.

// To convert a recursive solution to a memoized solution, we will follow the following steps:
// i. Create a memoization array to store the results of the subproblems.
// ii. Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
// iii. If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
// iv. Return the result.

int fib(int n, vector<int> &memo)
{
    // Base case
    if (n <= 1)
    {
        return n;
    }

    // Step 2: Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
    if (memo[n] != -1)
    {
        return memo[n];
    }

    // Step 3: If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

    // Step 4: Return the result.
    return memo[n];

    // The  steps 3-4 can be combined into a single line as follows:
    // return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}

int main()
{
    int n = 10;
    // Step 1 : Create a memoization array to store the results of the subproblems.
    vector<int> memo(n + 1, -1);
    cout << fib(n, memo) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) + O(n)[recusive stack space] = O(n)

// 2. Tabulation is a bottom-up approach where we start solving the problem from the smallest subproblem(Base case) and build up the solution for larger subproblems.

// To convert a recursive solution to a tabulated solution, we will follow the following steps:
// i. Create a tabulation array to store the results of the subproblems.
// ii. Initialize the base cases in the tabulation array.
// iii. Iterate over the subproblems in a bottom-up manner and calculate the result for each subproblem.
// iv. Return the result.

int fib(int n)
{
    // Step 1: Create a tabulation array to store the results of the subproblems.
    vector<int> dp(n + 1, 0);

    // Step 2: Initialize the base cases in the tabulation array.
    dp[0] = 0;
    dp[1] = 1;

    // Step 3: Iterate over the subproblems in a bottom-up manner and calculate the result for each subproblem.
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Step 4: Return the result.
    return dp[n];
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// Space optimization for tabulation approach
// We can optimize the space complexity of the tabulation approach by using only two variables to store the results of the subproblems instead of using an array.

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int first = 0, second = 1, curr;
    for (int i = 2; i <= n; i++)
    {
        curr = first + second;
        first = second;
        second = curr;
    }

    return curr;
}

// Time Complexity: O(n)
// Space Complexity: O(1)