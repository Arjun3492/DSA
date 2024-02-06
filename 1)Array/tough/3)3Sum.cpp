// 3 Sum : Find triplets that add up to a zero
// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Example :
// Input: nums = [-1, 0, 1, 2, -1, -4]
// Output: [[-1, -1, 2], [-1, 0, 1]]
// Explanation: The solution set must not contain duplicate triplets.

// LINK:https://www.codingninjas.com/studio/problems/three-sum_6922132

// BRUTE FORCE APPROACH
// We will use nested loop to compute all the possible triplets, and for uniqueness we will sort the triplets and store them in a set
// Finally return the ans from the set

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> ansSet;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                }
            }
        }
    }

    return {ansSet.begin(), ansSet.end()};
}

// BETTER APPROACH:Using hashing
// The intuition is that we have to eliminate the third level of nested loop so we will use a hashSet to hash values between i and jth index
//  and if the target which is -(arr[i]+arr[j]) is previously present in hashSet ,then these three elements will form a candidate
// finally push the current arr[j] to hashSet

// Time complexity: O(n^2)
// Space complexity: O(n)

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> setAns;
    for (int i = 0; i < n - 2; i++)
    {
        // hashSet to store the values between i and jth index
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            // target value, since arr[i]+arr[j]+arr[k]=0
            int target = -(arr[i] + arr[j]);
            if (hashSet.find(target) != hashSet.end())
            {
                // if target is present in hashSet then push the triplet to setAns

                vector<int> temp = {arr[i], arr[j], target};
                sort(temp.begin(), temp.end());
                setAns.insert(temp);
            }
            // push the current arr[j] to hashSet

            hashSet.insert(arr[j]);
        }
    }
    // return the setAns as vector

    return {setAns.begin(), setAns.end()};
}

// OPTIMAL APPROACH

// The optimal approach is to sort the array and then use three pointer approach to find the triplets
// The intuition is that we will fix the first element and then use two pointer approach to find the other two elements
// We will use the fact that the array is sorted to eliminate the duplicates
// Step1: Sort the array
// Step2: Iterate the array from 0 to n-2
// Step3: Fix the first element and use two pointer approach to find the other two elements
// Step4: Use left and right pointers to find the other two elements
// Step5: If the sum is less than 0, then increment the left pointer
// Step6: If the sum is greater than 0, then decrement the right pointer
// Step7: If the sum is equal to 0, then push the triplet to ans and increment the left pointer and decrement the right pointer
// Step8: Return the ans

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        // to eliminate duplicates
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int tempSum = arr[i] + arr[left] + arr[right];
            if (tempSum == 0)
            {
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1])
                    left++;
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
            // if sum is less than 0, then increment the left pointer
            else if (tempSum < 0)
            {
                left++;
            }
            // if sum is greater than 0, then decrement the right pointer
            else
            {
                right--;
            }
        }
    }
    return ans;
}
