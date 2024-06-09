// Best Time to Buy and Sell Stock III
// Problem statement
// Given an array "prices". In "prices" the ith element is the price of the
// stock on the ith day. Your task is to find maximum profit at the end of the ith day.
// You may complete at max 2 transactions.

// You can perform a transition with these conditions -

// 1. Not allowed to engage in more than 1 transaction at a time, which means if you have bought stock then you can buy another stock before selling the first stock.

// 2. If you bought a stock at ‘X’ price and sold it at ‘Y’ price then the profits ‘Y - X’.
// Note:
// It is not compulsory to perform an exact '2' transaction.

// Link : https://www.naukri.com/code360/problems/buy-and-sell-stock-iii_1092612

// Approach :
// We will write a recurrence function with params as current Day index, number of transactions done and bool shouldBuy
// We will keep track of the number of transactions done so far and handle it in the base case.
// We will explore all possibilities of buy/not buy and sell/notsell based on the shouldBuy value
// We will take the max profit of all the possibilites
// We will memoize the states to prevent doing overlapping subproblems

#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> &prices, int ind, int buy, int n, int count,
           vector<vector<vector<int>>> &dp)
{
    // Base case: When we reach the end of the prices array or reached the transaction cap
    if (ind == n || count == 2)
    {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy][count] != -1)
    {
        return dp[ind][buy][count];
    }

    int profit = 0;

    if (buy == 0)
    { // We can buy the stock
        int bought = -prices[ind] + getAns(prices, ind + 1, 1, n, count, dp);
        int notBought = 0 + getAns(prices, ind + 1, 0, n, count, dp);
        profit = max(bought, notBought);
    }
    else
    { // We can sell the stock
        int sold = prices[ind] + getAns(prices, ind + 1, 0, n, count + 1, dp);
        int notSold = 0 + getAns(prices, ind + 1, 1, n, count, dp);
        profit = max(sold, notSold);
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy][count] = profit;
}

int maxProfit(vector<int> &prices, int n)
{
    // Create a DP table to memoize results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    // Handle edge case where there are no prices
    if (n == 0)
    {
        return 0;
    }

    // Start with day 0, buy state, and no transactions done
    return getAns(prices, 0, 0, n, 0, dp);
}

// Time complexity : O(N)
// Space complexity : O(N)

// TABULATION
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                {
                    dp[i][j][k] = -prices[i];
                }
                else if (i == 0 && j == 0 && k != 0)
                {
                    dp[i][j][k] = INT_MIN;
                }
                else if (i == 0 && j == 1 && k == 0)
                {
                    dp[i][j][k] = prices[i];
                }
                else if (i == 0 && j == 1 && k != 0)
                {
                    dp[i][j][k] = INT_MIN;
                }
                else if (j == 0 && k == 0)
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], -prices[i]);
                }
                else if (j == 0 && k != 0)
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][1][k - 1] - prices[i]);
                }
                else if (j == 1 && k == 0)
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][0][k] + prices[i]);
                }
                else if (j == 1 && k != 0)
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][1][k]);
                }
            }
        }
    }

    return dp[n - 1][0][2];
}

// Time complexity : O(N)
// Space complexity : O(N)

// SPACE OPTIMIZED TABULATION
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }

    vector<vector<int>> dp(2, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                {
                    dp[j][k] = -prices[i];
                }
                else if (i == 0 && j == 0 && k != 0)
                {
                    dp[j][k] = INT_MIN;
                }
                else if (i == 0 && j == 1 && k == 0)
                {
                    dp[j][k] = prices[i];
                }
                else if (i == 0 && j == 1 && k != 0)
                {
                    dp[j][k] = INT_MIN;
                }
                else if (j == 0 && k == 0)
                {
                    dp[j][k] = max(dp[j][k], -prices[i]);
                }
                else if (j == 0 && k != 0)
                {
                    dp[j][k] = max(dp[j][k], dp[1][k - 1] - prices[i]);
                }
                else if (j == 1 && k == 0)
                {
                    dp[j][k] = max(dp[j][k], dp[0][k] + prices[i]);
                }
                else if (j == 1 && k != 0)
                {
                    dp[j][k] = max(dp[j][k], dp[1][k]);
                }
            }
        }
    }

    return dp[0][2];
}

// Time complexity : O(N)
// Space complexity : O(1)
