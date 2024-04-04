// Get All Unique Subsets
// Problem statement
// You are given an sorted integer array of size 'n'.
// Your task is to find and return all the unique subsets of the input array.
// Subsets are arrays of length varying from 0 to 'n', that contain elements of the array. But the order of elements should remain the same as in the input array.
// Note:
// The order of subsets is not important. You can return the subsets in any order. However, in the output, you will see the subsets in lexicographically sorted order.

// Time Limit: 1 sec
// Example:
// Input: 'n' = 3, 'arr' = [12, 15, 20]

// Output: [[], [12], [12, 15], [12, 15, 20], [12, 20], [15], [15, 20], [20]]

// Link : https://www.naukri.com/code360/problems/get-all-unique-subsets_624393

// Brute Force Approach
//  We will use a Set to store the subsets to avoid duplicates.
//  We will use the take or leave approach for each element in the array.
//  We will make a recursive call for both the choices.
//  Time Complexity: O(2^n * n) [2^n for generating all possible subsets and n for copying the subset to the result set]
//  Space Complexity: O(2^n) [stack space]

#include <bits/stdc++.h>
using namespace std;

void helper(int idx, vector<int> &arr, vector<int> &ds,
            set<vector<int>> &ans)
{

    if (idx == arr.size())
    {
        ans.insert(ds); // set will automatically take care of duplicates
        return;
    }

    // Pick the element
    ds.push_back(arr[idx]);
    helper(idx + 1, arr, ds, ans);
    ds.pop_back();

    // Don't pick the element
    helper(idx + 1, arr, ds, ans);
}

vector<vector<int>> getUniqueSubsets(vector<int> &arr)
{

    set<vector<int>> ans;
    vector<int> ds;
    helper(0, arr, ds, ans);
    return {res.begin(), res.end()}; // converting set to vector
}

// Optimal Approach
// We will sort the array at first
// Then inside the recursive function, for each position  we will pick a unique element for it and make a recursive call for the next position.
// Time Complexity: O(2^n)
// Space Complexity: O(2^n) [stack space]

void helper(int idx, vector<int> &arr, vector<int> &ds,
            vector<vector<int>> &ans)
{

    ans.push_back(ds);

    // each iteration will pick a unique element for the "idx" position
    // i.e. when idx=1, it will form subsets of size 1 will all possible unique
    // elements and so on
    for (int i = idx; i < arr.size(); i++)
    {

        // skipping duplicates for a given position
        if (i != idx && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        helper(i + 1, arr, ds, ans); // moving to fill next
        ds.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int> &arr)
{

    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end()); // only if array is unsorted
    helper(0, arr, ds, ans);
    return ans;
}