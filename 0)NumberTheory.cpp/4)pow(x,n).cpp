// Implement pow(x, n), which calculates x raised to the power n

// Approach 1: By folding the power
//  Time complexity:O(n)
//  Space complexity:O(1)

int power(int x, int n)
{

    int ans = 1;

    long nn = n;
    if (n < 0)
    {
        nn = -1 * nn;
    }

    while (nn)
    {
        if (nn % 2 == 0)
        {
            // even, so we can fold the power by half and multiply the base with itself to get the same result
            // for eg: 2^4 = 2*2 ^ 4/2
            x *= x;
            nn /= 2;
        }
        else
        {
            // if odd, we can write it as x^n = x * x^(n-1)
            // so we can multiply the ans with the base and reduce the power by 1
            ans *= x;
            nn -= 1;
        }
    }

    if (n < 0)
    {
        return (1.0 / ans);
    }

    return ans;
}

// Approach 2: Using Divide and Conquer
//  Time complexity:O(log(n))
//  Space complexity:O(log(n))

int power(int x, int n)
{

    if (n == 0)
    {
        return 1;
    }

    int temp = power(x, n / 2);

    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return x * temp * temp;
    }
}
