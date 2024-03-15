// Painter's Partition Problem
// Problem statement
// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

// Example :
// Input: arr = [2, 1, 5, 6, 2, 3], k = 2
// Output: 11
// Explanation:
// First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

// Link : https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557

// Intuition
// We are given an array of boards and we have to paint the boards using ‘k’ painters such that the area of the minimum time to get this job done is minimized.
// We know that the minimum possible value of the area of the minimum time to get this job done will be the maximum number in the array and the maximum possible value of the area of the minimum time to get this job done will be the sum of all the elements in the array.
// So for each possible value within the minimum and maximum value of the area of the minimum time to get this job done, we will check if it is possible to paint the boards using ‘k’ painters such that the area of the minimum time to get this job done is the current value.

// Utility function to check if it is possible to paint the boards using ‘k’ painters such that the area of the minimum time to get this job done is the current value.
bool isPossible(vector<int> a, int k, int minTIme)
{
    int boardsPainted = 0;
    int painters = 1;
    for (int i : a)
    {
        if (boardsPainted + i <= minTIme)
        {
            // allocate board to current painter
            boardsPainted += i;
        }
        else
        {
            // allocate board to next painter
            boardsPainted = i;
            painters++;
            if (painters > k) // Check if the painters exceed the given limit
                return false;
        }
    }
    return true;
}

// BRUTE FORCE
// We will iterate over the possible values of the area of the minimum time to get this job done and for each value, we will check if it is possible to paint the boards using ‘k’ painters such that the area of the minimum time to get this job done is the current value.
// If possible we will update the answer and if not then we will keep on checking the same.
// Time complexity: O(n^2)
// Space complexity: O(1)
int findLargestMinDistance(vector<int> &a, int k)
{
    int n = a.size();
    if (k > n + 1) // i.e. k> number of elements
        return -1;
    // min time that is required(Each board is painted by a separate painter, so
    // min time is the time req to paint the largest board)
    int low = *max_element(a.begin(), a.end());
    // max time that is required(if only 1 painter is present i.e. k=1)

    int high = accumulate(a.begin(), a.end(), 0);
    for (int i = low; i < high; i++)
    {
        if (isPossible(a, k, i))
            return i;
    }
}

// OPTIMAL APPROACH
// We will leverage binary search to find the answer.
// We will apply binary search on the possible values of the area of the minimum time to get this job done.
// Time complexity: O(nlogn)
// Space complexity: O(1)

int findLargestMinDistance(vector<int> &a, int k)
{
    int n = a.size();
    if (k > n + 1) // i.e. k> number of elements
        return -1;
    // min time that is required(Each board is painted by a separate painter, so
    // min time is the time req to paint the largest board)
    int low = *max_element(a.begin(), a.end());
    // max time that is required(if only 1 painter is present i.e. k=1)

    int high = accumulate(a.begin(), a.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        if (isPossible(a, k, mid))
        {
            ans = mid;
            high = mid - 1; // check for a smaller possible minTIme
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
