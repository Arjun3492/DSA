// Search In Rotated Sorted Array

//Problem statement
// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
// Now the array is rotated at some pivot point unknown to you.

// For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].
// Now, your task is to find the index at which ‘k’ is present in 'arr'.

//Link :https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554

// APPROACH :Using Binary Search
// Intuition: The array can be divided into two parts. The left part and the right part. One of the parts will always be sorted.
// We can use binary search to find the element in the sorted part and then check if the element is present in the sorted part or not.
// If the element is present in the sorted part then we can use binary search to find the element in the sorted part.
// If the element is not present in the sorted part then we can use binary search to find the element in the unsorted part.


int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = high - (high - low) / 2;
        if (arr[mid] == k) {
            return mid;
        }
        if (arr[low] <= arr[mid]) //checking if the left part is sorted
        {
            
            if (arr[low] <= k && k <= arr[mid])//checking if the element is present in the left part
             {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else //if the right part is sorted
        {
            if (arr[mid] <= k && k <= arr[high])//checking if the element is present in the right part
             {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}