// Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:

// 1)a next pointer to the next node,
// 2) a bottom pointer to a linked list where this node is head.

// Each of the sub-linked-list is in sorted order.

// Flatten the Link List such that all the nodes appear in a single level while maintaining a sorted order.

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next),
 *child(child) {}
 * };
 */

// Approach
//  1) Recursively flatten the next sub-linked list.
//  2) Separate the current sub-list from the rest of the linked list.
//  3) Merge the current sub-list with the flattened sub-list.
//  4) Attach the remaining part of the list (if any).
//  5) Return the head of the flattened linked list.
// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)
class Solution
{
    // Function to merge two sorted sub-linked lists.
    Node *mergeTwoLists(Node *a, Node *b)
    {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;

        // Create a dummy node to simplify merging.
        Node *temp = new Node(0);
        Node *res = temp;

        // Merge the two lists while maintaining sorted order.
        while (a != NULL && b != NULL)
        {
            if (a->data < b->data)
            {
                temp->child = a;
                temp = temp->child;
                a = a->child;
            }
            else
            {
                temp->child = b;
                temp = temp->child;
                b = b->child;
            }
        }

        // Attach the remaining part of the list (if any).
        if (a)
            temp->child = a;
        else
            temp->child = b;

        return res->child;
    }

    // Function to flatten a linked list with sub-linked lists.
    Node *flattenLinkedList(Node *root)
    {
        if (root == NULL || root->next == NULL)
            return root;

        // Recursively flatten the next sub-list.
        Node *nextSubList = flattenLinkedList(root->next);

        // Separate the current sub-list from the rest of the linked list.
        root->next = NULL;

        // Merge the current sub-list with the flattened sub-list.
        Node *ans = mergeTwoLists(root, nextSubList);

        return ans;
    }
}
