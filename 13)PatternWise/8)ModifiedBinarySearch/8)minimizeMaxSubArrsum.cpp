// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum

// The painter partition problem
// and the allocation of books problem are based on exact same problem statement

// https://youtu.be/Z0hwjftStI4?si=7vcc4JiajEuCZxuo
// https://youtu.be/thUd_WJn6wk?si=yuMcS-Yer-HtMdJT

class Solution
{
private:
    // Helper fn to get number of partitions to split array such that
    // subarray sum of each partition<=maxSubArrSum
    // TC:O(N)
    int getPartitions(vector<int> &nums, int maxSum)
    {

        int currSum = 0, partition_count = 1;
        for (int i : nums)
        {
            // curr element can be included in partition
            if (currSum + i <= maxSum)
            {
                currSum += i;
            }
            else
            {
                // allocate the curr num to the next partition
                partition_count++;
                currSum = i;
            }
        }
        return partition_count;
    }

    // helper fn to return the range of bounds ,i.e. lower and upper bound
    pair<int, int> getBounds(vector<int> &nums)
    {
        // Lower bound (lb):
        // The minimum possible value for the largest sum among
        // subarrays is the maximum single element.
        // This is because no subarray can avoid including at least one element,
        // so the largest element
        // is the minimum "worst case" for any subarray.
        // TC:O(N)

        int lb = *max_element(nums.begin(), nums.end());

        // Upper bound (ub):
        // The maximum possible value for the largest subarray sum is the
        // total sum of the array.
        // This happens when we consider the entire array as one single subarray.
        // TC:O(N)
        int ub = accumulate(nums.begin(), nums.end(), 0);

        return {
            lb,
            ub};
    }
    int brute(vector<int> &nums, int k)
    {

        // Will linearly iterate from lower bound to higher bound of sum
        // and the first feasible sum where array is split into exactly K subarray,
        // will be our ans
        int n = nums.size();

        pair<int, int> bounds = getBounds(nums);
        int lb = bounds.first, ub = bounds.second;

        // Intuition: the number of partitions increase with reduction in maxSubArraySum
        //  eg for partitions = 1, maxSubArraySum will be upper bound
        //  for paritions = n, maxSubArraySum will be largest element in array(lower_bound)

        // hence when we iterate from lower maxSubArraySum to higher
        // k(num of partitions) will reduce,
        // and we have to find the first maxSubArraySum where partitions= k
        for (int i = lb; i <= ub; i++)
        {
            int maxSubArraySum = i;
            int partitions = getPartitions(nums, maxSubArraySum);
            // the first possible(i.e. min) maxSubArraySum for which number of
            // partitions are reduced to K
            if (partitions == k)
            {
                return maxSubArraySum;
            }
        }
        return -1;
    }

    // Intuition will apply BS algo to the lb and ub
    int optimal(vector<int> &nums, int k)
    {
        int n = nums.size();

        pair<int, int> bounds = getBounds(nums);
        int lb = bounds.first, ub = bounds.second;

        while (lb < ub)
        {
            int m = lb + (ub - lb) / 2;

            int partitions = getPartitions(nums, m);

            if (partitions <= k)
            {
                // We found a valid maxSubArraySum (m) that allows at most k partitions.
                // Try to minimize it further by searching the left half.
                ub = m;
            }
            else
            {
                // Too many partitions → current m is too small.
                // We need to increase m to allow fewer partitions.
                lb = m + 1;
            }
        }
        // at the end of loop ,lb==ub = min maxSubArraySum with partition = k
        return lb;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        // Edge:Not possible to split n size array into k non empty
        if (k > nums.size())
            return -1;
        return optimal(nums, k);
    }
};