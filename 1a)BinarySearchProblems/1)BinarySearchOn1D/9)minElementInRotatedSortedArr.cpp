// Find Minimum in Rotated Sorted Array
//Problem statement
// You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.
// The rotation involves shifting every element to the right, with the last element moving to the first position. For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].
// Your task is to find the minimum number in this array.
// Note :
// All the elements in the array are distinct. 

// Example :
// Input: arr = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] and it was rotated 3 times.

//Link : https://www.codingninjas.com/studio/problems/rotated-array_1093219

// BRUTE FORCE APPROACH:Liner Search
// We can simply iterate through the array and find the minimum element in the array.
// Time complexity: O(n)
// Space complexity: O(1)

int findMin(vector<int> &arr) {
    int n = arr.size();
    int mini = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mini) {
            mini = arr[i];
        }
    }
    return mini;
}

// OPTIMAL APPROACH:Using Binary Search
// Take a variable ans to store the minimum element in the array.
// Using BS we will pick the smallest element from the sorted half and eliminate this sorted half from the search space.
// We will keep on updating the ans variable with the minimum element.
// Time complexity: O(logn)
// Space complexity: O(1)

int findMin(vector<int> &arr) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (arr[low] < arr[mid]) {
      // left half is sorted
      ans = min(ans, arr[low]); //As the left half is sorted, the minimum element will be at the start of the left half
      low = mid + 1;//eliminating left half
    } else {
      // right half is sorted
      ans = min(ans, arr[mid]); //As the right half is sorted, the minimum element will be at the start of the right half
      high = mid - 1;//eliminating right half
    }
  }
  return ans;
}

