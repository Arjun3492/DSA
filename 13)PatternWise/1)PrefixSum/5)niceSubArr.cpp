// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution
{

    // Brute Force Approach:
    // Intuition: For every subarray, count the number of odd elements.
    // If the count == k, increment the result.
    // Time: O(n^2), Space: O(1)
    int brute(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int oddCount = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 != 0)
                {
                    oddCount++;
                }

                if (oddCount == k)
                {
                    count++;
                }
                else if (oddCount > k)
                {
                    break; // No point in going further
                }
            }
        }

        return count;
    }

    // Optimal Approach:
    // Intuition: Prefix sum of odd counts.
    // Track how many times a specific odd count has appeared using a map.
    // If current_odd_count - k appeared before, add its frequency to the result.
    // Time: O(n), Space: O(n)
    int optimal(vector<int> &nums, int k)
    {

        map<int, int> mpp; // stores the<num_of_odd_elements,occurence_count>
        int curr_occurence = 0;
        int total = 0;

        for (int i : nums)
        {
            // if odd increase curr_occurence
            if (i % 2 != 0)
            {
                curr_occurence++;
            }

            if (curr_occurence == k)
            {
                total++;
            }

            int target = curr_occurence - k;

            if (mpp.find(target) != mpp.end())
            {
                // adding up occurences of target previously
                //  bcz  there will be  mpp[target] of subarray that will end at current index
                //  having K odd elements
                total += mpp[target];
            }
            // adding the occurence of current num of odd elements to map
            mpp[curr_occurence]++;
        }
        return total;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return optimal(nums, k);
    }
};