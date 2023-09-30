// Problem Statement: Given the head of a linked list,
// return the node where the cycle begins. If there is no cycle, return null.

// Approach 1: Brute Force
// Using hashing
// We create a set to store the addresses of the nodes.
// We iterate over the linked list.
// If the address of the current node is present in the set, we return the current node.
// If the address of the current node is not present in the set, we insert the address of the current node in the set.
// if we reach the end of the linked list, we return NULL.

// Time complexity: O(n)
// Space complexity: O(n)

Node *firstNode(Node *head)
{
    unordered_set<Node *> hashTable;
    while (head)
    {
        if (hashTable.find(head) != hashTable.end())
            return head;
        hashTable.insert(head);
        head = head->next;
    }
    return NULL;
}

// Approach 2: Two Pointer[Floyd's Cycle Detection Algorithm]
// We create two pointers slow and fast.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// If the slow pointer and the fast pointer meet, we break out of the loop.
// We set the slow pointer to the head.
// We iterate over the linked list till the slow pointer and the fast pointer meet.
// We return the slow pointer.

// Intuition: https://www.youtube.com/watch?v=LUm2ABqAs1w
//  Time complexity: O(n)
//  Space complexity: O(1)

Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}