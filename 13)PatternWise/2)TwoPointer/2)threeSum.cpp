// Three sum https://leetcode.com/problems/3sum

class Solution
{
private:
    // TC : O(nlogn) + O(n^3)
    // we sort the array and find all the unique triplets which sum up to three
    vector<vector<int>> brute(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        int n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int sum = arr[i] + arr[j] + arr[k];

                    if (sum == 0)
                        ans.insert({arr[i],
                                    arr[j],
                                    arr[k]});
                }
            }
        }

        // converting set to vector
        return {
            ans.begin(),
            ans.end()};
    }

    // Tc: O(nlogn) + O(n^2)
    vector<vector<int>> optimized(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // set to skip duplicates
        set<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            // using two pointer in the right sub array
            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0)
                {
                    ans.insert({nums[i],
                                nums[start],
                                nums[end]});
                    start++;
                    end--;
                }
                else if (sum < 0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        return {
            ans.begin(),
            ans.end()};
    }

public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        // return brute(arr);
        return optimized(arr);
    }
};