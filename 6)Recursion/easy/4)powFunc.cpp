// Problem statement: implement the pow function
// Link: https://www.codingninjas.com/studio/problems/find-x-raised-to-power-n-_626560

// Solution: using simple recursion
// We will multiply x with itself n times if n is positive
// and divide x by itself n times if n is negative
// Time complexity: O(n)
// Space complexity: O(n)[stack space]
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    return n > 0 ? x * myPow(x, n - 1) : (1 / x) * myPow(x, n + 1);
}

// Time complexity: O(n)
// Space complexity: O(n)[stack space]

// Solution: use recursion
// Since we know that x^n = x^(n/2) * x^(n/2) if n is even
// and x^n = x * x^(n/2) * x^(n/2) if n is odd
// we can use this property to reduce the number of multiplications
// and hence reduce the time complexity
// Time complexity: O(logn)
// Space complexity: O(logn)

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    double temp = myPow(x, n / 2);
    if (n % 2 == 0) // if n is even
        return temp * temp;
    else if (n > 0) // if n is odd and positive
        return x * temp * temp;
    else // if n is odd and negative
        return (1 / x) * temp * temp;
}

// Time complexity: O(logn)
// Space complexity: O(logn)

// Solution: use iteration and binary search
double myPow(double x, int n)
{
    double ans = 1;
    long long nn = n;
    if (nn < 0)
        nn *= -1;
    while (nn > 0)
    {
        if (nn % 2 == 1)
        { // if n is odd, multiply x with ans once and reduce n by 1
            ans *= x;
            nn--;
        }
        else
        { // if n is even, multiply x with x and reduce n by 2
            x *= x;
            nn /= 2;
        }
    }
    if (n < 0) // if n is negative, return 1/ans
        return 1 / ans;
    return ans;
}

// Time complexity: O(logn)
// Space complexity: O(1)
