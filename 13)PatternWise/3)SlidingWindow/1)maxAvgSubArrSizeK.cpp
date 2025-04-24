class Solution
{
private:
    // Brute-force approach by checking every subarray of length k
    // Time Complexity: O(n * k), where n = size of nums
    // Space Complexity: O(1)
    double brute(vector<int> &nums, int k)
    {
        double maxAvg = INT_MIN;
        int n = nums.size();

        // Iterate through all possible subarrays of size k
        for (int i = 0; i <= n - k; i++)
        {
            double sum = 0;

            // Calculate the sum of the current window
            for (int j = i; j < i + k; j++)
            {
                sum += nums[j];
            }

            double avg = sum / k;
            maxAvg = max(maxAvg, avg); // update maximum average
        }

        return maxAvg;
    }

    // Optimal approach using Sliding Window technique
    // Time Complexity: O(n), where n = size of nums
    // Space Complexity: O(1), as no extra space is used
    double optimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        double windowSum = 0;

        // Prepare the initial window [0 to k-1]
        int i = 0;
        while (i < k)
        {
            windowSum += nums[i];
            i++;
        }

        // Initial answer is the average of the first window
        double ans = windowSum / k;

        // Slide the window one element at a time
        // Add the next element (nums[i]), remove the leftmost (nums[i - k])
        while (i < n)
        {
            windowSum += nums[i] - nums[i - k]; // maintain sum of current window
            double avg = windowSum / k;
            ans = max(ans, avg); // update max average
            i++;
        }

        return ans;
    }

public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        return brute(nums, k); // change to `optimal(nums, k)` to use the optimized version
    }
};
