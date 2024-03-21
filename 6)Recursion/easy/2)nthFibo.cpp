// N-th Fibonacci Number
// Problem statement: Given a number n, find the n-th Fibonacci number,using recursion.

// Link: https://www.codingninjas.com/studio/problems/nth-fibonacci-number_1115780
// Example:
// Input: 5
// Output: 3
// Explanation: 5th Fibonacci number is 3, as 0,1,1,2,3

// Solution:
// The Fibonacci series is a series of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1.
// The Fibonacci sequence is defined by the recurrence relation:
// F(n) = F(n-1) + F(n-2)
// with seed values
// F(0) = 0 and F(1) = 1
// The Fibonacci numbers are the numbers in the following integer sequence.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
// Time complexity: O(n)
// Space complexity: O(n)[stack space]

#include <bits/stdc++.h>
int getFibo(int n, int firstNumber, int secondNumber, int i = 1)
{
    if (n == 0) // base case, 0th Fibonacci number is 0
        return 0;
    if (n == 1 || n == 2) // base case, 1st and 2nd Fibonacci number is 1
        return 1;
    if (i == n) // if we have reached the nth number
        return secondNumber;

    secondNumber += firstNumber; // next element = first number +second number

    // setting firstNumber as the previous secondNumber(older value of secondNumber)
    firstNumber = secondNumber - firstNumber;

    return getFibo(n, firstNumber, secondNumber, ++i); // recursive call
}
int fibonacciNumber(int n)
{
    return getFibo(n, 0, 1); // initial values of first and second number
}