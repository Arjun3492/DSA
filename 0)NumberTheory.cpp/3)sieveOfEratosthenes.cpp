// Find all the prime numbers less than or equal to n using sieve of eratosthenes
//   Problem Statement:Given a number N, print all primes smaller than or equal to N. It is also given that N is a small number.

// Approach 1: Naive Approach
// Time complexity:O(n*sqrt(n))
// Space complexity:O(1)

// Approach 2: Sieve of Eratosthenes
// Time complexity:O(n*log(log(n)))
// Space complexity:O(n)

vector<int> sieveOfEratosthenes(int n)
{
    vector<int> ans;
    vector<bool> isPrime(n, false);
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime[i])
        {
            ans.push_back(i);
            for (int j = i * i; j <= n; j += i)
            // we are starting from i*i because all the numbers before that will already be marked by their factors less than i
            {
                isPrime[j] = true;
            }
        }
    }
    return ans;
}