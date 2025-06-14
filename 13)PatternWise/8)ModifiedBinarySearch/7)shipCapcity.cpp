// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution
{
private:
    // Helper function to check if it's possible to ship all weights
    // within 'd' days using the given ship capacity 'cap'
    bool canShip(vector<int> &w, int cap, int d)
    {
        int sum = 0;       // total weight loaded on the current day
        int totalDays = 1; // start with day 1

        for (int i : w)
        {
            // If any individual package weight exceeds capacity, it's impossible
            if (i > cap)
                return false;

            // If adding current weight exceeds today's capacity,
            // start a new day and assign this weight to the new day
            if (sum + i > cap)
            {
                totalDays++; // new day
                sum = i;     // start new day's load with current weight
            }
            else
            {
                sum += i; // add current weight to today's load
            }
        }

        // Return true if total days needed is within allowed limit
        return totalDays <= d;
    }

    // Intuition, we will traverse lineraly from the min to max weight capacity and
    //  check for feasibility for each of the weight capacity to ship within d days
    // and return the minimum feasible weight capacity
    int brute(vector<int> &weights, int days)
    {
        // we will take 1 as the lower bound of weight capacity
        int min_weight = 1;
        // int max_weight= accumulate(weights.begin(),weights.end(),0);
        // max weight capacity would be total of all weights, but we will take INT_MAX
        // to prevent the O(N) complexity to find max weights as we will traverse
        // from lower to upper bound we will eventually find the least possible one
        int max_weight = INT_MAX;

        for (int i = min_weight; i <= max_weight; i++)
        {
            int capacity = i;
            if (canShip(weights, capacity, days))
            {
                return capacity;
            }
        }
        return -1;
    }

    // Using BS algo to reduce the search space to find the min possible capacity
    int optimal(vector<int> &w, int d)
    {

        int s = 1;
        int e = accumulate(w.begin(), w.end(), 0);

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (canShip(w, m, d))
            {
                e = m; // could be possible answer, but will continue to find a lower value
            }
            else
            {
                s = m + 1;
            }
        }
        // at the end of iteration s==e and will be at the lowest possible weight capacity
        return s;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        return optimal(weights, days);
    }
};