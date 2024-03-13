// Find Nth Root Of M
// Problem statement
// You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.
// Note:
// 'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.

// Example:
// Input: ‘n’ = 3, ‘m’ = 27
// Output: 3
// Explanation:
// 3rd Root of 27 is 3, as (3)^3 equals 27.

// Link:https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679

// Brute Force Approach
// Using Linear Search to find the nth root of m
// We will iterate from 1 to m and check if the number raised to the power n is equal to m
// Time complexity: O(m)
// Space complexity: O(1)

int NthRoot(int n, int m)
{
    if (m == 0 || m == 1)
        return m;
    for (int i = 1; i <= m; i++)
    {
        if (pow(i, n) == m)
            return i;
        if (pow(i, n) > m)
            return -1;
    }
    return -1;
}

// Optimal Approach
// Using Binary Search to find the nth root of m
// We will use BS to find the nth root of m
// Time complexity: O(logm)
// Space complexity: O(1)

int NthRoot(int n, int m)
{
    if (m == 1 || m == 0 || n == 1)
        return m;
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        long long temp = pow(mid, n);
        if (temp == m) // If mid is a perfect nth root
            return mid;
        if (temp < m)
        {
            // If mid is less than the nth root of m
            low = mid + 1;
        }
        else
        {
            // If mid is greater than the nth root of m
            high = mid - 1;
        }
    }
    return -1;
}