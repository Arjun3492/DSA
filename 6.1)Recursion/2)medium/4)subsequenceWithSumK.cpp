// Check if there is a subsequence with sum equal to k
// You are given an array / list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
// Note : Return true if there exists a subset with sum equal to ‘K’.Otherwise,return false.

// For Example : If ‘ARR’ is{1, 2, 3, 4} and ‘K’ = 4,
// then there exists 2 subsets with sum = 4. These are{1, 3} and {4}.Hence, return true.

// Link : https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954

// Intuition
// We will have two choices for each element in the array:
// 1. We can include the element in the subset.
// 2. We can exclude the element from the subset.
// We will make a recursive call for both the choices and keep track of the current sum.
// We will return true if at the end of array the current sum is equal to K.
// else we will return false.
// We will check the reponse of the recursive calls and return true if any of the recursive calls return true.
// Otherwise, we will return false. (means no subset with sum equal to K exists)

// Time complexity: O(2^n)
// Space complexity: O(2^n) [stack space]

#include <bits/stdc++.h>

bool subsetSumToKHelper(int i, int k, int sum, vector<int> &arr)
{
    // Base case
    if (i == arr.size())
    {
        return sum == k;
    }

    // including the ith number in sum
    if (subsetSumToKHelper(i + 1, k, sum + arr[i], arr))
        return true;

    // excluding the ith number from sum
    if (subsetSumToKHelper(i + 1, k, sum, arr))
        return true;

    // If none of the sequences summed up to k
    return false;
}

// Main function
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return subsetSumToKHelper(0, k, 0, arr);
}
