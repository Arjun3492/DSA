// Problem Statement: To delete the second last element of a given linkedList

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

// Approach 1: Iterative
// We use two pointers curr and secondLast to keep track of the current node and the second last node respectively.
// We iterate over the linked list till the next of the current node is NULL.
// We set the second last node to the current node.
// We set the current node to the next of the current node.(to move forward)
// We delete the current node(which is the last node after the loop reaches the end).
// update the pointer to the second last node to NULL.

Node *deleteLast(Node *head)
{
    // Write your code here
    Node *curr = head;
    Node *secondLast = NULL;
    while (curr->next != NULL)
    {
        secondLast = curr;
        curr = curr->next;
    }
    delete curr;
    secondLast->next = NULL;
    return head;
}
