// Square Root of a number
// Problem statement
// You are given a positive integer ‘n’.
// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

// Example:
// Input: ‘n’ = 7
// Output: 2

// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.

// Link:https://www.codingninjas.com/studio/problems/square-root-integral_893351

// Brute Force Approach
// Using Linear Search to find the square root of a number
// We will iterate from 1 to n and check if the square of the number is equal to n
// Time complexity: O(n)
// Space complexity: O(1)

int floorSqrt(int n)
{
    if (n == 0 || n == 1)
        return n;
    for (int i = 1; i <= n; i++)
    {
        if (i * i == n)
            return i;
        if (i * i > n)
            return i - 1;
    }
    return -1;
}

// Optimal Approach
// Using Binary Search to find the square root of a number
// We will use BS to find the square root of a number
// Time complexity: O(logn)
// Space complexity: O(1)

int floorSqrt(int n)
{
    // EDGE CASE:If n is 0 or 1
    if (n == 0 || n == 1)
        return n;
    int low = 1, high = n, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid == n)
            return mid; // If mid is a perfect square
        if (mid * mid < n)
        {
            // If mid is less than the square root of n
            // We update the answer and move to the right half,to check
            // for a larger number which is less than the square root of n
            low = mid + 1;
            ans = mid;
        }
        else
        {
            // If mid is greater than the square root of n
            // We move to the left half to check for a smaller number
            high = mid - 1;
        }
    }
    return ans;
}