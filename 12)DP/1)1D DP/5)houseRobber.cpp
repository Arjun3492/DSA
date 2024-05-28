//  House Robber
// Problem statement
// Mr. X is a professional robber planning to rob houses along a street.
// Each house has a certain amount of money hidden.

// All houses along this street are arranged in a circle.
// That means the first house is the neighbour of the last one.
// Meanwhile, adjacent houses have a security system connected,
// and it will automatically contact the police if two adjacent houses are broken into on the same night.

// You are given an array/list of non-negative integers 'ARR' representing the
// amount of money of each house. Your task is to return the maximum amount of
// money Mr. X can rob tonight without alerting the police.

// Link : https://www.naukri.com/code360/problems/house-robber_839733

#include <bits/stdc++.h>

// Helper function to calculate the maximum amount of money Mr. X can rob tonight without alerting the police.
int helper(vector<int> &nums)
{
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int take_idx = nums[i];
        if (i > 1)
            take_idx += prev2;

        int not_take_idx = prev1;

        prev2 = prev1;
        prev1 = max(take_idx, not_take_idx);
    }

    return prev1;
}

// Function
long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];
    // Create two vectors to store the values of the houses excluding the first and last house
    vector<int> temp1(n - 1), temp2(n - 1);

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }

    // Return the maximum amount of money Mr. X can rob tonight either by excluding the first house or the last house
    return max(helper(temp1), helper(temp2));
}