// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution
{

private:
    int optimal(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // In left sorted part
            if (nums[left] <= nums[mid])
            {
                // if num lies in left sorted part
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1; // target is in left part
                }
                else
                {
                    left = mid + 1;
                }
            }
            // In right sorted part
            else
            {
                // target is in right sorted part
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1; // target is in right part
                }
                else
                {
                    right = mid - 1;
                }
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