// Check if a number is prime or not
//  Problem Statement:Given a number N, check if it is prime or not.

// Approach 1: Naive Approach
// Time complexity:O(sqrt(n))
// Space complexity:O(1)

bool isPrime(int N)
{
    if (N == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(N); i++)
    // the loop will run till sqrt(n) because if a number is composite then it will have atleast one factor less than or equal to sqrt(n),as after that the factors will repeat
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}