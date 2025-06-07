// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element

class Solution
{
private:
    // int brute(vector<int> &nums) {}

    // Intuition: Think of it as a real mountain
    //  If mid > mid+1 , we are on descending slope hence peak will be in [0,mid]
    //  If mid<mid+1, we are on ascending slop hence peak will be somewhere ahead [mid+1,n]
    //  TC:O(LogN)
    int optimal(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // If mid element is greater than the next one,
            // then the peak lies on the left (including mid)
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                // Else, peak lies on the right (excluding mid)
                left = mid + 1;
            }
        }

        // At the end, left == right and points to a peak
        return left;
    }

public:
    int findPeakElement(vector<int> &nums)
    {
        return optimal(nums);
    }
};