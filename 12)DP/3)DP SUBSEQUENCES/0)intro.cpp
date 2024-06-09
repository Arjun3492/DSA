//// We will understand the memoization and tabulation approach to solve problems based on DP on Subsqeuences.

// RECURRENCE
// Steps to convert a problem to reccurence
// 1.Try to represent the problem in terms of index and target. [fn(i,target)]
// 2. Try all possible choices/ways at every index according to the problem statement. [(take or not take i)]
// 3. Return true if the target is achieved else return false. [fn(i,target) = ch1 || ch2]

// Let us consider the example of the DP on Subsequences to understand the memoization and tabulation approach.

// MEMOIZATION
//  To convert a recursive solution to a memoized solution, we will follow the following steps:
//  i. Create a memoization array to store the results of the subproblems.
//  ii. Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
//  iii. If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
//  iv. Return the result.

bool fn(int i, int target, vector<int> &nums, vector<vector<int>> &memo)
{
    // Base case
    if (target == 0)
    {
        return true;
    }
    if (i < 0)
    {
        return false;
    }

    // Step 2: Check if the result of the subproblem is already stored in the memoization array. If yes, return the result.
    if (memo[i][target] != -1)
    {
        return memo[i][target];
    }

    // Step 3: If the result is not stored in the memoization array, calculate the result and store it in the memoization array.
    bool take = false, not_take = false;
    if (nums[i] <= target)
    {
        take = fn(i - 1, target - nums[i], nums, memo);
    }
    not_take = fn(i - 1, target, nums, memo);
    return memo[i][target] = take || not_take;
}

int main()
{
    vector<int> nums = {2, 3, 7, 8};
    int target = 11;
    // Step 1 : Create a memoization array to store the results of the subproblems.
    vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
    cout << fn(nums.size() - 1, target, nums, memo) << endl;
    return 0;
}

// TABULATION
// To convert a recursive solution to a tabulated solution, we will follow the following steps:
// i. Create a DP table to store the results of the subproblems.
// ii. Initialize the base cases of the DP table.
// iii. Iterate over the DP table in a bottom-up manner to fill the table.
// iv. Return the result from the DP table.

bool fn(int target, vector<int> &nums)
{
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: If the target is 0, we can achieve it by not selecting any element
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}
