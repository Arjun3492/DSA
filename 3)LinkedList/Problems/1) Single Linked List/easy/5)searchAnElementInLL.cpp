// Problem Statement: To search for an element in a given linkedList

// Approach 1: Iterative
// We iterate over the linked list till the current node is NULL.
// We check if the data of the current node is equal to the given value.
// If yes, we return true.
// If no, we move forward.

// Time complexity: O(n)
// Space complexity: O(1)

bool search(Node *head, int value)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Approach 2: Recursive
// We return false if the head is NULL.
// We return true if the data of the head is equal to the given value.
// We return the return value of the recursive call for the next of the head.

// Time complexity: O(n)
// Space complexity: O(n)

bool search(Node *head, int value)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->data == value)
    {
        return true;
    }
    return search(head->next, value);
}