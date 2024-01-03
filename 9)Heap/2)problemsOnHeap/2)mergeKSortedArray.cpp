// Merge K sorted arrays
// Problem Statement: Given k sorted arrays of size n each, merge them and return the sorted output.

// Example:

// Input:
// K = 3, N =  4
// arr[][] = {{1,2,3,4},
//            {2,2,3,4},
//            {5,5,6,6}}
// Output: 1 2 2 2 3 3 4 4 5 5 6 6
// Explanation:The output array is a merge and sorted

// Approach 1: Brute Force
// Time Complexity: O(nklog(nk))
// Space Complexity: O(nk)
// Add all the elements to a single array and sort it

// Approach 2: Using Min Heap
typedef pair<int, pair<int, int>> ppi;
// first element hold the value , second element hold the arrayIndex and third hold the valueIndex

// we start with pushing the first element of each k array in min heap
// then while minHeap is not empty ,we pop element and push it to ans vector
// if the next element exist in the vector whose element was popped out then
// we push the next element into the heap
// we repeat this process until the heap is empty
// Time Complexity: O(nklogk)
// Space Complexity: O(k)
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;
    vector<int> res;

    // pushing all the 1st indexEle from all kArrays
    for (int arrayIndex = 0; arrayIndex < k; arrayIndex++)
    {
        minHeap.push({arr[arrayIndex][0], {arrayIndex, 0}});
    }

    while (!minHeap.empty())
    {
        ppi topElement = minHeap.top();
        res.push_back(topElement.first);
        minHeap.pop();

        int arrayIndex = topElement.second.first;
        int arrayElementIndex = topElement.second.second;

        // checking if arrayElementIndex+1 is not out of bound
        // then pushing the next element from the array recently popped out.
        if (arrayElementIndex + 1 < arr[arrayIndex].size())
        {
            minHeap.push({arr[arrayIndex][arrayElementIndex + 1], {arrayIndex, arrayElementIndex + 1}});
        }
    }

    return res;
}

// using custom node to store data ,arrayIndex and elementIndex
#include <bits/stdc++.h>
class Node
{
public:
    int data;
    int arrayIndex;
    int elementIndex;

    Node(int data, int arrayIndex, int elementIndex)
    {
        this->data = data;
        this->elementIndex = elementIndex;
        this->arrayIndex = arrayIndex;
    }

    // Add a destructor to delete dynamically allocated nodes
    ~Node()
    {
        // You may add additional cleanup here if needed
    }
};
class compare
{

public:
    bool operator()(Node *a, Node *b)
    {

        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    vector<int> res;

    // Pushing all the 1st indexEle from all kArrays
    for (int arrayIndex = 0; arrayIndex < k; arrayIndex++)
    {
        Node *newNode = new Node(arr[arrayIndex][0], arrayIndex, 0);
        minHeap.push(newNode);
    }

    while (!minHeap.empty())
    {
        Node *topElement = minHeap.top();
        res.push_back(topElement->data);
        minHeap.pop();

        int arrayIndex = topElement->arrayIndex;
        int arrayElementIndex = topElement->elementIndex;

        // Checking if arrayElementIndex+1 is not out of bound
        // Then pushing the next element from the array recently popped out.
        if (arrayElementIndex + 1 < arr[arrayIndex].size())
        {
            Node *newNode = new Node(arr[arrayIndex][arrayElementIndex + 1],
                                     arrayIndex, arrayElementIndex + 1);
            minHeap.push(newNode);
        }

        // Delete the topElement node to avoid memory leak
        delete topElement;
    }

    return res;
}