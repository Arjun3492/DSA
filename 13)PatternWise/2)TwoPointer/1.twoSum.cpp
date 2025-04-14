https : // leetcode.com/problems/two-sum-ii-input-array-is-sorted

        class Solution
{
private:
    // we will find each possible pair using nested loop
    // TC: O(n)
    vector<int> bruteApproach(vector<int> &arr, int target)
    {
        int n = arr.size();
        // int a, b = 0                                                  ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (arr[i] + arr[j] == target)
                {
                    return {
                        i,
                        j};
                }
            }
        }
        return {-1, -1};
    }

    // Taking two pointers placing them start and end ,
    //  doing start ++ and end--
    vector<int> optimal(vector<int> &arr, int target)
    {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
                return {i + 1, j + 1};
            if (sum < target)
                i++;
            else
                j--;
        }
        return {-1, -1};
    }

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // return bruteApproach(numbers, target)                         ;
        return optimal(numbers, target);
    }
};