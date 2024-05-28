// Maximum sum of non-adjacent elements
// Problem statement
// You are given an array/list of ‘N’ integers.
// You are supposed to return the maximum sum of the subsequence with the
// constraint that no two elements are adjacent in the given array/list.

// Example
// Input : arr = [3, 2, 5, 10, 7]
// Output :15
// Explanation
// The maximum sum of the subsequence is 15, which is the sum of 3, 5, and 7.

// Link : https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

// BASIC RECURSIVE APPROACH

int helper(vector<int> &nums, int i)
{

    // Base case: If reached 0th element
    if (i == 0)
        return nums[0];
    // Base case:If taken 1 index and reached -1 by skipping 0
    if (i == -1)
        return 0;

    // element at ith index taken and skipping the adj element
    int take_idx = nums[i] + helper(nums, i - 2);
    // element at ith index not taken and moving to adjacent element
    int not_take_idx = 0 + helper(nums, i - 1);

    return max(take_idx, not_take_idx);
}

int maxSumNonAdjacent(vector<int> &nums)
{
    return helper(nums, nums.size() - 1);
}

// MEMOIZATION

int helperMemo(vector<int> &nums, int i, vector<int> &memo)
{

    // Base case: If reached 0th element
    if (i == 0)
        return nums[0];
    // Base case:If taken 1 index and reached -1 by skipping 0
    if (i == -1)
        return 0;

    // Return memoized result if already computed
    if (memo[i] != -1)
        return memo[i];

    // element at ith index taken and skipping the adj element
    int take_idx = nums[i] + helperMemo(nums, i - 2, memo);
    // element at ith index not taken and moving to adjacent element
    int not_take_idx = 0 + helperMemo(nums, i - 1, memo);

    return memo[i] = max(take_idx, not_take_idx);
}

int maxSumNonAdjacent(vector<int> &nums)
{
    vector<int> memo(nums.size(), -1);
    return helperMemo(nums, nums.size() - 1, memo);
}

// TABULATION

int maxSumNonAdjacent(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int take_idx = nums[i] + dp[i - 2];

        int not_take_idx = 0 + dp[i - 1];

        dp[i] = max(take_idx, not_take_idx);
    }

    return dp[n - 1];
}

// Time complexity: O(n)
// Space complexity: O(n)

// SPACE OPTIMIZED TABULATION

int maxSumNonAdjacent(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int take_idx = nums[i] + prev2;

        int not_take_idx = prev1;

        prev2 = prev1;
        prev1 = max(take_idx, not_take_idx);
    }

    return prev1;
}