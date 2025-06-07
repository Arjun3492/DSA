// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k

class Solution
{
private:
    int preFixApproach(vector<int> &nums, int k)
    {
        // initializing prefixSum
        int prefixSum = 0;

        // prefixsum mpp[sum:occurrence_count]
        unordered_map<int, int> prefixMpp;
        // initially count is set to 0
        int count = 0;
        for (int i : nums)
        {
            prefixSum += i;

            // edge case
            if (prefixSum == k)
            {
                count++;
            }

            // prefix sum to check for
            int toBeFound = prefixSum - k;

            if (prefixMpp.find(toBeFound) != prefixMpp.end())
            {
                // if found, increment count by number of occurrences
                count += prefixMpp[toBeFound];
            }
            prefixMpp[prefixSum]++;
        }
        return count;
    }

    int bruteApproach(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }

public:
    int subarraySum(vector<int> &nums, int k)
    {
        // return preFixApproach(nums, k);
        return bruteApproach(nums, k);
    }
};