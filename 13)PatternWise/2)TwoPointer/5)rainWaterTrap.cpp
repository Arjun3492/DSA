// Problem: https://leetcode.com/problems/trapping-rain-water/

class Solution
{
private:
    // Optimal Two-Pointer Approach
    // Time: O(n), Space: O(1)
    int optimal(vector<int> &h)
    {
        int n = h.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int totalW = 0;

        // Process bars from both ends toward the center
        while (left < right)
        {
            // We always process the side with the smaller height,
            // because the trapped water is limited by the shorter boundary.
            if (h[left] < h[right])
            {
                // If current height is greater than leftMax, update it
                if (h[left] > leftMax)
                {
                    leftMax = h[left];
                }
                else
                {
                    // Water trapped = leftMax - current height
                    totalW += leftMax - h[left];
                }
                left++; // move the left pointer forward
            }
            else // h[right] <= h[left]
            {
                // If current height is greater than rightMax, update it
                if (h[right] > rightMax)
                {
                    rightMax = h[right];
                }
                else
                {
                    // Water trapped = rightMax - current height
                    totalW += rightMax - h[right];
                }
                right--; // move the right pointer backward
            }
        }

        return totalW;
    }

    // Prefix Max Arrays Approach (Less Optimal)
    // Time: O(n), Space: O(n)
    // Intuition: Water at index i = min(maxHeightToLeft, maxHeightToRight) - h[i]
    int brute(vector<int> &h)
    {
        int n = h.size();

        // Precompute max heights to the left and right of each index
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        // Fill leftMax: max height to the left of each bar
        leftMax[0] = h[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], h[i]);
        }

        // Fill rightMax: max height to the right of each bar
        rightMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], h[i]);
        }

        int totalW = 0;

        // For each bar, compute the water it can trap
        for (int i = 0; i < n; i++)
        {
            int waterLevel = min(leftMax[i], rightMax[i]); // limiting height
            totalW += waterLevel - h[i];                   // trapped water = limiting height - current height
        }

        return totalW;
    }

public:
    int trap(vector<int> &height)
    {
        // Choose one of the approaches to return
        return optimal(height); // O(n) time, O(1) space
        // return brute(height); // O(n) time, O(n) space
    }
};
