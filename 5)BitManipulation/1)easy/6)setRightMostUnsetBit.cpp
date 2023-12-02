// Problem Statement:To set the rightmost unset bit of given number , if all bits are set return the number as it is

// Intuition: creating a mask with setbit at the position where the number has the rightmost unset bit
int setBits(int N)
{
    int count = 0;
    int temp = N;
    while (temp)
    {
        // increasing the count
        count++;
        if ((temp & 1) == 0)
            // if unset bit is encountered , we break out from loop
            break;
        temp >>= 1;
    }
    // creating mask with setbit at target position
    int mask = (1 << count - 1);
    return (N | mask);
}