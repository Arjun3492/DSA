// 303. Range Sum Query - Immutable

// https://leetcode.com/problems/range-sum-query-immutable

class NumArray
{
private:
    std::vector<int> &arr;
    std::vector<int> prefixSum;
    int n;

public:
    NumArray(std::vector<int> &nums) : arr(nums), prefixSum(nums.size(), 0) //
    {

        // initializing presum array on object creation, so sumRange queries give lookup in 0(1)
        // using formula sum[L to R] = prefixSum[R]- prefixSum[L-1];
        n = arr.size();
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
    }

    int sum_On(int l, int r)
    {
        int sum = 0;
        for (int k = l; k <= r; k++)
        {
            sum += arr[k];
        }
        return sum;
    }

    int sumRange(int left, int right)
    {
        // return sum_On(left, right);
        if (left == 0)
        {
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *int param_1 = obj->sumRange(left,right);
 */