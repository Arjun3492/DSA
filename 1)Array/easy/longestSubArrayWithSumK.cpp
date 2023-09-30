//Brute force approach
int getLongestSubarray(vector<int> &nums, int k) {
  // Write your code here
  // Brute force computing all subarrays
  int n = nums.size();
  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      // subarray[i to j]
      sum += nums[j];
      if (sum == k) {
        maxLen = max(maxLen, j - i + 1);
      }
    }
  }
  return maxLen;
}


//Optimal approach hashing


#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k) {
  // Write your code here
  // optimal hashing
  int maxLen = 0;
  int sum = 0;
  int n = nums.size();
  map<int, int> preSum;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    // if we encounter any preFix sum == k
    if (sum == k) {
      maxLen = i + 1; // 0 based indexing
    }
    if (preSum.find(sum) == preSum.end()) {
        // want the leftmost presum index , 
        //cz if there are subsequent 0 to the right we don't want to account them in prefix map
      preSum[sum] = i;
    }

    int rem = sum - k;
    //reverse mathematics , total sum - k = remainder, 
    // if remainder exist in preSum map , then there is a subarray of length preSum[rem]+1 index to current index i
    if (preSum.find(rem) != preSum.end()) {
      maxLen = max(maxLen, i - preSum[rem]);
    }
  }
  return maxLen;
}