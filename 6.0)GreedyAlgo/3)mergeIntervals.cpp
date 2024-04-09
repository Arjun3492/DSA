// Merge Intervals
// Problem statement
// You are given N number of intervals, where each interval contains two integers denoting the start time and the end time for the interval.
// The task is to merge all the overlapping intervals and return the list of merged intervals sorted by increasing order of their start time.
// Two intervals [A,B] and [C,D] are said to be overlapping with each other if there is at least one integer that is covered by both of them.

// Example :
// Input : [[1,3],[2,6],[8,10],[15,18]]
// Output : [[1,6],[8,10],[15,18]]
// Explanation: The intervals [1,3] and [2,6] are overlapping with each other, so they are merged into [1,6].

// Link : https://www.naukri.com/code360/problems/merge-intervals_699917

// Approach
// We will sort the intervals at first
// We will initialise a vector of pairs to store the merged intervals
// Intially we will add the first interval to the merged intervals
// We will iterate through the intervals and check if the current interval overlaps with the last interval in the merged intervals
// If it overlaps , we will update the end time of the last interval in the merged intervals (meaning we will merge it with the previous interval)
// If it does not overlap , we will add the current interval to the merged intervals , this will now become the last interval to be checked for overlapping

// Time complexity: O(NlogN) + O(N) [sorting + traversing]
// Space complexity: O(N) [extra space is used to store the merged intervals]

#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // if the current interval does not
        // lie in the last interval: we add it to the answer
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval: we merge them
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
