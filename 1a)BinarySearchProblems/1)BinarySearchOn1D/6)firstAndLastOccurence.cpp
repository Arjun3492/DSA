// First and Last Position of an Element In Sorted Array
//Problem statement
// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
// Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
// 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. 'arr' may contain duplicate elements.

//Example
// Input: 'arr' = [0,1,1,5] , 'k' = 1
// Output: 1 2
// Explanation:
// If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

//Link:https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

// APPROACH 1: Using lower_bound and upper_bound
// Since we know that lower_bound of a number is smallest index i such that arr[i] >= k and upper_bound of a number is the smallest index i such that arr[i] > k
// We can use lower_bound to find the first occurrence of the element and upper_bound to find the last occurrence of the element.
// Where first occurrence is the index returned by lower_bound and last occurrence is the index returned by upper_bound - 1

// Time complexity: O(2*logn)
// Space complexity: O(1)

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
    int first = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
    if (first > last) {
        return {-1, -1};
    }
    return {first, last};
}


// APPROACH 2: Using Binary Search
// We can use binary search to find the first and last occurrence of the element in the array.
// We can find the first occurrence of the element by finding the element in the array and then checking if the element before it is not equal to the element.
// We can find the last occurrence of the element by finding the element in the array and then checking if the element after it is not equal to the element.

//First Occurence
int firstPos(vector<int> &arr, int n, int target) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (arr[mid] < target) {
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid - 1;
    } else {
        //if mid is not 0 and the element before mid is equal to the target then then it means that the first occurence is before mid
      if (mid != 0 && arr[mid - 1] == target) {
        high = mid - 1;
      } else
        return mid; // this is first occurence
    }
  }
  return -1;
}
int secondPos(vector<int> &arr, int n, int target) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (arr[mid] < target) {
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid - 1;
    } else {
        //if mid is not n-1 and the element after mid is equal to the target then then it means that the second occurence is after mid
      if (mid != n - 1 && arr[mid + 1] == target) {
        low = mid + 1;
      } else
        return mid; // this is last occurence
    }
  }
  return -1;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
  return make_pair(firstPos(arr, n, k), secondPos(arr, n, k));
}

