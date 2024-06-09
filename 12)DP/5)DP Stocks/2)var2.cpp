// Best Time to Buy and Sell Stock II
// Problem statement
// You have been given stock values/prices for N number of days.
// Every i-th day signifies the price of a stock on that day.
// Your task is to find the maximum profit which you can make by buying and selling the stocks.

//  Note :
// You may make as many transactions as you want but can not have more
// than one transaction at a time i.e, if you have the stock, you need
// to sell it first, and then only you can buy it again.

// Link : https://www.naukri.com/code360/problems/selling-stock_630282

// Approach :
//  We will write a recurrence function with params as current Day index and bool shouldBuy
//  We will explore all possibilities of buy/not buy and sell/notsell based on the shouldBuy value
//  We will take the max profit of all the possibilites
//  We will memoize the states to prevent doing overlapping subproblems

#include <bits/stdc++.h>
using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    // Base case: When we reach the end of the array, there are no more decisions
    // to make.
    if (ind == n)
    {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0)
    { // We can buy the stock
        long bought = -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp);
        long notBought = 0 + getAns(Arr, ind + 1, 0, n, dp);
        profit = max(bought, notBought);
    }

    if (buy == 1)
    {
        long sold = Arr[ind] + getAns(Arr, ind + 1, 0, n, dp);
        long notSold = 0 + getAns(Arr, ind + 1, 1, n, dp);
        profit = max(sold, notSold);
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n)
{
    // Create a DP table to memoize results
    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0)
    {
        return 0;
    }

    long ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

// Time complexity : O(N)
// Space complexity : O(N)

// Tabulation approach
long getMaximumProfit(long *Arr, int n)
{
    // Create a DP table to store the results of subproblems
    vector<vector<long>> dp(n, vector<long>(2, 0));

    // Initialize the base cases
    dp[0][0] = 0;
    dp[0][1] = -Arr[0];

    for (int i = 1; i < n; i++)
    {
        // If we are not holding any stock, we can either buy or do nothing
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + Arr[i]);

        // If we are holding a stock, we can either sell or do nothing
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - Arr[i]);
    }

    // Return the maximum profit we can make after the last day
    return dp[n - 1][0];
}

// Time complexity : O(N)
// Space complexity : O(N)

// SPACE OPTIMIZED TABULATION APPROACH

long getMaximumProfit(long *Arr, int n)
{
    // Initialize the base cases
    long sold = 0;
    long bought = -Arr[0];

    for (int i = 1; i < n; i++)
    {
        // If we are not holding any stock, we can either buy or do nothing
        long newSold = max(sold, bought + Arr[i]);

        // If we are holding a stock, we can either sell or do nothing
        long newBought = max(bought, sold - Arr[i]);

        sold = newSold;
        bought = newBought;
    }

    // Return the maximum profit we can make after the last day
    return sold;
}
