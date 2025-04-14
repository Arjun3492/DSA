// Problem: https://leetcode.com/problems/container-with-most-water/

class Solution
{
private:
    // O(n2)
    int bruteForce(vector<int> &h)
    {
        // For each current h[i] we will find the area for each h[j] towards its right
        // We will keep updating the maxHeight in the process
        int maxH = INT_MIN;
        int n = h.size();
        for (int i = 0; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                int height = min(h[i], h[j]);
                int width = (j - i);
                int area = height * width;
                maxH = max(area, maxH);
            }
        }
        return maxH;
    }

    // O(n)
    int optimal(vector<int> &h)
    {
        // Optimal approach where in we use the two pointer approach
        //  We take two pointers left and right,
        // calculate area as
        //  Area = min(both the heights) *width;
        //  Move the smaller pointer inwards.

        int n = h.size();
        int maxH = INT_MIN;

        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int height = min(h[left], h[right]);
            int width = right - left;
            int area = height * width;
            maxH = max(area, maxH);
            if (h[left] < h[right])
            {
                left++;
            }
            else
            {
                // h[left]>h[right]
                // Edge case(h[left]==h[right]) : If they're equal, both are limiting equally,
                // and moving either one might  lead to a better result —
                // but won’t cause a miss of the optimal area
                right--;
            }
        }
        return maxH;
    }

public:
    int maxArea(vector<int> &height)
    {
        // return bruteForce(height);
        return optimal(height);
    }
};