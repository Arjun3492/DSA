// Count Distinct Subarrays With At Most K Odd Elements

// Problem statement:You are given an array of integers and an integer k. Find the number of subarrays with at most k odd elements.

// Examples:
// Input: arr = [2,2,5,6], k = 1
// Output: 4
// Explanation: The subarrays with at most 1 odd elements are [2], [2], [2,2], [5].

// Input: arr = [2,2,6,5,6], k = 1
// Output: 9
// Explanation: The subarrays with at most 1 odd elements are [2], [2], [2,2], [6], [5], [6], [2,2,6], [2,6,5], [6,5].

// Approach: Sliding window

// solve function: This function calculates the total number of subarrays with at most k odd numbers.
int solve(vector<int> &arr, int k)
{
    int l = 0, c = 0, total = 0;
    // l and r are the left and right pointers of the current subarray.
    // c keeps track of the count of odd numbers in the current subarray.

    for (int r = 0; r < arr.size(); r++)
    // The loop iterates through the array, updating c and adjusting the window size accordingly.

    {
        if (arr[r] % 2 != 0)
            c++;
        while (c > k)
        {
            if (arr[l] % 2 != 0)
                c--;
            l++;
        }
        total += r - l + 1;
        // total accumulates the count of subarrays with at most k odd numbers.
    }
    return total;
}

// distinctSubKOdds function: This function calls solve twice, once with parameter k
// and once with k-1, and then calculates the difference to get the count of distinct
// subarrays with exactly k odd numbers.
int distinctSubKOdds(vector<int> &arr, int k)
{
    return solve(arr, k) - solve(arr, k - 1);
}