// Capacity To Ship Packages Within D Days
// Problem statement:
// You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another.
// The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'weights'.
// The packages are loaded on the conveyor belts every day in the same order as they appear in the array.
// The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

// Example:
// Input: weights = [1,2,3,4,5,6,7,8,9,10], d = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days.

// Link : https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379

// Intuition:
// The search space for the answer is from the low=maximum element in the array to high= sum of the array elements.
// low is the minimum possible capacity and high is the maximum possible capacity.
// inorder to ship all the packages the lowest capacity should be eq to the weight of the heaviest package
// and the highest capacity should be eq to the sum of all the packages in that case the ship will be able to ship all the packages in 1 day.

// The utility function to get the sum of the division's result
bool isPossible(vector<int> &weights, int d, int capacity)
{
    int dailyLoad = 0;
    --d;
    for (int w : weights)
    {
        if (dailyLoad + w <= capacity)
        {
            dailyLoad += w;
        }
        else
        {
            dailyLoad = w;
            --d; // shipped for the current day
        }
    }
    return d >= 0;
}

// BRUTE FORCE
// we will leverage linear search to find the answer
// we will start from low and keep on check if the current capacity is able to ship all the packages in 'd' days
// if it is then we will return the current capacity as the answer
// else we will keep on incrementing the capacity and checking the same

// Time complexity: O(n*(diff)) where diff is the difference between the maximum and minimum element in the array
// Space complexity: O(1)

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(weights, d, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

// OPTIMAL APPROACH:
// We can leverage binary search to find the answer
// We will set low as the minimum element and high as the maximum element in the array
// We will find the mid element and check if this capacity is able to ship all the packages in 'd' days
// if it is then we will update the answer and move to the left half in search of a smaller capacity to ship all the packages in 'd' days
// else we will move to the right half in search of a larger capacity to ship all the packages in 'd' days

// Time complexity: O(nlog(diff)) where diff is the difference between the maximum and minimum element in the array

int leastWeightCapacity(vector<int> &weights, int d)
{
    //   cz inorder to ship all the packages the lowest capacity should be eq to the
    //   weight of the heaviest package
    int low = *max_element(weights.begin(), weights.end());
    // high will be the sum of all elements, as this will be smallest possible
    // value with which we can ship all packages in one day
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        if (isPossible(weights, d, mid))
        {
            // check for a smaller result
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}