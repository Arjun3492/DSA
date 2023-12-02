// Problem statement: Given N, count the total number of set bits for all nums from 1 to N

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