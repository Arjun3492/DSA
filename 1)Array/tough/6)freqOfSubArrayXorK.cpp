// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B.
// Find the total number of subarrays having bitwise XOR of all elements equal to k.

// Link:https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258

// Example:
// Input: A = [4, 2, 2, 6, 4], B = 6
// Output: 4
// Explanation: The subarrays having XOR equal to 6 are [4, 2], [2, 2, 6, 4], [6], [6, 4]

// BRUTE FORCE APPROACH
//  We will use nested loop to compute all the possible subarrays, and for each subarray we will
//  compute the xor and check if it is equal to k

// Time complexity: O(n^3)
// Space complexity: O(1)

int countSubarraysWithXorK(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorSum = 0;
            for (int k = i; k <= j; k++)
            {
                xorSum ^= arr[k];
            }
            if (xorSum == k)
            {
                count++;
            }
        }
    }
    return count;
}

// BETTER APPROACH
// We can trim down the time complexity to O(n^2) by removing the third nested loop
// and computing the xor for each next subarray by just adding the next element to the xorSum

// Time complexity: O(n^2)
// Space complexity: O(1)

int countSubarraysWithXorK(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xorSum = 0;
        for (int j = i; j < n; j++)
        {
            xorSum ^= arr[j];
            if (xorSum == k)
            {
                count++;
            }
        }
    }
    return count;
}

// OPTIMAL APPROACH
// We will use a hash map to store the prefix xor of the array along with the frequency of the prefix xor
// We will iterate over the array and keep adding the elements to the xorSum
// If the xorSum is equal to k, then we will increment the count
// If the xorSum^k is present in the hash map, then we will increment the count by the frequency of xorSum^k
// Finally we will increment the frequency of xorSum in the hash map

// Time complexity: O(n)
// Space complexity: O(n)

int countSubarraysWithXorK(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> hashMap;
    int xorSum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum ^= arr[i];
        if (xorSum == k)
        {
            count++;
        }
        int x = xorSum ^ k; // x^k=xorSum ,then x=xorSum^k
        if (hashMap.find(x) != hashMap.end())
        {
            count += hashMap[x];
        }
        hashMap[xorSum]++;
    }
    return count;
}
