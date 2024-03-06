// Binary Search
//Problem Statement: Given a sorted array of integers, we need to find the index of the given integer using binary search.
//Link : https://www.codingninjas.com/studio/problems/binary-search_972

//Example :
//Target: 5
//Array: 1 2 3 4 5 6 7 8 9
//Output: 4
//Explanation: 5 is present at index 4.

int search(vector<int> &nums, int target) {
  int n = nums.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    if (target > nums[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

