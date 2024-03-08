// Number of occurrence
//Problem statement
// You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.
// Find the total number of occurrences of 'x' in the array/list.

// Example:
// Input: 'n' = 7, 'x' = 3
// 'arr' = [1, 1, 1, 2, 2, 3, 3]
// Output: 2
// Explanation:
// The total number of occurrences of 3 in the array is 2.

//Link : https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456

// APPROACH : Finding the first and last occurrence of the element 

// Time complexity: O(logn)
// Space complexity: O(1)

int count(vector<int> &arr, int n, int x) {
    int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
    if (first > last) {
        return 0;
    }
    return last - first + 1;
}


