// Implement Upper Bound
//Problem statement
// You are given a sorted array ‘arr’ containing ‘n’ integers and an integer ‘x’.
// Implement the ‘upperBound’ function to find the index of the upper bound of 'x' in the array.

// Link : https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383

//Example:
// Input : ‘arr’ = {2,4,6,7} and ‘x’ = 5,
// Output: 2
// Explanation: The upper bound of 5 is 6 in the given array, which is at index 2 (0-indexed).

// BRUTE FORCE APPROACH
// We need to find the index of the smallest element which is greater than the target.
// Since the array is sorted, we can simply iterate through the array and find the first element which is greater than the target.
// The index of this element will be our answer.
int upperBound(vector<int> &arr, int x, int n) {
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            return i;
        }
    }
    return n;
}
//Time Complexity: O(n)
//Space Complexity: O(1)


// OPTIMIZED APPROACH
// We can use binary search to solve this problem
// We need to find the index of the smallest element which is greater than the target.
int upperBound(vector<int> &arr, int x, int n) {
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (arr[mid] > x) {
      ans = mid;
      // we'll look for smaller index on the left
      high = mid - 1;
    } else {
      // reduce the search space to right half
      low = mid + 1;
    }
  }
  return ans;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)
