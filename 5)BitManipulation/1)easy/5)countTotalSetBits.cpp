// Problem statement: Given N, count the total number of set bits for all nums from 1 to N

// Approach 1: Naive Approach
int countSetBits(int N)

{
    // var to store total num of setbits
    int ans = 0;
    if (N == 0)
        // if N is 0
        return 0;

    for (int i = 1; i <= N; i++)
    {
        // traversing from 1 to N, to check for each number
        int num = i;
        while (num)
        {
            // until the current num is not 0 , we iteratively AND with 1 and rightshift it by one to count number of setbits
            if (num & 1)
            {
                // if LSB is 1
                ans++;
            }
            // right shift by 1
            num >>= 1;
        }
    }
    return ans;
}

// Approach 2: Brian Kernighan’s Algorithm
//  Intuition: In this approach, we will use the fact that if we subtract 1 from a number then all the bits after the rightmost set bit will be flipped. For example, if we have 10100 then subtracting 1 from it will give us 10011. Now if we do bitwise & of these two numbers then we will get 10000 which is the number with the rightmost set bit unset. So, we can count the number of times we can perform this operation until the number becomes 0.

int countSetBits(int N)
{
    // var to store total num of setbits
    int ans = 0;
    if (N == 0)
        // if N is 0
        return 0;

    while (N)
    // until N is not 0
    {
        // unset the rightmost set bit
        N = N & (N - 1);
        ans++;
    }
    return ans;
}
