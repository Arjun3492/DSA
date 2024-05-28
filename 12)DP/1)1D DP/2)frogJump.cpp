// // Frog Jump
// Problem statement
// There is a frog on the '1st' step of an 'N' stairs long staircase.
// The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair
// .If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute
// value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either
// to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by
// the frog to reach from '1st' stair to 'Nth' stair.

// Link : https://www.naukri.com/code360/problems/frog-jump_3621012

// RECURSIVE APPROACH
// Step 1: We will assume the stairs as indexes from 0 to N-1 for the heights array.

// Step 2: At any given stair i, the frog can jump either to (i+1) or (i+2).
// Step 3: To find the minimum total energy, we will return the minimum of both choices in our recursive function.
// Step 4: The base case will be when we reach the 0th stair; the energy cost is zero since no jump is needed.

int helper(int i, vector<int> &heights)
{
    // Base case: when at the 0th stair, no energy is required
    if (i == 0)
        return 0;

    // Calculate energy for a jump from (i-1)th to ith stair
    int left = helper(i - 1, heights) + abs(heights[i] - heights[i - 1]);

    int right = INT_MAX;
    // Calculate energy for a jump from (i-2)th to ith stair if i >= 2
    if (i > 1)
    {
        right = helper(i - 2, heights) + abs(heights[i] - heights[i - 2]);
    }

    // Return the minimum energy required to reach ith stair
    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    return helper(n - 1, heights);
}

// MEMOIZATION

int helperMemo(int i, vector<int> &heights, vector<int> &memo)
{
    // Base case: when at the 0th stair, no energy is required
    if (i == 0)
        return 0;

    // Return memoized result if already computed
    if (memo[i] != -1)
        return memo[i];

    // Calculate energy for a jump from (i-1)th to ith stair
    int left = helperMemo(i - 1, heights, memo) + abs(heights[i] - heights[i - 1]);

    int right = INT_MAX;
    // Calculate energy for a jump from (i-2)th to ith stair if i >= 2
    if (i > 1)
    {
        right = helperMemo(i - 2, heights, memo) + abs(heights[i] - heights[i - 2]);
    }

    // Memoize and return the result
    return memo[i] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> memo(n, -1);
    return helperMemo(n - 1, heights, memo);
}

// TABULATION
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);

    // Base case: no energy required to be on the first stair
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        // Calculate energy for a jump from (i-1)th to ith stair
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        int right = INT_MAX;
        // Calculate energy for a jump from (i-2)th to ith stair if i >= 2
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        // Store the minimum energy required to reach ith stair
        dp[i] = min(left, right);
    }

    // The answer is the minimum energy to reach the last stair
    return dp[n - 1];
}

// TABULATION SPACE OPTIMIZATION
int frogJump(int n, vector<int> &heights)
{
    // Two variables to keep track of the last two computations
    int prev1 = 0; // Energy to reach (i-1)th stair
    int prev2;

    for (int i = 1; i < n; i++)
    {
        // Calculate energy for a jump from (i-1)th to ith stair
        int left = prev1 + abs(heights[i] - heights[i - 1]);

        int right = INT_MAX;
        // Calculate energy for a jump from (i-2)th to ith stair if i >= 2
        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }

        // Calculate the minimum energy required to reach ith stair
        int curr = min(left, right);

        // Update prev2 and prev1 for the next iteration
        prev2 = prev1;
        prev1 = curr;
    }

    // The answer is the minimum energy to reach the last stair
    return prev1;
}
