// Problem statement
// You are given an array ‘arr’ of ‘n’ positive integers.
// You are also given a positive integer ‘target’.
// Your task is to find all unique combinations of elements of array ‘arr’ whose sum is equal to ‘target’. Each number in ‘arr’ may only be used once in the combination.
// Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.
// Note:
// In lexicographical order, combination/array  ‘a’  comes before array ‘b’ if at the first index 'i' where 'a[i]' differs from 'b[i]', 'a[i]' < 'b[i]  or length of 'a' is less than 'b'.

// Example:
// Input: ‘arr’ = [1, 2, 3, 1], ‘target’ = 5.
// Output: [[1,1,3], [2,3]]
// Explanation:
// All possible valid combinations with sum = 5 in lexicographical order are -:
// (1, 1, 3)
// (2, 3)

// Link : https://www.naukri.com/code360/problems/combination-sum-ii_1112622

// Brute Force Approach
//  Using power set approach to generate all possible combinations and then checking if the sum of the combination is equal to B or not.
//  If yes then add it to the result.
//  Time Complexity: O(2^N * N) , 2^N for generating all possible combinations and N for checking the sum of each combination.
//  Space Complexity: O(2^N * N) , 2^N for storing all possible combinations and N for storing each combination.

vector<vector<int>> combSum2(vector<int> &a, int target)
{

    // using bit manipulation to generate all possible combinations
    vector<vector<int>> res;
    int n = a.size();
    for (int i = 0; i < (1 << n); i++) // 1<<n is equal to 2^n
    {
        vector<int> temp;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) // generating all possible combinations ,based on set bits
            {
                sum += a[j];
                temp.push_back(a[j]);
            }
        }
        if (sum == target) // checking if the sum of the combination is equal to target or not
            res.push_back(temp);
    }
}

// Better Approach(Pattern to generate all possible combinations )
// Using recursion to generate all possible combinations and checking if the sum of the combination is equal to B or not.
// We will use the take and not take approach to generate all possible combinations.
// We will sort the array and use a set to store the combination to avoid duplicates.
// Time Complexity: O(2^t)*log k, where t the target and log k is to store the combination in the set result.
// Space Complexity: O(N) , N for storing each combination.

#include <bits/stdc++.h>

void recCombSum(vector<int> &a, int target, int index, vector<int> &ds,
                set<vector<int>> &ans)
{

    // Base case: reached the end of array
    if (index == a.size())
    {
        // if target is reduced to zero , this is a candidate solution
        if (target == 0)
        {
            ans.insert(ds);
        }
        // finally return
        return;
    }

    // if current index element is less than target(substracting it from target
    // won't reduce the target to zero)

    if (a[index] <= target)
    {

        // Take recursive call

        ds.push_back(a[index]); // pushing it to ds
        recCombSum(a, target - a[index], index + 1, ds, ans);
        ds.pop_back(); // popping it from to ds, to continue with non take path
    }

    // Not Take recursive call
    recCombSum(a, target, index + 1, ds,
               ans); // target remains same , while moving to next index
}

vector<vector<int>> combinationSum2(vector<int> &a, int n, int target)
{
    sort(a.begin(), a.end());
    set<vector<int>> ans; // using set to store only unique candidates
    vector<int> ds;
    recCombSum(a, target, 0, ds, ans);
    return {ans.begin(), ans.end()}; // parsing to vector
}

// Optimized Approach(Pattern to generate all possible combinations by skipping duplicates)
//  We will skip the duplicates for a given index and then generate all possible combinations.
//  Time Complexity: O(2^N * N) , 2^N for generating all possible combinations and N for checking the sum of each combination.
//  Space Complexity: O(2^N * N) , 2^N for storing all possible combinations and N for storing each combination.

#include <bits/stdc++.h>
void findCombination(int ind, int target, vector<int> &arr,
                     vector<vector<int>> &ans, vector<int> &ds)
{

    // base case: if target reduced to 0
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    // for each position we will ,pick a unique and suitable number
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1]) // skipping duplicates
            continue;
        if (arr[i] > target) // breaking out , if no more numbers lesser than target avaiable
            break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &a, int n, int target)
{
    sort(a.begin(), a.end());
    vector<vector<int>> ans; // using set to store only unique candidates
    vector<int> ds;
    findCombination(0, target, a, ans, ds);
    return ans; // parsing to vector
}
