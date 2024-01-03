// Merge k sorted Linked List
//  Problem Statement: Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example:
// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:The test case has 4 sorted linked list of size 3, 2, 2, 2

// Approach 1: Brute Force
// Time Complexity: O(nklog(nk))
// Space Complexity: O(nk)
// Add all the elements to a single array and sort it

// Approach 2: Using Min Heap
// Similar to last solution ,first we will push heads of all k linked lists onto the min-heap
// then we will pop the top element from the heap and push it to the merged Linked list
// if the popped element has a next element then we will push it to the heap
// we will repeat this process until the heap is empty
// Time Complexity: O(nklogk)
// Space Complexity: O(k)

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list node
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Custom comparator class for the min-heap
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->data > b->data);
    }
};

// Function to merge k sorted linked lists
Node *mergeKLists(vector<Node *> &listArray)
{
    // Priority queue (min-heap) to efficiently track the minimum element
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = listArray.size();

    if (k == 0)
        return nullptr;

    // Push the heads of all linked lists onto the min-heap
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != nullptr)
            minHeap.push(listArray[i]);
    }

    // Initialize pointers for the merged list
    Node *head = nullptr;
    Node *tail = nullptr;

    // Process until the min-heap is not empty
    while (!minHeap.empty())
    {
        // Extract the minimum element from the min-heap
        Node *top = minHeap.top();
        minHeap.pop();

        // If the current node has a next element, push it onto the min-heap
        if (top->next != nullptr)
            minHeap.push(top->next);

        // Update the merged list
        if (head == nullptr)
        {
            head = tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}
