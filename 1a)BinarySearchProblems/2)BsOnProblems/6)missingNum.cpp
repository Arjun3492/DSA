// Kth Missing Positive Number
// Problem statement
// You are given a strictly increasing array 'vec' and a positive integer 'k'.
// Find the 'kth' positive integer missing from 'vec'.

// Example : Input : vec = [ 2, 4, 5, 7 ],
// k = 3
// Output : 6
// Explanation : In the given example,
// first missing positive integer is 1 second missing positive integer is 3, and the third missing positive integer is 6. Hence the answer is 6.

// Link :https://www.codingninjas.com/studio/problems/kth-missing-element_893215

// Intuition
// In a normal array all the numbers the nth number will appear at the (n)th index[1-based indexing].
// For example, in the array [1,2,3,4,5] the 3rd number is 3 and it is present at the 3rd index.
// But in the given array the numbers are missing and the array is strictly increasing.
// So , nth number will appear at (n-b)th index where b is the number of missing numbers before the nth number.
// For example, in the array [2,4,5,7] 7 is appearing at the 4th index[1-based indexing] as 3 numbers are missing before 7 ,i.e, 1,3,6.

// BRUTE FORCE
//  we will iterate over the array and keep on checking if the current number is missing or not.
//  if it is missing then we will decrement k and if k becomes 0 then we will return the current number as the answer.
//  else we will keep on checking the same.
//  Time complexity: O(n)
//  Space complexity: O(1)

int missingK(vector<int> arr, int n, int k)
{
    int i = 0;
    int j = 1;
    while (i < n && k > 0)
    {
        if (arr[i] == j)
        {
            i++;
            j++;
        }
        else
        {
            k--;
            j++;
        }
    }
    return j + k - 1;
}

// The above approach is a brute force approach and it is not leveraging the fact that the array is strictly increasing.

// OPTIMAL
// We will leverage binary search to find the answer.
// We will apply binary search on the indices of the given array. For each index, we will calculate the number of missing numbers and based on it, we will try to eliminate the halves.
// After completing the binary search on the indices, the pointer high will point to the closest neighbor(present in the array) that is smaller than the kth missing number.
// So, the answer will be low+k as the kth missing number will be present between the low and high indices.
// Time complexity: O(log(n))
// Space complexity: O(1)

int missingK(vector<int> arr, int n, int k)
{
    int low = 0;
    int high = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] - (mid + 1) >= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low + k;
}
