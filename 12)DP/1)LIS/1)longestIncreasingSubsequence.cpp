// Longest Increasing Subsequence

// Problem statement
// For a given array with N elements, you need to find the length of the longest
// subsequence from the array such that all the elements of the subsequence are s
// orted in strictly increasing order.

// Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.

// Link : https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

// Brute Force Approach
//  We will generate all the subsequences using power set or recursion(take and not take approach) and check if the subsequence is strictly increasing or not.
// If it is strictly increasing, we will update the maximum length of the subsequence.

// Time Complexity: O(2^n)
// Space Complexity: O(n) [recursion stack space]

// Better Approach : Recursion with Memoization
// We will use the recursive approach to solve this problem.
// We will create a recursive function that will take the current index and the previous element as input.
// If the current index is greater than or equal to the size of the array, we will return 0.(Base case)
// If the current element is greater than the previous element, we will recursively call the function for the next index and the current element.
// We will store the result of the subproblem in a memoization array to avoid recomputation.
// Finally, we will return the maximum length of the subsequence.

// Time Complexity: O(n^2)
// Space Complexity: O(n) + O(n) [recursion stack space] = O(n)

int longestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return LIS(nums, -1, 0, memo);
}

int LIS(vector<int> &nums, int prev, int curr, vector<vector<int>> &memo)
{

    // Base case
    if (curr >= nums.size())
    {
        return 0;
    }
    // If the result is already computed
    if (memo[prev + 1][curr] != -1)
    {
        return memo[prev + 1][curr];
    }

    // Take the current element
    int taken = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        taken = 1 + LIS(nums, curr, curr + 1, memo);
    }

    // Not take the current element
    int notTaken = LIS(nums, prev, curr + 1, memo);

    // Store the result in the memoization array and return
    return memo[prev + 1][curr] = max(taken, notTaken);
}

// Optimal Approach : Tabulation Approach
// We will use the dynamic programming approach to solve this problem.
// We will create a dp array of size n to store the length of the longest increasing subsequence ending at the ith index.
// We will initialize the dp array with 1 as the minimum length of the subsequence will be 1.
// We will iterate over the array from the second element to the last element.
// For each element, we will iterate over all the elements before it and check if the current element is greater than the previous element.
// If it is greater, we will update the length of the longest increasing subsequence ending at the current index.
// We will update the maximum length of the subsequence.
// Finally, we will return the maximum length of the subsequence.

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// video : https://youtu.be/IFfYfonAFGc?si=VfN8oF-0OecvWq7X&t=619

int longestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int prev_ind = 0; prev_ind < ind; prev_ind++)
        {
            if (nums[ind] > nums[prev_ind])
            {
                dp[ind] = max(dp[ind], dp[prev_ind] + 1);
            }
        }
        maxLength = max(maxLength, dp[ind]);
    }
    return maxLength;
}

// Printing the Longest Increasing Subsequence using traceback
// Video : https://youtu.be/IFfYfonAFGc?si=C70wSVxoMMXSgrwt&t=1063

vector<int> longestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prevIndex(n, -1); // for traceback
    int maxLength = 1;
    int endIndex = 0;
    for (int ind = 1; ind < n; ind++)
    {
        for (int prev_ind = 0; prev_ind < ind; prev_ind++)
        {
            if (nums[ind] > nums[prev_ind])
            {
                if (dp[ind] < dp[prev_ind] + 1)
                {
                    dp[ind] = dp[prev_ind] + 1;
                    prevIndex[ind] = prev_ind; // updating the previous index for traceback
                }
            }
        }
        if (dp[ind] > maxLength)
        {
            maxLength = dp[ind];
            endIndex = ind;
        }
    }

    // Traceback to get the longest increasing subsequence
    vector<int> lis;
    while (endIndex != -1)
    {
        lis.push_back(nums[endIndex]);
        endIndex = prevIndex[endIndex];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
