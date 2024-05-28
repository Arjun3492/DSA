// Frog Jump With K Distance

// Problem statement
// Same as last problem but here, If the Frog is on 'ith' staircase,
// he can jump i+1 to i+k th stair Your task is to find the minimum total energy used by
// the frog to reach from '1st' stair to 'Nth' stair.

// RECURSIVE APPROACH
// Step 1: We will assume the stairs as indexes from 0 to N-1 for the heights array.
// Step 2: At any given stair i, the frog can take any jump from i+1 to i+k stair.
// Step 3: To find the minimum total energy, we will return the minimum of all the choices in our recursive function.
// Step 4: The base case will be when we reach the 0th stair; the energy cost is zero since no jump is needed.

int helper(int i, vector<int> &heights, int k)
{
    // Base case: when at the 0th stair, no energy is required
    if (i == 0)
        return 0;

    int minEnergy = INT_MAX;
    // Calculate energy for a jump from (i-j)th to ith stair for all j from 1 to k
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            minEnergy = min(minEnergy, helper(i - j, heights, k) + abs(heights[i] - heights[i - j]));
        }
    }

    return minEnergy;
}

int frogJumpWithK(int n, vector<int> &heights, int k)
{
    return helper(n - 1, heights, k);
}

// MEMOIZATION

int helperMemo(int i, vector<int> &heights, vector<int> &memo, int k)
{
    // Base case: when at the 0th stair, no energy is required
    if (i == 0)
        return 0;

    // Return memoized result if already computed
    if (memo[i] != -1)
        return memo[i];

    int minEnergy = INT_MAX;
    // Calculate energy for a jump from (i-j)th to ith stair for all j from 1 to k
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            minEnergy = min(minEnergy, helperMemo(i - j, heights, memo, k) + abs(heights[i] - heights[i - j]));
        }
    }

    return memo[i] = minEnergy;
}

int frogJumpWithK(int n, vector<int> &heights, int k)
{
    vector<int> memo(n, -1);
    return helperMemo(n - 1, heights, memo, k);
}

// TABULATION

int frogJumpWithK(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        // Calculate energy for a jump from (i-j)th to ith stair for all j from 1 to k
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }

    return dp[n - 1];
}

// Time Complexity: O(n*k)
// Space Complexity: O(n)

// Space Optimized Tabulation

int frogJumpWithK(int n, vector<int> &heights, int k)
{
    vector<int> temp(k, INT_MAX);
    temp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minEnergy = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                minEnergy = min(minEnergy, temp[(i - j) % k] + abs(heights[i] - heights[i - j]));
            }
        }
        temp[i % k] = minEnergy;
    }
}