// Implement Lower Bound
// Problem Statement: Given a sorted array of integers and a target,
// we need to find the index of the smallest element which is greater
// than or equal to the target.

// Link : https://www.codingninjas.com/studio/problems/lower-bound_8165382

// Example:
// Input: ‘arr’ = [1, 2, 2, 3] and 'x' = 0
// Output: 0
// Explanation: Index '0' is the smallest index such that 'arr[0]' is not less than '

// BRUTE FORCE APPROACH
//  We need to find the index of the smallest element which is greater than or equal to the target.
//  Since the array is sorted, we can simply iterate through the array and find the first element which is greater than or equal to the target.
//  The index of this element will be our answer.
int lowerBound(vector<int> nums, int n, int target)
{
  for (int i = 0; i < n; i++)
  {
    if (nums[i] >= target)
    {
      return i;
    }
  }
  return n;
}
// Time Complexity: O(n)
// Space Complexity: O(1)

// OPTIMIZED APPROACH
// We can use binary search to solve this problem
// NOTE: We can also use the inbuilt lower_bound function in C++ STL to solve this problem.
// Eg : auto it = lower_bound(arr.begin(), arr.end(), x);
//     cout << it - arr.begin() << endl;
int lowerBound(vector<int> nums, int n, int target)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = high - (high - low) / 2;
    if (nums[mid] >= target)
    {
      ans = mid;
      // we'll look for smaller index on the left
      high = mid - 1;
    }
    else
    {
      // reduce the search space to right half
      low = mid + 1;
    }
  }
  return ans;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)
