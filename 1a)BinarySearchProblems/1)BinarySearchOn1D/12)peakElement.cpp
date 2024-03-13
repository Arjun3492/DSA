// Find Peak Element
// Problem statement
// You are given an array 'arr' of length 'n'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
// Peak element is defined as that element that is greater than both of its neighbors. If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.
// Assume 'arr[-1]' and 'arr[n]' as negative infinity.

// Note:
// 1.  There are no 2 adjacent elements having same value (as mentioned in the constraints).
// 2.  Do not print anything, just return the index of the peak element (0 - indexed).
// 3. 'True'/'False' will be printed depending on whether your answer is correct or not.

// Example:
// Input: 'arr' = [1, 8, 1, 5, 3]
// Output: 3
// Explanation: There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3.

// Link:https://www.codingninjas.com/studio/problems/find-peak-element_1081482

// Brute Force Approach
// Using Linear Search to find the peak element
// Time complexity: O(n)
// Space complexity: O(1)

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();

    // EDGE CASE:If arr has only one element, or the first element is peak itself
    if (n == 1 || arr[0] > arr[1])
        return 0;

    // EDGE CASE:If the last element is peak itself
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    // Handling inner array
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            return i;
    }
    return -1;
}

// Optimal Approach
// Using Binary Search to find the peak element
// We will use BS to eliminate the half of the array based on the position of the peak element
// Time complexity: O(logn)
// Space complexity: O(1)

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    // EDGE CASE:If arr has only one element, or the first element is peak itself
    if (n == 1 || (arr[0] > arr[1]))
        return 0;
    // EDGE CASE:If the last element is peak itself
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    // Handling inner array
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1]))
            // is peak element
            return mid;
        if (arr[mid - 1] > arr[mid])
        {
            // peak element lies on left half
            high = mid - 1;
        }
        else
        {
            // peak element lies on right half
            low = mid + 1;
        }
    }
}
