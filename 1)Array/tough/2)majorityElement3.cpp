// Majority Elements(>N/3 times)
// Find the elements that appears more than N/3 times in the array

// Problem Statement: Given an array of N integers. Find the elements that appear more
// than N/3 times in the array. If no such element exists, return an empty vector.

// LINK: https://www.codingninjas.com/studio/problems/majority-element_6915220

// Example1 :
// Input: [3,2,3]
// Output: [3]
// Explanation: 3 appears more than 3/3 = 1 times.

// Example2 :
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
// Explanation: 1 and 2 appear more than 8/3 = 2 times.

// INTUITION:The ans will have atmost 2 elements as the elements that appear more than N/3 times can be atmost 2.

// BRUTE FORCE APPROACH
// We will use a nested loop to find the count of each element in the array
// Time Complexity: O(n^2)
// Space Complexity: O(1)

vector<int> majorityElement(vector<int> v)
{

    int n = v.size();
    vector<int> res;
    int mini = (int)(n / 3) + 1;
    for (int i : v)
    {
        if (res.empty() || res[0] == i)
        {
            int count = 0;
            for (int j : v)
            {
                if (j == i)
                {
                    count++;
                    if (count == mini)
                    {
                        res.push_back(i);
                        if (res.size() == 2) // as there will be atmost 2 elements so we can return the result
                            return res;
                        else
                        {
                            break; // move to the next element
                        }
                    }
                }
            }
        }
    }
    return res;
}

// BETTER APPROACH (HASHING)
//  We will use a hashmap to store the count of each element in the array
//  Time Complexity: O(n)
//  Space Complexity: O(n)

vector<int> majorityElement(vector<int> v)
{
    int n = v.size();
    vector<int> res;
    int mini = (int)(n / 3) + 1;
    unordered_map<int, int> mp;
    for (int i : v)
    {
        mp[i]++;
    }
    for (auto i : mp)
    {
        if (i.second >= mini)
        {
            res.push_back(i.first);
        }
    }
    return res;
}

// OPTIMAL APPROACH
// Similar to intuition used for finding element with frequency > N/2
//  we will simulate it to work for N/3, since we will have atmost 2 elements with frequency > N/3
//  we will use count1,count2 to store the frequency of the two elements
//  ans element1,element2 to store the two elements
//  Time Complexity: O(n)
//  Space Complexity: O(1)

vector<int> majorityElement(vector<int> v)
{
    int element1 = INT_MIN, element2 = INT_MIN, count1 = 0, count2 = 0;
    int n = v.size();
    for (int i : v)
    {
        if (count1 == 0 && element2 != i) // element2 must be different from i,so that we don't track the same element twice

        {
            element1 = i;
            count1 = 1;
        }
        else if (count2 == 0 && element1 != i) // element1 must be different from i,so that we don't track the same element twice
        {
            element2 = i;
            count2 = 1;
        }
        else if (i == element1)
        {
            count1++;
        }
        else if (i == element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // finally checking if the elements are appearing more than N/3 times

    vector<int> ans;
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == element1)
            count1++;
        if (v[i] == element2)
            count2++;
    }

    int mini = int(n / 3) + 1;
    if (count1 >= mini)
        ans.push_back(element1);
    if (count2 >= mini)
        ans.push_back(element2);
    return ans;
}