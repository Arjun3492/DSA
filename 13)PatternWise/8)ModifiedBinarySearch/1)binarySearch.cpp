// Binary Search
// https://leetcode.com/problems/binary-search

class Solution
{

private:
    // Basic linear search
    //  TC:O(n)
    int brute(vector<int> &nums, int target)
    {

        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }

    // Binary search
    // Tc:O(logN)
    int optimal(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) // till left does not cross right
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (target < nums[mid])
            {
                // search in left half
                right = mid - 1;
            }
            else
            {
                // search in right half
                left = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        return optimal(nums, target);
    }
};