// Factorial of a Number
// Problem statement: Given a number n, find the factorial of n,using recursion.

// Example:
// Input:5
// Output:120
// Explanation:5! = 5*4*3*2*1 = 120

// Link : https://www.codingninjas.com/studio/problems/factorial_975273

// Approach:
// Factorial of a number n is the product of all positive integers less than or equal to n.
// n! = n*(n-1)*(n-2)*...*1
// n! = n*(n-1)!
// Base case: factorial of 0 and 1 is 1
// Recursive case: n! = n*(n-1)!
// Time complexity: O(n)
// Space complexity: O(n)[stack space]
int getFact(int n)
{
    if (n <= 1) // base case, factorial of 0 and 1 is 1
        return 1;
    return n * getFact(n - 1); // as n! = n*(n-1)!
}