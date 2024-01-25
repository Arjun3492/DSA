// Find Second Smallest and Second Largest Element in an array
// Problem Statement: Given an array, find the second
// smallest element in the array. Print ‘-1’ in the event
// that either of them doesn’t exist.

// BRUTE FORCE APPROACH
//   sort the array and return the second element
//   TC: O(nlogn)
//   SC: O(1)

// BETTER APPROACH
// traversing the arr two times,once to find the smallest element and other to find the second smallest element
// TC: O(n)
// SC: O(1)

void getSecondSmalledElement(int arr[])
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = INT_MAX;
    int secondMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < secondMin && arr[i] != min)
        {
            secondMin = arr[i];
        }
    }
    if (secondMin == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << secondMin;
    }
}

// OPTIMAL FORCE APPROACH
//  maintaing two variables min and secondMin
//  TC: O(n)
//  SC: O(1)

void getSecondSmalledElement(int arr[])
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = INT_MAX;
    int secondMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            secondMin = min;
            min = arr[i];
        }
        else if (arr[i] < secondMin && arr[i] != min)
        {
            secondMin = arr[i];
        }
    }
    if (secondMin == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << secondMin;
    }
}
