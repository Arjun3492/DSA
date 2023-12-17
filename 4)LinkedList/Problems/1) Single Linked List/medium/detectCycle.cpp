// Problem Statement: Given head, the head of a linked list,
//  determine if the linked list has a cycle in it. There is a cycle
//  in a linked list if there is some node in the list that can be
//  reached again by continuously following the next pointer.

// Approach 1: Brute Force
// Using hashing
// We create a set to store the addresses of the nodes.
// We iterate over the linked list.
// If the address of the current node is present in the set, we return true.
// If the address of the current node is not present in the set, we insert the address of the current node in the set.
// if we reach the end of the linked list, we return false.
// Time complexity: O(n)
// Space complexity: O(n)
bool detectCycle(Node *head)
{
    unordered_set<Node *> hashTable;
    while (head)
    {
        if (hashTable.find(head) != hashTable.end())
            return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}

// Approach 2: Two Pointer
// We create two pointers slow and fast.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// If the slow pointer and the fast pointer meet, we return true.
// If the slow pointer and the fast pointer do not meet, we return false.
// Time complexity: O(n)
// Space complexity: O(1)

bool detectCycle(Node *head)
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
            return true;
        }
    }
    return false;
}
