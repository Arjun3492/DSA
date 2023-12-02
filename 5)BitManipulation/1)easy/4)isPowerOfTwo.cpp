// Problem Statement:check if the given num is power of 2

// Intuition if that for a number  'n' that is power of 2
// n AND n-1 is always 0

// Relation between n and n-1 is that starting from the right most set bit(bit that is 1), all bits are reversed
// Eg: 12 :1100
// 11: 1011  (starting from the right most set bit(bit that is 1), all bits are reversed)

// so now we know that for a num that is power of 2 , all its bits are 0 except the MSB
// so the bits of num-1 will have all bits as 1, except MSB
// taking AND of n and n-1 we will get 0, if n is power of 2

// eg:n=4
// 4: 100
// 4-1=3: 011
// 4 AND 3 =0
bool isPowerOfTwo(int n)
{
    return !(n & (n - 1));
}