// Subset Sum
// Problem statement
// You are given an array 'nums' of ‘n’ integers.
// Return all subset sums of 'nums' in a non-decreasing order.
// Note:
// Here subset sum means sum of all elements of a subset of 'nums'. A subset of 'nums' is an array formed by removing some (possibly zero or all) elements of 'nums'.

// For example
// Input: 'nums' = [1,2]
// Output: 0 1 2 3
// Explanation:
// Following are the subset sums:
// 0 (by considering empty subset)
// 1
// 2
// 1+2 = 3
// So, subset sum are [0,1,2,3].

// Link : https://www.naukri.com/code360/problems/subset-sum_3843086

// Intuition
// We will follow the take or leave approach for each element in the array.
// We will make a recursive call for both the choices with the value of sum.

// Time complexity: O(2^n)  + [O(2^nlog2^n) for sorting the result]
// Space complexity: O(2^n) [stack space]

void helper(int i, int sum, vector<int> &ans, vector<int> &num)
{

    // Base case: Reached the end of array
    if (i == num.size())
    {
        ans.push_back(sum); // adding the subset sum to ans
        return;
    }
    helper(i + 1, sum + num[i], ans, num); // taking ith element
    helper(i + 1, sum, ans, num);          // not taking ith element
}

vector<int> subsetSum(vector<int> &num)
{

    vector<int> ans;
    helper(0, 0, ans, num);
    sort(ans.begin(), ans.end()); // sorting the final ans
    return ans;
}
