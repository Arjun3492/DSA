// Count Subsets with Sum K
// Problem statement
// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
// Since the number of ways can be very large,print it modulo 10 ^ 9 + 7.

// Link : https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532

// Intuition
// We will have two choices for each element in the array:
// 1. We can include the element in the subset.
// 2. We can exclude the element from the subset.
// We will make a recursive call for both the choices and keep track of the current sum.
// We will return 1 if at the end of array the current sum is equal to K.
// else we will return 0.
// We will add the response of the recursive calls and return it.

// Time complexity: O(2^n)
// Space complexity: O(2^n) [stack space]

int findWaysHelper(vector<int> &arr, int k, int i, int sum)
{
    // Base condition: traversed the entire array
    if (i == arr.size())
    {
        if (sum == k)
            return 1; // returning 1 to account for this subsequnces
        return 0;     // zero otherwise
    }

    // including the ith number in sum
    int first = findWaysHelper(arr, k, i + 1, sum + arr[i]);

    // excluding the ith number from sum
    int second = findWaysHelper(arr, k, i + 1, sum);

    return first + second;
}

int findWays(vector<int> &arr, int k)
{
    return findWaysHelper(arr, k, 0, 0);
}
