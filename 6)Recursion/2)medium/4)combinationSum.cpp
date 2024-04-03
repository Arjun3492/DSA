// Combination Sum
// Problem statement
// You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.
// Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.
// Elements in each combination must be in non-decreasing order.

// For example:
// Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-
// (1, 1, 1, 1, 1)
// (1, 1, 1, 2)
// (1, 1, 3)
// (1, 2, 2)
// (2, 3)

// Link : https://www.naukri.com/code360/problems/combination-sum_981296

// Approach
// Using recursion to generate all possible combinations and checking if the sum of the combination is equal to B or not.
// We will use the take and not take approach to generate all possible combinations.

// Time Complexity: O(2^t)*k, where t the target and k is to store the combination in the result.
// Space Complexity: O(N) , N for storing each combination.

void recCombSum(vector<int> &a, int target, int index, vector<int> &ds,
                vector<vector<int>> &ans)
{

    // Base case: reached the end of array
    if (index == a.size())
    {
        // if target is reduced to zero , this is a candidate solution
        if (target == 0)
        {
            ans.push_back(ds);
        }
        // finally return
        return;
    }

    // if current index element is less than target(substracting it from target
    // won't reduce the target to zero)
    if (a[index] <= target)
    {
        ds.push_back(a[index]); // pushing it to ds
        recCombSum(a, target - a[index], index, ds,
                   ans); // calling with same index
        ds.pop_back();
    }
    recCombSum(a, target, index + 1, ds,
               ans); // moving to next index
}

vector<vector<int>> combSum(vector<int> &a, int target)
{
    sort(a.begin(), a.end()); // sorting the array, as we need to print the combination in non-decreasing order
    vector<vector<int>> ans;
    vector<int> ds;
    recCombSum(a, target, 0, ds, ans);
    return ans;
}
