// Find Minimum Number Of Coins
// Problem statement
// Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.
// Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required in decreasing order.
// For Example
// For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
// Note
// It is always possible to find the minimum number of coins for the given amount. So, the answer will always exist.

// Example :
// Input : N = 70
// Output : [50, 20]
// Explanation: The minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.

// Link : https://www.naukri.com/code360/problems/find-minimum-number-of-coins_975277

// Approach
// We will follow a greedy approach to solve this problem.
// Since we want the minimum number of coins, we will first pick the coins with the higher value.
// We will iterate through the coins in decreasing order and keep reducing the amount by the value of the coin until the amount becomes zero.

// Time complexity: O(N * A) [where A is the amount and N is the number of coins]
// Space complexity: O(1) [no extra space is used]

vector<int> MinimumCoins(int n)
{
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> coins;

    int remainingAmt = n;

    // Step 1: Optional - We will find the first denomination just smaller than the amount
    int s = 0;
    int e = denominations.size() - 1;
    int mid = s - (s - e) / 2;

    while (s <= e)
    {

        if (denominations[mid] > n)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s - (s - e) / 2;
    }

    // Step2: Traverse the denominations in decreasing order and keep reducing the amount by the value of the coin until the amount becomes zero.
    for (int i = mid; i >= 0; i--)
    // We  can skip step 1 and start from i=denominations.size()-1 , as the number of denominations is very less
    {
        while (denominations[i] <= remainingAmt) // if the denomination is less than the remaining amount
        {
            remainingAmt -= denominations[i];  // reduce the amount by the denomination
            coins.push_back(denominations[i]); // add the denomination to the list of coins
        }
        if (remainingAmt == 0) // if the amount becomes zero
            break;
    }

    return coins; // return the list of coins
}
