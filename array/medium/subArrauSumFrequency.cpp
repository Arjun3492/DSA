// Count Subarray sum Equals K
// Problem Statement: Given an array of integers and an integer k, 
// return the total number of subarrays whose sum equals k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Brute Force Approach
// We will use 2 loops to find all the subarrays and check if their sum is equal to k
// Time Complexity: O(n^2)
int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
  int n = arr.size();
  int c = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (sum == k) {
        c++;
      }
    }
  }
  return c;
}

//Optimal approach
//Using prefix sum method
//We will use a map to store the frequency of prefix sum
//and then we will check if the remainder of current sum and k is present in map
//we will increase the count by the frequency of remainder(if not present frequency by default is 0)
//Time Complexity: O(n)
int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
  // Write Your Code Here

  // Using prefix sum method
  map<int,int> sum;
  prefixSum[0]=1;
  int sum = 0;
  int c = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
      //calculating the next sum
   sum+=arr[i];
   //finding the remainder
   int r= sum-k;
   //increasing count depending on the frequency of remainder
   //presum present in prefixSumMap
   c+=prefixSum[r];
   //increasing the freq of current sum
   prefixSum[sum]++;
  }
  return c;
}