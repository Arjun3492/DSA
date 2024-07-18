// Longest Subarray with given Sum K(Positives)
// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Brute force approach
// TC: O(n^2)
// SC: O(1)
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
      if (sum > k)
      {
        break; // skipping to next subarray with start index i+1;
      }
      if (sum == k)
      {
        maxLen = max(maxLen, j - i + 1);
      }
    }
  }
  return maxLen;
}

// Hashing approach
//  wherein,we would store the sum till the current index
//  in a mapping of sum to index , and check if "sum-k" exists in map,
//  if yes then we'd strip that subarray from the current subarray
//  TC: O(n)
//  SC: O(n)

int longestSubarrayWithSumK(vector<int> a, long long k)
{
  int n = a.size();
  unordered_map<long long, int> mp;
  long long sum = 0;
  int maxLen = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    // If sum == k, then we can update the max length
    if (sum == k)
    {
      maxLen = i + 1;
    }

    // If sum-k exists in map, then we can strip that subarray from the current subarray
    if (mp.find(sum - k) != mp.end())
    {
      maxLen = max(maxLen, i - mp[sum - k]);
    }

    // Since we want the greatest length, we are storing the first occurence of sum in map
    if (mp.find(sum) == mp.end())
    {
      mp[sum] = i;
    }
  }
  return maxLen;
}

// Opimal Approach
// TC: O(n)
// SC: O(n)
// Using two pointer approach where in we are adding each subsequent right element of array to sum
// if sum becomes > k ,we are reducing the array from left (sum=sum-arr[left],left ++ )
//  if sum == k , we are updating the max length
int longestSubarrayWithSumK(vector<int> a, long long k)
{
  int n = a.size();
  int right = 0, left = 0;
  long long sum = 0;
  int maxLen = 0;
  while (right < n)
  {
    sum += a[right];
    while (sum > k && left <= right)
    {
      sum -= a[left];
      left++;
    }
    if (sum == k)
    {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
  }
  return maxLen;
}
