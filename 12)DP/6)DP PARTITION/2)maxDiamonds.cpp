//  Mining Diamonds
// Problem statement
// There are ‘N’ diamonds in a mine. The size of each diamond is given in the
// form of integer array ‘A’. If the miner mines a diamond, then he gets 'size
// of previous unmined diamond * size of currently mined diamond * size of next unmined diamond'
// number of coins. If there isn’t any next or previous unmined diamond then their size is
// replaced by 1 while calculating the number of coins.

// Vladimir, a dumb miner was assigned the task to mine all diamonds. Since he is dumb he
// asks for your help to determine the maximum number of coins that he can earn by mining
// the diamonds in an optimal order.

// I.E. The cost of mining the ith diamond is A[i-1]*A[i]*A[i+1].

// Approach
//  1. Start with the entire block/array and mark it with i,j. We need to find the value of f(i,j).
//  2. Run a loop to try all partitions. (Place partition between i and j)
//  3. Run the best possible answer of the two partitions ( answer that comes after dividing the problem into two subproblems and solving them recursively).

#include <bits/stdc++.h>

using namespace std;

// Recursive function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxCoins = INT_MIN;

    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++)
    {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];

        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);

        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }

    return dp[i][j] = maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // Create a DP array for memoization
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums, dp);
}

// Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
// Space Complexity: O(N2) + Auxiliary stack space of O(N), N2 for the dp array we are using.

// TABULATION

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // Create a DP array for tabulation
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Iterate over the length of the subarray
    for (int len = 1; len <= n; len++)
    {
        // Iterate over the starting index of the subarray
        for (int i = 1; i <= n - len + 1; i++)
        {
            // Calculate the ending index of the subarray
            int j = i + len - 1;

            // Iterate through each possible balloon to burst last
            for (int k = i; k <= j; k++)
            {
                // Calculate the coins obtained by bursting the k-th balloon last
                int coins = nums[i - 1] * nums[k] * nums[j + 1];

                // Update the maximum coins
                dp[i][j] = max(dp[i][j], coins + dp[i][k - 1] + dp[k + 1][j]);
            }
        }
    }

    return dp[1][n];
}

// Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
// Space Complexity: O(N2), N2 for the dp array we are using.

// SPACE OPTIMIZED TABULATION

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // Create a DP array for tabulation
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Iterate over the length of the subarray
    for (int len = 1; len <= n; len++)
    {
        // Iterate over the starting index of the subarray
        for (int i = 1; i <= n - len + 1; i++)
        {
            // Calculate the ending index of the subarray
            int j = i + len - 1;

            // Iterate through each possible balloon to burst last
            for (int k = i; k <= j; k++)
            {
                // Calculate the coins obtained by bursting the k-th balloon last
                int coins = nums[i - 1] * nums[k] * nums[j + 1];

                // Update the maximum coins
                dp[i][j] = max(dp[i][j], coins + dp[i][k - 1] + dp[k + 1][j]);
            }
        }
    }

    return dp[1][n];
}
