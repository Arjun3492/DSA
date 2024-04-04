// Permuations
// Problem Statement:
// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.

// Example :
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Link : https://leetcode.com/problems/permutations/

// Approach 1:
// For each position we will make a recursive call to fill the position with all the elements of the array.
// To avoid duplicates we will keep track of the elements that we have already used using a hash array.
// Time Complexity: O(n! * n) ,n! for generating a permutation and n for iterating for each element.
// Space Complexity: O(n)+O(n) , O(n) for hash array and O(n) for ds.

void helper1(int idx, vector<int> isTaken, vector<int> &ds,
             vector<int> &nums, vector<vector<int>> &ans)
{

    // Base case: If all the elements are placed in the permutation
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!isTaken[i]) // if this element is not taken
        {
            isTaken[i] = 1;
            ds.push_back(nums[i]);
            helper1(i + 1, isTaken, ds, nums, ans); // recursive call for next position
            isTaken[i] = 0;                         // backtracking
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int> isTaken(n, 0);
    vector<int> ds;
    helper1(0, isTaken, ds, nums, ans);

    return ans;
}

// Approach 2:
// We can use recusion to generate all possible permutations by swapping the elements.
// We will swap the current element with all the elements to its right and make a recursive call for the next position.
// Time Complexity: O(n! * n) ,n! for generating a permutation and n for iterating for each element.
// Space Complexity: O(n)[stack space]

void helper2(int idx, vector<int> &nums, vector<vector<int>> &ans)
{
    // base case
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);    // swapping the current element with all the elements to its right, to form a new permutation
        helper2(idx + 1, nums, ans); // recursive call for next position
        swap(nums[i], nums[idx]);    // backtracking
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    helper2(0, nums, ans);
    return ans;
}
