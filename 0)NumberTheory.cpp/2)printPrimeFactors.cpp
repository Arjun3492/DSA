// Return prime factors of a number
//  Problem Statement:Given a number N, print all its unique prime factors in increasing order.

// Approach 1: Naive Approach
// Time complexity:O(sqrt(n))
// Space complexity:O(1)

vector<int> countPrimes(int n)
{
    vector<int> primes;
    for (int i = 2; i <= sqrt(n); i++)
    // the loop will run till sqrt(n) because if a number is composite then it will have atleast one factor less than or equal to sqrt(n),as after that the factors will repeat
    {
        while (n % i == 0)
        {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    // if the current n is prime,then it will escape the above loop,as it will not have any factor less than or equal to sqrt(n),
    // so we need to check for it
    {
        primes.push_back(n);
    }
    return primes;
}
