// 739. Daily Temperatures
//  https://leetcode.com/problems/daily-temperatures

class Solution
{

private:
    // We will use a nested loop technique where in
    //  for each given index i we will find the index of the next warmer day
    //  if present we will store the difference in the indexes
    // which is equivalent to the numbers of days to wait
    // TC:O(n^2)
    // SC:O(1)
    vector<int> brute(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> ans(n, 0); // initialising with all 0, as per the ques

        // Nested loop
        for (int i = 0; i <= n - 2; i++)
        {
            int currDayTemp = arr[i];
            for (int j = i + 1; j <= n - 1; j++)
            {
                int futureTemp = arr[j];
                if (futureTemp > currDayTemp)
                {
                    ans[i] = j - i; // storing the num of days to wait
                    break;
                }
            }
        }
        return ans;
    }

    // We will use the monotonic stack approach, to find the next warmer day,
    // but will store the indexes in stack instead of the element itself
    //  TC:O(n)
    // SC:O(n)
    vector<int> optimal(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> ans(n, 0); // Initialising with all 0, as per the ques
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            int currDayTemp = arr[i];

            // pop each element where currDayTemp > arr[st.top()]
            while (!st.empty() && currDayTemp >= arr[st.top()])
            // carefully comparing the elements @ the index
            {
                st.pop();
            }
            // if now any element is left in stack that will be the NGE
            if (!st.empty())
            {
                ans[i] = st.top() - i; // diff between the indexes
            }
            // inserting the index of the current iTh day
            st.push(i);
        }
        return ans;
    }

public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        return optimal(temperatures);
    }
};