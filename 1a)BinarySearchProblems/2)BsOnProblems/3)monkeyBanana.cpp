// Koko Eating Bananas
// Problem statement
// A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

// Example:
// Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7
// Output: 3
// Explanation: If ‘m’ = 3, then
// The time taken to empty the 1st pile is 1 hour.
// The time taken to empty the 2nd pile is 2 hour.
// The time taken to empty the 3rd pile is 1 hour.
// The time taken to empty the 4th pile is 3 hour.
// Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.

// Link : https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064

// Intuition
// We will use a arbitrary function to check if the monkey can eat all the bananas in 'h' hours at a rate of 'm' bananas per hour.

// Funtion to check if the monkey can eat all the bananas in 'h' hours at a rate of 'm' bananas per hour.

int totalHrsTaken(vector<int> v, int c)
{
    int totalHrs = 0;
    for (int i : v)
    {
        totalHrs += ceil((double)(i) / (double)(c));
    }
    return totalHrs;
}

// Brute Force Approach
// Using Linear Search to find the minimum rate to eat bananas
// We will iterate from 1 to the maximum number of bananas in the array and check if the monkey can eat all the bananas in 'h' hours
// Time complexity: O(max(v) *n ), as outer loop runs max(v) times and inner loop(totalHrsTaken) runs n times
// Space complexity: O(1)

int minimumRateToEatBananas(vector<int> v, int h)
{
    int maxBananas = *max_element(v.begin(), v.end());
    for (int i = 1; i <= maxBananas; i++)
    {
        if (totalHrsTaken(v, i) <= h)
        // since we need to find the minimum rate to eat bananas, we will return the first rate at which the monkey can eat all the bananas in 'h' hours
        {
            return i;
        }
    }
    return -1;
}

//  Optimal Approach
//  Using Binary Search to find the minimum rate to eat bananas
//  We will use BS to find the minimum rate to eat bananas
//  Time complexity: O(n*log(max(v))), as we are using binary search to find the minimum rate to eat bananas

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1, high = *max_element(v.begin(), v.end());
    // high is the maximum number of bananas in the array, as the monkey needs to eat atmost that many bananas in an hour to have the minimum rate
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (totalHrsTaken(v, mid) <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}