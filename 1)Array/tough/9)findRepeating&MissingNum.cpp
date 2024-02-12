// Find the repeating and missing numbers
// Problem Statement: You are given a read-only array of N integers with values also in the
// range [1, N] both inclusive. Each integer appears exactly once except A which appears twice
// and B which is missing. The task is to find the repeating and missing numbers A and B where
// A repeats twice and B is missing.

// Link:https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164

// Example:
// Input: [3, 1, 2, 5, 3]
// Output: [3, 4]
// Explanation: The repeating number is 3 and the missing number is 4.

// BRUTE FORCE
// Loop from 1 to n and for each number check it's frequency in the array
// Time complexity: O(n^2)
// Space complexity: O(1)
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                count++;
            }
        }
        if (count == 2)
        {
            repeating = i;
        }
        else if (count == 0)
        {
            missing = i;
        }
    }
    return {repeating, missing};
}

// BETTER APPROACH (HASHING)
// We use an array as to hash and store the frequency of each number as we loop through the given array
// Then we loop through the hash array to find the repeating and missing numbers based on the frequency
// Time complexity: O(n)
// Space complexity: O(n)

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    int hashArr[n + 1] = {0};
    for (int i : a)
    {
        hashArr[i]++;
    }
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hashArr[i] == 0)
            missing = i;
        else if (hashArr[i] == 2)
            repeating = i;
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}

// OPTIMAL APPROACH
//  We will xor all the elements of the array with all the numbers from 1 to n
//  Then find the mask with set bit as the rightmost set bit of the xor value
// based on this mask we can divide the numbers into two groups
//  one group with the set bit at the rightmost position and the other group with the rightmost bit not set
// we will make two xor variables "xorRepeating" and "xorMissing" to separately xor the elements of the array and the numbers from 1 to n based on AND operation with the mask
// one of the xor variable will have the repeating number and the other will have the missing number
// Time complexity: O(n)
// Space complexity: O(1)

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    int _xor = 0;
    for (int i : a)
    {
        _xor ^= i;
    }
    // finding the mask with set bit at position where the _xor value is set
    int mask = (_xor & ~(_xor - 1));

    // separately xoring value with set and unset bit
    int xorRepeating = 0, xorMissing = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i & mask) != 0)
        {
            xorRepeating ^= i;
        }
        else
        {
            xorMissing ^= i;
        }
        if ((a[i - 1] & mask) != 0)
        {
            xorRepeating ^= a[i - 1];
        }
        else
        {
            xorMissing ^= a[i - 1];
        }
    }
    int cnt = 0;
    for (int i : a)
    {
        if (i == xorRepeating)
            cnt++;
    }

    if (cnt == 2)
        return {xorRepeating, xorMissing};
    return {xorMissing, xorRepeating};
}