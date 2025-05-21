
// 430. Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        flattenDFS(head);
        return head;
    }

private:
    // We will recursively solve this,
    //   IF NO CHILD we will traverse forward
    //   IF CHILD FOUND, we will get the tail of child and do the following
    // 1. Connect curr node < -> childHead
    // 2. Connect childTail <-> next node
    // 3. clear the curr node child pointer
    Node *flattenDFS(Node *node)
    {
        Node *curr = node;
        Node *prev = nullptr;

        while (curr)
        {
            Node *next = curr->next;

            if (!curr->child)
            // if no child,continue traversal of the current level
            {
                prev = curr;
                curr = next;
            }
            else
            // If there is a child, we need to flatten it

            {
                Node *childHead = curr->child;
                Node *childTail = flattenDFS(childHead); // Flatten the child list

                // Connect curr < -> childHead
                curr->next = childHead;
                childHead->prev = curr;

                // Connect childTail < -> next (if next exists)
                if (next)
                {
                    childTail->next = next;
                    next->prev = childTail;
                }

                // Remove the child pointer
                curr->child = nullptr;

                // Update last pointer
                prev = childTail;
                curr = next;
            }
        }

        return prev;
    }
};