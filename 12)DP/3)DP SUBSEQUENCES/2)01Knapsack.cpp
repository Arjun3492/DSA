// 0/1 Knapsack
// Problem statement
// A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack.
// There are 'N' items available in the store and the weight and value of each item is
// known to the thief. Considering the constraints of the maximum weight that a knapsack
// can carry, you have to find the maximum profit that a thief can generate by stealing items.

// Note: The thief is not allowed to break the items.

// Link : https://www.naukri.com/code360/problems/0-1-knapsack_1072980

// Approach
// 1. We will use a recursive function to calculate the maximum profit that a thief can generate by stealing items.
// 2. We will consider two possibilities for each item: either include it in the knapsack or exclude it.
// 3. If the weight of the current item is less than or equal to the remaining weight of the knapsack, we will calculate the profit by including the item in the knapsack.
// 4. If the weight of the current item is greater than the remaining weight of the knapsack, we will exclude the item from the knapsack.
// 5. We will return the maximum profit generated by the two possibilities.
// 6. We will store the result in the dp table and return it.

// RECURSIVE MEMOIZED SOLUTION

// Function to solve the 0/1 Knapsack problem using memoization
int helper(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (ind == -1 || W == 0)
    {
        return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    // Calculate the maximum value by either excluding the current item or including it
    int notTaken = helper(wt, val, ind - 1, W, dp);
    int taken = 0;

    // Check if the current item can be included without exceeding the knapsack's capacity
    if (wt[ind] <= W)
    {
        taken = val[ind] + helper(wt, val, ind - 1, W - wt[ind], dp);
    }

    // Store the result in the DP table and return
    return dp[ind][W] = max(notTaken, taken);
}

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return helper(wt, val, n - 1, W, dp);
}

// Time complexity: O(N*W)
// Space complexity: O(N*W) [dp array] + O(N) [stack space] = O(N*W)

// TABULATION

// Function to solve the 0/1 Knapsack problem using tabulation
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Initialize the DP table with base cases
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
        }
    }

    // Fill the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            // If the weight of the current item is less than or equal to the remaining weight of the knapsack
            if (wt[i - 1] <= w)
            {
                // Calculate the maximum value by either excluding the current item or including it
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                // Exclude the current item if its weight exceeds the remaining weight of the knapsack
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum profit that can be generated
    return dp[n][W];
}

// Time complexity: O(N*W)
// Space complexity: O(N*W)

// SPACE OPTIMIZED TABULATION

// Function to solve the 0/1 Knapsack problem using tabulation with space optimization
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    vector<int> dp(W + 1, 0);

    // Fill the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = W; w >= wt[i - 1]; w--)
        {
            // Calculate the maximum value by either excluding the current item or including it
            dp[w] = max(dp[w], val[i - 1] + dp[w - wt[i - 1]]);
        }
    }

    // Return the maximum profit that can be generated
    return dp[W];
}

// Time complexity: O(N*W)
// Space complexity: O(W)
