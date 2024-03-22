// Sum Of First N Numbers
// Problem statement: Given a number n, find the sum of first n numbers,using recursion.

// Link: https://www.codingninjas.com/studio/problems/sum-of-first-n-numbers_8876068

// Example:
// Input:5
// Output:15
// Explanation:1+2+3+4+5 = 15

// Solution:
int sumFirstN(int n)
{
    if (n == 0) // base case, sum of 0 numbers is 0
        return 0;
    return n + sumFirstN(n - 1); // as sum of n numbers = n + sum of n-1 numbers
}