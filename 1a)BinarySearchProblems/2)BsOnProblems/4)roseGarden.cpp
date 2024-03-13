// Rose Garden
// Problem statement
// You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.

// Example :
// Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2
// Output: 3.
// Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.

// Link : https://www.codingninjas.com/studio/problems/rose-garden_2248080

// Intuition
// We will use a arbitrary function to check if it is possible to make at least 'm' bouquets each containing 'k' roses in 'x' days.

// Funtion to check if it is possible to make at least 'm' bouquets each containing 'k' roses in 'x' days.
bool isPossible(const vector<int> &arr, int k, int days, int m)
{
    int bouquets = 0;
    int consecutiveFlowers = 0;
    for (int day : arr)
    {
        if (day <= days)
        {
            consecutiveFlowers++;
            if (consecutiveFlowers == k)
            {
                bouquets++;
                consecutiveFlowers = 0;
            }
        }
        else
        {
            consecutiveFlowers = 0;
        }
    }
    return bouquets >= m;
}

// Brute Force Approach
// Using Linear Search to find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses
// We will iterate from 1 to the maximum number of days in the array and check if it is possible to make at least 'm' bouquets each containing 'k' roses in 'x' days
// Time complexity: O(max(arr) * n), as outer loop runs max(arr) times and inner loop runs n times
// Space complexity: O(1)

int roseGarden(const vector<int> &arr, int k, int m)
{

    int maxDays = *max_element(arr.begin(), arr.end());
    for (int i = 1; i <= maxDays; i++)
    {
        if (isPossible(arr, k, i, m))
        {
            return i;
        }
    }
    return -1;
}

// Optimal Approach
// Using Binary Search to find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses
// We will use BS to find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses
// Time complexity: O(n*log(max(arr))), as we are using binary search to find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses
// Space complexity: O(1)

int roseGarden(const vector<int> &arr, int k, int m)
{
    int low = *min_element(arr.begin(), arr.end()), high = *max_element(arr.begin(), arr.end());
    int ans = -1; // Initialize ans to -1, indicating impossibility
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (countBouquets(arr, k, mid, m))
        { // If enough bouquets can be made within 'mid' days
            ans = mid;
            high = mid - 1; // Check for a smaller number of days
        }
        else
        {
            low = mid + 1; // Check for a larger number of days
        }
    }
    return ans;
}