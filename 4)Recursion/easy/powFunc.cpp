// Problem statement: implement the pow function

// Solution: use recursion
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    return n > 0 ? x * myPow(x, n - 1) : (1 / x) * myPow(x, n + 1);
}

// Time complexity: O(n)
// Space complexity: O(n)[stack space]

// Solution: use recursion and binary search
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    double temp = myPow(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else if (n > 0)
        return x * temp * temp;
    else
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
        {
            ans *= x;
            nn--;
        }
        else
        {
            x *= x;
            nn /= 2;
        }
    }
    if (n < 0)
        return 1 / ans;
    return ans;
}

// Time complexity: O(logn)
// Space complexity: O(1)
