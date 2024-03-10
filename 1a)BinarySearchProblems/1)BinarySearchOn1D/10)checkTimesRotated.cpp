//Rotation

// Problem statement
// You are given an array 'arr' having 'n' distinct integers sorted in ascending order. 
//The array is right rotated 'r' times
// Find the minimum value of 'r'.
// Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, 
//for all 'i' from 0 to ‘n-1'.

// Example:
// Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]
// Output: 3 
// Explanation:
// If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. 
//Thus 'r' = 3.

//Link : https://www.codingninjas.com/studio/problems/rotation_7449070


//INTUITION :
//Since we know that the array was sorted in ascending order and then right rotated 'r' times.
//So the index of the minimum element in the array will be the value of 'r'.
//as the minimum element will be at the start of the array before rotation.

//BRUTE FORCE APPROACH
//We can simply iterate through the array and find the index of minimum element in the array.
//Time complexity: O(n) 
//Space complexity: O(1)

int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int mini = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < mini) {
            mini = arr[i];
            index = i;
        }
    }
    return index;
}

//OPTIMAL APPROACH:Using Binary Search
//We can use binary search to find the index of the minimum element in the array.
//We can pick the smallest element from the sorted half and eliminate this sorted half from the search space.
//We will keep on updating the index variable with the index of the minimum element.
//Time complexity: O(logn)
//Space complexity: O(1)

#include <bits/stdc++.h>
int findKRotation(vector<int> &arr) {

  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = -1, mini = INT_MAX;

  while (low <= high) {
    int mid = high - (high - low) / 2;
    if (arr[low] < arr[mid]) // left half is sorted
    {
      if (arr[low] < mini)
      //if the first index of the sorted left half(low is the first) is smallest
      //update mini and ans
       {
        mini = arr[low];
        ans = low;
      }
      low = mid + 1; // eliminating left half
    } else // right half is sorted
    {
      if (arr[mid] < mini)
      //if the first index of the sorted right half(mid is the first) is smallest
      //update mini and ans
       {
        mini = arr[mid];
        ans = mid;
      }
      high = mid - 1; // eliminating right half
    }
  }
  return ans;
}
