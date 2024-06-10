// Count Ways To Reach The N-th Stairs
// Problem statement
// You have been given a number of stairs. Initially,
// you are at the 0th stair, and you need to reach the Nth stair.

// Each time, you can climb either one step or two steps.

// You are supposed to return the number of distinct ways you can
// climb from the 0th step to the Nth step.

// Link : https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

// Note : DP is applied to problem if it asks one of the following:
// 1. count the number of ways
// 2. find the minimum/maximum number of ways
// 3. find the maximum/minimum cost

// Steps to convert a problem to reccurence
// 1.Try to represent the problem in terms of indexes.
// 2. Try all possible choices/ways at every index according to the problem statement.
// 3. If the question states
// Count all the ways - return sum of all choices/ways.
// Find maximum/minimum- return the choice/way with maximum/minimum output.

// Recursion Approach
// Step 1: We will assume n stairs as indexes from 0 to N.

// Step 2: At a single time, we have 2 choices: Jump one step or jump two steps. We will try both of these options at every index.
//  Step 3: As the problem statement asks to count the total number of distinct ways, we will return the sum of all the choices in our recursive function.
// Step 4: The base case will be when we want to go to the 0th and 1st stair, then we have only one option.

// basic recursion
int helper(int i)
{
    // base case: for the 0th and 1st stair there is only one way
    if (i <= 1)
        return 1;

    int left = helper(i - 1);
    int right = helper(i - 2);
    return left + right;
}

int countDistinctWays(int nStairs) { return helper(nStairs); }

// Memoization

int helperMemo(int i, int memo[])
{
    // base case: for the 0th and 1st stair there is only one way
    if (i <= 1)
        return 1;

    if (memo[i] != -1)
        return memo[i];

    int left = helperMemo(i - 1, memo);
    int right = helperMemo(i - 2, memo);
    return memo[i] = (left + right);
}

int countDistinctWays(int nStairs)
{
    int memo[nStairs + 1];
    memset(memo, -1, sizeof(memo));
    return helperMemo(nStairs, memo);
}

// Tabulation Approach
// We will create an array of size N+1 to store the number of ways to reach the ith stair.
// We will initialize the 0th and 1st index with 1 as there is only one way to reach the 0th and 1st stair.
// We will iterate from 2 to N and calculate the number of ways to reach the ith stair by adding the number of ways to reach the (i-1)th and (i-2)th stair.
// Finally, we will return the number of ways to reach the Nth stair.

int countDistinctWays(int nStairs)
{
    int mod = 1e9 + 7;
    int memo[nStairs + 1];

    memset(memo, -1, sizeof(memo));
    memo[0] = 1;
    memo[1] = 1;

    for (int i = 2; i <= nStairs; i++)
    {

        memo[i] = (memo[i - 1] + memo[i - 2]) % mod;
    }
    return memo[nStairs];
}

// Tabulation Space optimization
// We will create three variables to store the number of ways to reach the ith stair, (i-1)th stair, and (i-2)th stair.
// We will initialize the 0th and 1st index with 1 as there is only one way to reach the 0th and 1st stair.
// We will iterate from 2 to N and calculate the number of ways to reach the ith stair by adding the number of ways to reach the (i-1)th and (i-2)th stair.
// Finally, we will return the number of ways to reach the Nth stair.

int countDistinctWays(int nStairs)
{
    int mod = 1e9 + 7;

    int secondLast = 1;
    int last = 1;
    int curr = 0;

    for (int i = 2; i <= nStairs; i++)
    {

        curr = (secondLast + last) % mod;
        secondLast = last;
        last = curr;
    }
    return last;
}
