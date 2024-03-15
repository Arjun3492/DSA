// Aggressive Cows
// Problem statement
//  You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
//  You are also given an integer 'k' which denotes the number of aggressive cows.
//  You are given the task of assigning stalls to 'k' cows such that the minimum
//  distance between any two of them is the maximum possible.
//  Print the maximum possible minimum distance.

// Example:
//  Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
//  Output: 2
//  Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

// Link : https://www.codingninjas.com/studio/problems/aggressive-cows_1082559

// Intuition
//  We are given an array of stalls and we have to place 'k' cows in such a way that the minimum distance between any two cows is maximum.
//  So we know that the minimum distance between any two cows will be 1 and the maximum distance will be the distance between the first and the last stall.
// So for each possible value within the minimum and maximum distance, we will check if it is possible to place 'k' cows such that the minimum distance between any two cows is the current value.
//  If it is possible then we will try to maximize the minimum distance and if it is not possible then we will try to the left value.

// Utility function to check if it is possible to place 'k' cows such that the minimum distance between any two cows is the current value.

bool isPossible(vector<int> &stalls, int cows, int dist)
{
    int n = stalls.size(); // size of array
    cows--;                // first cow placed
    int last = stalls[0];  // position of last placed cow.
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cows--;           // place next cow.
            last = stalls[i]; // update the last location.
        }
        if (cows <= 0)
            return true;
    }
    return false;
}

//  BRUTE FORCE
//  We will iterate over the possible values of the minimum distance and for each value, we will check if it is possible to place 'k' cows such that the minimum distance between any two cows is the current value.
// If possible we will update the answer and if not then we will keep on checking the same.
//  Time complexity: O(n^2)
//  Space complexity: O(1)

int aggressiveCows(vector<int> &stalls, int k)
{

    int n = stalls.size();
    // sorting the arr so that we only have to compute
    // the distance between adjacent stalls as we only need to find the min
    // distance between stalls
    sort(stalls.begin(), stalls.end());

    int minDistPossible = 1;                         // minimum possible distance between any two cows.
    int maxDistPossible = stalls[n - 1] - stalls[0]; // maximum possible distance between any two cows.
    int maxPossibleMinDist = -1;
    for (int i = minDistPossible; i <= maxDistPossible; i++)
    {
        if (isPossible(stalls, k, i))
        {
            maxPossibleMinDist = i; // since we need the maximum distance , we will update the answer whenever we find a newer possible value.
        }
        else
            return maxPossibleMinDist;
    }
}

//  OPTIMAL APPROACH
//  We will leverage binary search to find the answer.
//  We will apply binary search on the possible values of the minimum distance between any two cows.
//  For each value, we will check if it is possible to place 'k' cows such that the minimum distance between any two cows is the current value.
//  If it is possible then we will try to maximize the minimum distance and if it is not possible then we will try to minimize the minimum distance.
// Time complexity: O(nlog(n))
// Space complexity: O(1)
int aggressiveCows(vector<int> &stalls, int k)
{

    // sorting the arr so that we only have to compute
    // the distance between adjacent stalls as we only need to find the min
    // distance between stalls
    sort(stalls.begin(), stalls.end());

    //  the min possible distance , between any two cows is one
    int low = 1;
    // the max possible distance would be the range within the arr
    int high = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    while (low <= high)
    {
        int minDist = high - (high - low) / 2;
        if (isPossible(stalls, k, minDist))
        {
            ans = minDist;
            low = minDist + 1; // check for a higher possible value
        }
        else
        {
            high = minDist - 1; // trim the right search space
        }
    }
    return ans;
}
