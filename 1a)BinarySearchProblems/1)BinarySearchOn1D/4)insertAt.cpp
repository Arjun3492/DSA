// Search Insert Position
//Problem statement
// You are given a sorted array 'arr' of distinct values and a target value 'm'.
// You need to search for the index of the target value in the array.

// Note:
// If the value is present in the array, return its index.
// If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order. 

// Link : https://www.codingninjas.com/studio/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813

//Example:
// Input: arr = [1, 3, 5, 6], m = 5
// Output: 2
// Explanation: The value 5 is present at index 2 in the array.

// BRUTE FORCE APPROACH
// We need to find the index of the value >= element to be inserted.
// Since the array is sorted, we can simply iterate through the array and find the first element which is greater than or equal to the target.
// The index of this element will be our answer.
int searchInsert(vector<int> &arr, int m) {
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=m){
            return i;
        }
    }
    return arr.size();
}
//Time Complexity: O(n)
//Space Complexity: O(1)

// OPTIMIZED APPROACH
// We can use binary search to solve this problem
// We need to find the index of the value >= element to be inserted.
int searchInsert(vector<int> &nums, int target) {
  int n = nums.size();
  int low = 0, high = n - 1;
  int posToBeInsertedAt = n;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (nums[mid] >= target) {
      posToBeInsertedAt = mid;
      // we'll look for smaller index on the left
      high = mid - 1;
    } else {
      // reduce the search space to right half
      low = mid + 1;
    }
  }
  return posToBeInsertedAt;
}
//Time Complexity: O(log n)
//Space Complexity: O(1)

