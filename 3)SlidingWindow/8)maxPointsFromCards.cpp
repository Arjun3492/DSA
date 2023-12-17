// Maximum Points From Cards
// Problem statement: You have several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// Examples:
// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score.
// The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.

int maxPoints(vector<int> &arr, int K)
{
    int cnt = 0;
    int l = 0;              // Start of window
    int r = arr.size() - K; // End of the K-sized window
    int sum = 0;

    // Calculate the sum of the first K elements
    for (int i = r; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int total = sum;

    // Sliding window
    while (r < arr.size())
    {
        total = total - arr[r] + arr[l]; // Update the sum for the current window
        sum = max(sum, total);           // Update the maximum sum
        r++;
        l++;
    }

    return sum;
}