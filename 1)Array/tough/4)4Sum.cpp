// 4 Sum | Find Quads that add up to a target value
// Problem Statement: Given an array of N integers, your task is to find unique quads
// that add up to give a target value. In short, you need to return an array of all the
// unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Example :
// Input: nums = [1, 0, -1, 0, -2, 2], target = 0
// Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
// Explanation: The solution set must not contain duplicate quadruplets.

// LINK :https://www.codingninjas.com/studio/problems/4sum_5713771

//// BRUTE FORCE APPROACH
// We will use nested loop to compute all the possible quadruplets, and for uniqueness we will sort the quadruplets and store them in a set
// Finally return the ans from the set

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    set<vector<int>> ansSet;
    int n = arr.size();
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        ansSet.insert(temp);
                    }
                }
            }
        }
    }

    return {ansSet.begin(), ansSet.end()};
}

// BETTER APPROACH

// The intuition is that we have to eliminate the fourth level of nested loop so we will use a hashSet to hash values between jth and kth index, while i is fixed
//  and if the fourth element which is target-(arr[i]+arr[j]+arr[k]) is previously present in hashSet ,then these four elements will form a candidate
// finally push the current arr[k] to hashSet

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> setAns;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashSet;
            for (int k = j + 1; k < n; k++)
            {
                int fourth = target - (arr[i] + arr[j] + arr[k]);
                if (hashSet.find(fourth) != hashSet.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    setAns.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }
    return {setAns.begin(), setAns.end()};
}

// OPTIMAL APPROACH

// The optimal approach is to sort the array and then use three pointer approach to find the quadruplets
// The intuition is that we will fix the first element and second element and then use two pointer approach to find the other two elements
// We will use the fact that the array is sorted to eliminate the duplicates
// Step1: Sort the array
// Step2: Iterate the array from 0 to n
// Step3: Fix the first element and second element and use two pointer approach to find the other two elements
// Step4: Use left and right pointers to find the other two elements
// Step5: If the sum is less than target, then increment the left pointer
// Step6: If the sum is greater than target, then decrement the right pointer
// Step7: If the sum is equal to target, then push the triplet to ans and increment the left pointer and decrement the right pointer
// Step8: Return the ans

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // 2 pointers:
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[left];
                sum += nums[right];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;

                    // skip the duplicates:
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }

    return ans;
}
