// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas

class Solution
{

private:
    // Intuition:
    //  the min possible speed K is 1,
    //  The  max possible speed is the max num of bananas in a pile giving the max speed K
    //  We will utilize BS technique to find if a mid number is be used to eat all bananas within
    //  h hours, if yes we will move to a smaller value of K, by moving to left half
    //  or move to a greater value ,that is on right half
    //  Note: we need to write the helper function  to check if a given K speed is feasible or not

    // Helper function
    //  for a given K the number of hours to eat a pile will be given by ceil of
    // quotient when pile is divided by k
    bool canEat(int K, int h, vector<int> &piles)
    {
        int totalHours = 0;

        for (int pile : piles)
        {
            // type cast to double to ensure we don't get floor value due to integer
            totalHours += ceil((double)pile / K);

            if (totalHours > h)
                return false;
        }

        return totalHours <= h;
    }

    // Brute force solution
    // 1. Start with K = 1 and increment it until we find a K that can eat all bananas in h hours
    // 2. For each K, calculate the total hours needed to eat all piles
    // 3. If total hours <= h, return K
    // TC: O(N * k) where N is the number of piles and k is the number of hours
    int brute(vector<int> &piles, int h)
    {
        int K = 1;
        while (true)
        {
            if (canEat(K, h, piles))
            {
                return K;
            }
            K++;
        }
    }

    // TC: O(N * log(max(piles)))
    //  where N is the number of piles and max(piles) is the maximum number of bananas in a pile
    //  SC: O(1) as we are using constant space
    int optimal(vector<int> &p, int h)
    {
        int n = p.size();
        // setting the search space for K
        // 1. The minimum speed K can be 1
        // 2. The maximum speed K can be the max number of bananas in a pile
        int s = 1, e = *max_element(p.begin(), p.end());

        // Binary search to find the minimum K
        // 1. If canEat(mid) is true, then we can try to find a smaller K
        // 2. If canEat(mid) is false, then we need to increase K
        while (s < e)
        {
            int m = s + (e - s) / 2;
            // Tc: O(N) for canEat function
            if (canEat(m, h, p))
            {
                // find a smaller value of K
                e = m;
            }
            else
            {
                // find a greater value of K
                s = m + 1;
            }
        }
        // At the end, s == e and points to the minimum K that can eat all bananas in h hours
        return s;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        return optimal(piles, h);
    }
};