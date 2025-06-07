// 154. Find Minimum in Rotated Sorted Array II

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution
{

private:
    // Intuition:
    //  We need to find the pivot which is indeed the smallest in the array
    //  Pivot is the point where the array drops to a lower value after an increasing slope
    //  Conditions:
    // 1 . mid_el > end_el ,i.e. pivot is somewhere on the right
    //  2. mid_el< end_el ,i.e. pivot is somewhere on the left
    //  3. mid_el==end_el, edge case for duplicates[3,3,1,2,3]	//3 ==3 ,decrement end_idx
    int optimal(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;

        while (s < e)
        {
            int m = s + (e - s) / 2;

            if (nums[m] > nums[e])

            {
                // pivot is on right
                s = m + 1;
            }
            else if (nums[m] < nums[e])
            {
                // pivot on left
                e = m; // could be ans ,but looking for a smaller value on left
            }
            else
            {
                // edge case for duplicates
                e--;
            }
        }
        // at the end of loop. s==e = index of smallest element,i.e. pivot
        return nums[s];
    }

public:
    int findMin(vector<int> &nums)
    {
        return optimal(nums);
    }
};