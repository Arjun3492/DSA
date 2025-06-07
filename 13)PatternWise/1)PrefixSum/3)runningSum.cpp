// 1480. Running Sum of 1d Array

// https://leetcode.com/problems/running-sum-of-1d-array

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        // stores the ans vector
        vector<int> ans;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // sum till the ith element
            sum += nums[i];
            // pushing to ans vector
            ans.push_back(sum);
        }
        return ans;
    }
};