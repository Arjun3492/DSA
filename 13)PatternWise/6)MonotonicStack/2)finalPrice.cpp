// 1475. Final Prices With a Special Discount in a Shop

// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution
{

private:
    // TC:O(n^2)
    // SC:O(1)
    vector<int> brute(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ans = prices;

        // using a nested loop to get the NSE item price for each item @ ith index
        for (int i = 0; i < n; i++)
        {

            int currEl = prices[i];

            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= currEl)
                {
                    // if NSE found, storing the discount
                    ans[i] = currEl - prices[j];
                    break;
                }
            }
        }

        return ans;
    }

    // TC:O(n)
    // SC:O(n)
    vector<int> optimal(vector<int> &prices)
    {
        int n = prices.size();
        stack<int> st;
        vector<int> ans = prices;

        for (int i = n - 1; i >= 0; i--)
        {
            // popping out elements which are greater than the curr element,
            // so that the element left at top is next smaller
            while (!st.empty() && prices[i] < st.top())
            {
                st.pop();
            }

            // storing final price ,if NSE exists for current item
            if (!st.empty())
            {
                ans[i] = prices[i] - st.top();
            }

            // pusing price of current item in stack
            st.push(prices[i]);
        }
        return ans;
    }

public:
    vector<int> finalPrices(vector<int> &prices)
    {
        return optimal(prices);
    }
};