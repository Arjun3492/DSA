// Maximum Consecutive Ones
// Problem statement:Given a binary array arr and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// link:https://www.codingninjas.com/studio/problems/maximum-consecutive-ones_892994

// Examples:
//  Input: arr = [1,1,1,0,0,0,1,1,1,1,0], k = 2
//  Output: 6
//  Explanation: [1,1,1,0,0,1,1,1,1,1,1]
//  Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Input: arr = [1,1,1,0,0,0,1,1,1,1,0], k = 0
// Output: 3
// Explanation: [1,1,1,0,0,0,1,1,1,1,0]
// In this case, k is 0 so you can't flip any 0's. The longest subarray is underlined.

// Approach: Sliding window

// Function to return the maximum number of consecutive 1's in the array
// with the ability to flip at most k 0's
int longestSubSeg(std::vector<int> &arr, int n, int k)
{
    // Initialize left and right pointers, zero count, and the maximum consecutive 1's count
    int l = 0, r = 0;
    int zeroCount = 0;
    int maxOneCount = 0;

    // Iterate through the array using the right pointer
    while (r < n)
    {
        // Get the current element
        int currEl = arr[r];

        // If the current element is 0, increment the zero count
        if (currEl == 0)
        {
            zeroCount++;
        }

        // While the zero count exceeds the allowed flips (k), move the left pointer
        while (zeroCount > k)
        {
            // If the left element is 0, decrement the zero count
            if (arr[l] == 0)
            {
                zeroCount--;
            }
            // Move the left pointer to the next position
            l++;
        }

        // Calculate the current count of consecutive 1's and update the maximum count
        maxOneCount = std::max(maxOneCount, r - l + 1);

        // Move the right pointer to the next position
        r++;
    }

    // Return the maximum consecutive 1's count
    return maxOneCount;
}
