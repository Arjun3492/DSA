// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // intuition is that if we treat 1 as +1 and 0 as -1, then using prefix sum if
        //  a same sum is encountered later on in array it means between the current
        // index   and first occurence of the same sum if equal num of 0 and 1,
        // since we are doing +1 and -1, so to come to the same sum again there
        // must be equal num of 0 and 1

        unordered_map<int, int> mpp;
        // to store prefix sum -> first occurence(longest array)
        int prefixSum = 0;
        int largest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            //+1 for 1 and -1 for 0
            prefixSum += (nums[i] == 1 ? 1 : -1);
            if (prefixSum == 0)
            {
                // if at any point sum = 0, this means this is the largest
                largest = i + 1;
            }
            else if (mpp.find(prefixSum) == mpp.end())
            {
                // not found ,then store first occurence
                mpp[prefixSum] = i;
            }
            else
            {
                // if found earlier, get calculate length
                largest = max(largest, i - mpp[prefixSum]);
            }
        }
        return largest;
    }
};