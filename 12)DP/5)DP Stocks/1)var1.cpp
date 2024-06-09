// Stock Buy and Sell  1
// Problem statement
// You are given an array of integers 'prices' of size 'n', where ‘prices[i]’
// is the price of a given stock on an ‘i’-th day. You want to maximize the profit
// by choosing a single day to buy one stock and a different day to sell that stock.

// Please note that you can’t sell a stock before you buy one.

// Link : https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_6194560

// Approach
// We do a simple traversal through the given array while maintaining the lowest stock so far AND max profit so far.
// At each day we will find the profit with the lowest stock known so far and update max profit AND  lowest stock price  if required

// Time complexity : O(N)
// Space complexity : O(1)

int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    // stores the ans
    int maxProfit = 0;

    // stores the lowest stock so far
    int mini = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        // finding the current day profit based on lowest known stock
        int curProfit = prices[i] - mini;
        // updating max profit
        maxProfit = max(maxProfit, curProfit);
        // updating lowest stock price
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

// Approach : Memoized Recurrence

//  We will write a recurrence function with params as current Day index and bool shouldBuy
//  We will explore all possibilities of buy/not buy and sell/notsell based on the shouldBuy value
// Since we can only buy one stock at a time, we will set shouldBuy as -1 to indicate that one transaction has already been done and can handle it in base case.
//  We will take the max profit of all the possibilites
//  We will memoize the states to prevent doing overlapping subproblems

int getAns(vector<int> &prices, int ind, int buy, int n, vector<vector<int>> &dp)
{
    // Base case: When we reach the end of the pricesay, there are no more decisions
    // to make.
    if (ind == n)
    {
        return 0;
    }

    // BASE case : if we have sold the stock
    if (buy == -1)
    {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    int profit = 0;

    if (buy == 0)
    { // We can buy the stock
        int bought = -prices[ind] + getAns(prices, ind + 1, 1, n, dp);
        int notBought = 0 + getAns(prices, ind + 1, 0, n, dp);
        profit = max(bought, notBought);
    }

    if (buy == 1)
    {
        // when selling setting shouldBuy as -1 to indicate that one transaction executed
        int sold = prices[ind] + getAns(prices, ind + 1, -1, n, dp);
        int notSold = 0 + getAns(prices, ind + 1, 1, n, dp);
        profit = max(sold, notSold);
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

int bestTimeToBuyAndSellStock(vector<int> &prices)

{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    // Create a DP table to memoize results

    if (n == 0)
    {
        return 0;
    }

    int ans = getAns(prices, 0, 0, n, dp);
    return ans;
}
