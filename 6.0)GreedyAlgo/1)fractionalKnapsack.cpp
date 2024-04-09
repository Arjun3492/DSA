// Fractional Knapsack
// Problem statement
// You have been given weights and values of ‘N’ items.
// You are also given a knapsack of size ‘W’.
// Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.
// Note:
// You are allowed to break the items.

// Example:
// N = 3
// W = 50
// Weights = [10, 20, 30]
// Values = [60, 100, 120]
// Output: 240
// Explanation: The maximum value that can be obtained is 240 by taking the first two items and breaking the third item into 20 units.

// Link: https://www.naukri.com/code360/problems/fractional-knapsack_975286

// Approach:
// We will follow a greedy approach to solve this problem.
// Since we want the maximum value and we are limited by the weight, we will sort the items based on the value/weight ratio in descending order.
// This will ensure that we get the maximum value each time we fill the knapsack.
// We will keep adding the items to the knapsack until we can’t add the next item completely.
// In this case, we will add the fraction of the next item to the knapsack.

// Time complexity: O(NlogN) + O(N) [sorting + traversing]
// Space complexity: O(1) [no extra space is used]

#include <bits/stdc++.h>

// ITEMS contains {weight, value} pairs.

// Function to compare the value/weight ratio of two items
bool comp(pair<int, int> a, pair<int, int> b)
{
    double first = (double)a.second / (double)a.first;
    double second = (double)b.second / (double)b.first;
    return first > second;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // sorting in decreasing order by value/weight ratio
    sort(items.begin(), items.end(), comp);

    double totalVal = 0;        // to keep track of total value in knapsack
    double remainingWeight = w; // to keep track of remaining weight in knapsack

    for (pair<int, int> it : items) // traversing through all items
    {

        if (it.first <= remainingWeight) // if full item can be added
        {
            // adding full item to knapsack
            totalVal += it.second;
            remainingWeight -= it.first;
        }
        else // if full item can't be added
        {
            // adding fraction of item as per the remaining weight
            totalVal += (double)it.second / (double)it.first * remainingWeight;
            break; // breaking the loop as knapsack is full
        }
    }
    return totalVal;
}