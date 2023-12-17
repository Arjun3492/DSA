// Problem Statement:
// Given a linked list, you have to return the length of the linked list.

// Approach 1: Iterative
// We use a variable count to store the length of the linked list.
// We iterate over the linked list till current node pointer is NULL.
// We increment the count by 1.
// We return the count.
// Time complexity: O(n)
// Space complexity: O(1)

int lengthOfLinkedList(Node *head)
{
    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// Approach 2: Recursive
// We return 0 if the head is NULL.
// We return 1 + the return value of the recursive call for the next of the head.
// Time complexity: O(n)
// Space complexity: O(n)

int lengthOfLinkedList(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + lengthOfLinkedList(head->next);
}