// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution
{

private:
    int getFirstSeen(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0, e = n - 1;
        int ans = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                // could be ans, but keep looking towards left
                // as we need the first occurrence of target
                ans = m;
                e = m - 1;
            }
            else if (target < nums[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }

    int getLastSeen(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0, e = n - 1;
        int ans = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                // could be ans, but keep looking towards right
                // as we need the last occurence of target
                ans = m;
                s = m + 1;
            }
            else if (target < nums[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }

        return ans;
    }
    vector<int> optimal(vector<int> &nums, int target)
    {

        int firstSeenPos = getFirstSeen(nums, target);
        int lastSeenPos = getLastSeen(nums, target);

        return {
            firstSeenPos,
            lastSeenPos};
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return optimal(nums, target);
    }
};