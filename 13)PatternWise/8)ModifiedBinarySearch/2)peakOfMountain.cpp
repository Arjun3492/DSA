// Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution
{

private:
    // Since the values are first increasing then decrease from peak, we will linearly
    // iterate and check for the first element where the next element is smaller,
    // and return its index
    // TC: O(N)
    int brute(vector<int> &arr)
    {

        int n = arr.size();

        for (int i = 0; i <= n - 2; i++)
        {
            int curr = arr[i], next = arr[i + 1];
            if (next < curr)
                return i;
        }

        return -1;
    }

    // Optimal solution using modified binary search
    // Since the values are first increasing then decrease from peak, we will use
    // binary search to find the peak element.
    // TC: O(logN)
    int optimal(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;

                while (left < right)
        {
            int mid = left + (right - left) / 2;

            // Check whether we're in the decreasing part of the mountain
            if (arr[mid] > arr[mid + 1])
            {
                // Since we're on the decreasing slope, mid could be the peak,
                // but there might be a higher peak on the left.
                right = mid;
            }
            else
            {
                // We're in the increasing part of the mountain.
                // So the peak must be to the right of mid.
                left = mid + 1;
            }
        }

        // At the end, left == right and points to the peak index
        return left;
    }

public:
    int peakIndexInMountainArray(vector<int> &arr)
    {

        return optimal(arr);
    }
};