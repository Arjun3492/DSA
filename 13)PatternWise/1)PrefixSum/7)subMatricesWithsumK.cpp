// 1074. Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution
{
public:
    // Intuition: we will iterate through the rows and
    // make a compressed 1D array summing up the columns for each
    // index of 1D array, then perform the target sum approach on compressed 1d array
    //  O(rows² × cols)
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int count = 0;

        // Prefix sum across rows
        for (int r1 = 0; r1 < rows; ++r1)
        {
            vector<int> colSum(cols, 0); // compressed 1D array for current row pair

            for (int r2 = r1; r2 < rows; ++r2)
            {
                // Build 1D array: sum of elements in column `c` from row `r1` to `r2`
                for (int c = 0; c < cols; ++c)
                {
                    colSum[c] += matrix[r2][c];
                }

                // Now count subarrays in colSum with sum = target
                unordered_map<int, int> prefixFreq;
                prefixFreq[0] = 1;

                int prefixSum = 0;
                for (int sum : colSum)
                {
                    prefixSum += sum;

                    // Check if a subarray with sum = target ends here
                    if (prefixFreq.find(prefixSum - target) != prefixFreq.end())
                    {
                        count += prefixFreq[prefixSum - target];
                    }

                    // Record current prefix sum
                    prefixFreq[prefixSum]++;
                }
            }
        }

        return count;
    }
};