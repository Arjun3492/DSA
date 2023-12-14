// Two Numbers With Odd Occurrences

// Problem statement:Given an array of positive integers. All numbers occur even number of times except two numbers which occurs odd number of times. Return the two numbers in decreasing order.

// Approach 1: Using Hashing
// Time complexity:O(n)
// Space complexity:O(n)

// Approach 2: Using Bit Manipulation
// Time complexity:O(n)
// Space complexity:O(1)

vector<int> twoOddNum(vector<int> arr)
{

    int xorr = 0;

    // xor of all arr elements

    for (int i = 0; i < arr.size(); i++)
    {

        xorr ^= arr[i];
    }

    // rightmost set bit

    int rset = xorr & (~(xorr - 1));

    // partition in groups

    int ans1 = 0;

    int ans2 = 0;

    for (int i : arr)
    {

        if (i & rset)
        {

            ans1 ^= i;
        }

        else
        {

            ans2 ^= i;
        }
    }

    return {max(ans1, ans2), min(ans1, ans2)};
}