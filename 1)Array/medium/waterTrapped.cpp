// Trapping Rainwater
// Problem Statement: Given an array of non-negative integers representation elevation of ground.
// Your task is to find the water that can be trapped after rain.

// Link:https://takeuforward.org/data-structure/trapping-rainwater

// Approach:the amount the water stored at a particular index is the "minimum of maximum" elevation to the
// left and right of the index minus the elevation at that index.

// waterTrapped[i] = min(maxLeft, maxRight) - elevation[i]

// Brute Force Approach: for each index, find the maximum elevation to the left and right of the index and
// then calculate the water stored at that index. Time Complexity: O(n^2)

int trap(vector<int> &arr)
{
    int n = arr.size();
    int totalWaterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            // find the maximum elevation to the left of the index
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            // find the maximum elevation to the right of the index
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        // calculate the water stored at the index
        int waterStoredAtCurrentIndex = min(leftMax, rightMax) - arr[i];
        totalWaterTrapped += waterStoredAtCurrentIndex;
    }
    return totalWaterTrapped;
}

// Better Approach:Use two arrays to store the maximum elevation to the left and right of the index.[hashing]
//  Time Complexity: O(n) Space Complexity: O(2n)

// Approach: Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand.
// Then use the formula min(prefix[I], suffix[i])-arr[i] to compute water trapped at each index.

int trap(vector<int> &arr)
{
    int n = arr.size();
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}

// Optimal Approach:
// Link:https://www.youtube.com/watch?time_continue=1199&v=m18Hntz4go8&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F

// Approach: Take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively.
// Take two variables leftMax and rightMax and initialize them to 0. If height[l] is less than or equal to
// height[r] then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l]
// to your final answer and move the l pointer to the right i.e l++. If height[r] is less than height[l],
// then now we are dealing with the right block. If height[r] is greater than rightMax, then update rightMax to
// height[r] else add rightMax-height[r] to the final answer. Now move r to the left. Repeat these steps till l and
// r crosses each other.

// Intuition: We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r]
// we increase l++, so we can surely say that there is a block with a height more than height[l] to the
// right of l. And for the same reason when height[r]<=height[l] we can surely say that there is a block
// to the left of r which is at least of height[r]. So by traversing these cases and using two pointers
// approach the time complexity can be decreased without using extra space.

int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}
