// Minimum Bit Flips to Convert Number
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

// Example 1:
// Input: start = 2, goal = 6
// Output: 1
// Explanation: There is only one bit difference between 2(0010) and 6(1010): .

// Approach
//  1) we will xor start and goal and store it in a variable
//  2) then we will count the number of set bits in the xor variable
//  3) return the count

int minBitFlips(int start, int goal)
{
    if (start == goal)
        return 0;
    int xorVal = start ^ goal;
    // return __builtin_popcount(xorVal);  // this is a inbuilt function in c++ to count the number of set bits
    int ans = 0;
    while (num)
    {
        if (num & 1)
        {
            ans++;
        }
        num = num >> 1;
    }
    return ans;
}

// Time Complexity: O(logN)
// Space Complexity: O(1)
