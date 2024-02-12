// Merge Overlapping Sub-intervals
// Problem Statement: Given an array of intervals, merge all the overlapping intervals
// and return an array of non-overlapping intervals.

// Link:https://www.codingninjas.com/studio/problems/merge-all-overlapping-intervals_6783452

// Example:
// Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
// Output: [[1, 6], [8, 10], [15, 18]]
// Explanation: Since intervals [1, 3] and [2, 6] overlap, we merged them into [1, 6], and so on.

// BRUTE FORCE APPROACH
// For each interval, we will check if it overlaps with any other interval and merge them,using a nested loop

// Time complexity: O(n^2)
// Space complexity: O(1)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0], end = arr[i][1];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end) // condition for overlap
            {
                end = max(end, arr[j][1]);
                i++;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// OPTIMAL APPROACH
//  We will sort the intervals based on the start time
//  Then we will iterate over the array and merge the overlapping intervals
//  Finally return the ans

// Time complexity: O(nlogn)
// Space complexity: O(1)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size(); // size of the array

    // sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // if the ans is initially empty or  if the current interval does not
        //  lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval, then we will update the upper bound of last interval accordingly
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}