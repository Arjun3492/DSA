// Smallest divisor
// Problem statement
// You are given an array of integers 'arr' and an integer 'limit'.
// Your task is to find the smallest positive integer divisor,
// such that upon dividing all the elements of the given array by it,
// the sum of the division's result is less than or equal to the given integer's limit.

// Note:
// Each result of the division is rounded to the nearest integer greater than or equal to
// that element. For Example, 7/3 = 3.

// Example :
// Input : arr= 1 2 3 4 5 , limit = 8
// Output : 3
// Explanation :
// We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.
// The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor, and the sum is 7(1 + 1 + 1 + 2 + 2) if we choose 3 as a divisor, which is less than the 'limit'.
// Hence we return 3.

// Link:https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882

// Intuition
// We have to first find the search space for the answer. The search space is from minimun element to the maximum element in the array.
// Since the answer is a divisor of the sum of the array elements, so the minimum value will give the largest possible result and the maximum value will give the smallest possible result.

// The utility function to get the sum of the division's result
int getDivisionSum(vector<int> &arr, int divisor)
{
    int sum = 0;
    for (int i : arr)
    {
        sum += ceil((double)(i) / (double)(divisor));
    }
    return sum;
}

// BRUTE FORCE
// we will leverage linear search to find the answer
// we will start from the minimum element and keep on checking if the sum of the division's result is less than or equal to the given integer's limit.
// if it is then we will return the divisor as the answer
// else we will keep on incrementing the divisor and checking the same

// Time complexity: O(n*(diff)) where diff is the difference between the maximum and minimum element in the array
// Space complexity: O(1)

int smallestDivisor(vector<int> &arr, int limit)
{
    int minElement = *min_element(arr.begin(), arr.end());
    int maxElement = *max_element(arr.begin(), arr.end());
    int divisor = minElement;
    while (divisor <= maxElement)
    {
        if (getDivisionSum(arr, divisor) <= limit)
        {
            return divisor;
        }
        divisor++;
    }
    return -1;
}

// OPTIMAL APPROACH:
// We can leverage binary search to find the answer
// We will set low as the minimum element and high as the maximum element in the array
// We will keep on checking the sum of the division's result for the mid element
// if it is less than or equal to the given integer's limit then we will update the answer and move to the left half
// else we will move to the right half in search of a larger divisor to get a smaller sum of the division's result which is less than or equal to the given integer's limit

// Time complexity: O(nlog(diff)) where diff is the difference between the maximum and minimum element in the array
// Space complexity: O(1)

int smallestDivisor(vector<int> &arr, int limit)
{
    // finding the max element of the array since this is the
    // smallest element which when divides all the arr elements
    //  the sum of the divison's would be the smallest (and the sum would be equal
    //  to 1*size_of_array)
    int maxEl = *max_element(arr.begin(), arr.end());

    // the min element will give the largest possible result
    int minEl = *min_element(arr.begin(), arr.end());

    int low = minEl, high = maxEl;
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        if (getDivisionSum(arr, mid) <= limit)
        {
            high = mid - 1; // searching for more smaller possible values
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}
