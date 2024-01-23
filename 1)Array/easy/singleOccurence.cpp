// Find the number that appears once, and the other numbers twice
// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

// BRUTE FORCE APPROACH
// using nested loops to count the frequency of each element
// TC: O(n^2)
// SC: O(1)

int getSingleElement(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            return arr[i];
        }
    }
    return -1;
}

// BETTER APPROACH ,USING HASHING
// we will use a hashmap to store and update the frequency of each element as we traverse the array
// then we will traverse the hashmap and return the element with frequency 1
// TC: O(n)
// SC: O(n)
int getSingleElement(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]]++;
    }
    for (auto it : hashMap)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

// OPTIMAL APPROACH
// Using XOR operator
// XOR of a number with itself is 0.
// XOR of a number with 0 is number itself.
// TC: O(n)
// SC: O(1)
int getSingleElement(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
