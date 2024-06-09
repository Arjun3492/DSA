// Kth smallest element
//  Problem Statment: Given an array arr and an integer k find the
// kth smallest element from the array arr

// Link : https://www.naukri.com/code360/problems/kth-smallest-element_893056

// Example:
//  Input: arr = [7,10,4,3,20,15]
//  k = 3
//  Output: 7
//  Explanation: 3rd smallest element in the given array is 7

// Approach 1: Sort the array and return the kth element
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

// Approach 2: Use a min heap and pop k elements from the heap
// Time Complexity: O(nlogk)
// Space Complexity: O(k)

// Working:
// We know that the root(top) element of maxHeap is the largest of all the elements
// so one by one we will push elements to heap and when the heap size becomes greater than k we will pop the top element ensuring that the heap size is always k
// so at the end we will have k smallest elements in the heap and the top element of the heap will be the kth smallest element
int kSmallest(int arr[], int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}
