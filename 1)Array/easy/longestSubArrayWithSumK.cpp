// Brute force approach
int getLongestSubarray(vector<int> &nums, int k)
{
  // Brute force computing all subarrays
  int n = nums.size();
  int maxLen = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      // subarray[i to j]
      sum += nums[j];
      if (sum == k)
      {
        maxLen = max(maxLen, j - i + 1);
      }
    }
  }
  return maxLen;
}

// Optimal approach hashing

#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
  // optimal hashing
  int maxLen = 0;
  int sum = 0;
  int n = nums.size();
  map<int, int> preSum;
  for (int i = 0; i < n; i++)
  {

    // STEP 1 : NORMAL FLOW OF CALCULATING PRE SUM AND UPDATING MAX LENGTH
    sum += nums[i];
    // at any moment if sum == k , then max length is i+1
    if (sum == k)
    {
      maxLen = i + 1; // 0 based indexing
    }

    // STEP2: CHECKING IF "SUM - K" IS PREVIOUSLY AVAILABLE IN MAP,IF YES THEN WE CAN STRIP THAT SUBARRAY FROM CURRENT SUBARRAY TO GET THE SUBARRAY WITH SUM K
    int rem = sum - k;
    // reverse mathematics , total sum - k = remainder,
    //  if remainder exist in preSum map , then there is a subarray of length preSum[rem]+1 index to current index i
    if (preSum.find(rem) != preSum.end())
    {
      maxLen = max(maxLen, i - preSum[rem]);
    }

    // STEP 3: ADD LEFTMOST PRESUM INDEX TO MAP(LEFTMOST BCZ WE WANT MAX LENGTH)
    if (preSum.find(sum) == preSum.end())
    {
      // want the leftmost presum index ,
      // cz if there are subsequent 0 to the right we don't want to update the current sum index
      // say if array is 2 0 0 3 and k =3 then we want to keep index of preSum 2 @ index 0 only rather than updating it to index 2 as 2+0+0 is also 2
      preSum[sum] = i;
    }
  }
  return maxLen;
}