// Stock Span
// Given an array 'prices' where 'prices[i]' denotes the price of a stock on the 'i'th day.
// You are required to find the stock span for each day.
// The stock span of a stock 'i' is the number of days before the current day for which the price of the stock was less than or equal to its price on the current day.
// Link : https://www.naukri.com/code360/problems/stock-span_5243295
// Approach:Monotonic stack
// we will find the index of the left greater element for each element of the array ,if any.
// The difference between the index of the current element and the index of the left greater element gives the number of days before the current day for which the price of the stock was less than or equal to its price on the current day.
// If there is no left greater element, then the current element is the left greater element for all the elements before it.
// Time complexity: O(n)
// Space complexity: O(n)

vector<int> findStockSpans(vector<int> &prices)
{
    int n = prices.size();
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] < prices[i])
        {
            st.pop();
        }

        if (!st.empty())
        { // difference between the index of the current element and the index of the left greater element
            // gives the number of days before the current day for which the price of the stock was less than or equal to its price on the current day.
            ans.push_back(i - st.top());
        }
        else
        {
            // if there is no left greater element, then the current element is the left greater element for all the elements before it.
            ans.push_back(i + 1);
        }

        st.push(i);
    }

    return ans;
}