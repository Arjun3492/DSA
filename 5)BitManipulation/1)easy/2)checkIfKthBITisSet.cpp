// Check if Kth bit is set or not
//  Problem Statement: Check if kth bit is set or not.

bool approach1(int n, int k)
{
    // creating mask with 1 at target position, by left shifting 1 (0001) by k-1 position
    int mask = 1 << (k - 1);
    // on taking AND of mask and num ,if it is non-zero meaning bit at kth pos was 1
    return (n & mask) != 0;
}
bool approach2(int n, int k)
{
    // right shifting n by k-1 position , to place the target position bit at LSB
    // then taking AND with 1 , to check if the target bit is 1 or 0
    n = n >> (k - 1);
    return n & 1;
}
