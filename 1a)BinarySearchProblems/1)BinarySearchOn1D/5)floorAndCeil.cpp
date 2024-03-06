// Ceil The Floor
//Problem statement
// You're given a sorted array 'a' of 'n' integers and an integer 'x'.
// Find the floor and ceiling of 'x' in 'a[0..n-1]'.
// Note:
// Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
// Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.

// Link:https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401

//Example:
// Input: a = [1, 2, 8, 10, 10, 12, 19], x = 5
// Output: 2 8
// Explanation: The floor of 5 is 2 and the ceiling of 5 is 8.

// BRUTE FORCE APPROACH
// We use linear search to find the floor and ceiling of 'x' in the array.

pair<int, int> findFloorAndCeil(vector<int> &a, int n, int x) {
  int floor = -1, ceil = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) {
      floor = a[i];
    }
    if (a[i] >= x) {
      ceil = a[i];
      break;
    }
  }
  return {floor, ceil};
}

//Time Complexity: O(n)
//Space Complexity: O(1)

// OPTIMIZED APPROACH
// We can use binary search to solve this problem
// For the floor, we need to find the largest element in the array which is smaller than or equal to 'x'.
// For the ceiling, we need to find the smallest element in the array greater than or equal to 'x'.
// Since we know that the array is sorted, we can use binary search to find the floor and ceiling of 'x' in the array.

pair<int, int> findFloorAndCeil(vector<int> &a, int n, int x) {
    //Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
    //Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.
  int low = 0, high = n - 1;
  int floor = -1, ceil = -1;
  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (a[mid] == x) {
      floor = ceil = a[mid];
      return {floor, ceil};
    } else if (a[mid] < x) {
      floor = a[mid];
      low = mid + 1;
    } else {
      ceil = a[mid];
      high = mid - 1;
    }
  }
  return {floor, ceil};
}

//Time Complexity: O(log n)
//Space Complexity: O(1)

