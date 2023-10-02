// Problem Statement:Reverse a doubly linked list.

// Approach:
//  1. Traverse the list till the last element and swap the prev and next pointers.
//  2. swap the prev and next pointers of the last node.
//  3. Return the last node(now head) of the reversed list.

Node *reverseDLL(Node *head)
{
    Node *curr = head;

    while (curr->next)
    // Traverse the list till the second last node
    {
        // Swap the prev and next pointers
        swap(curr->prev, curr->next);

        // Move to the next node
        curr = curr->prev;
    }
    // Swap the prev and next pointers of the last node
    swap(curr->prev, curr->next);

    return curr;
}

// Approach 2:
// using pointer to keep track of the previous node(last node of the reversed list ,to be returned)
Node *reverseDLL(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;

    while (curr)
    {
        swap(curr->prev, curr->next);
        prev = curr;
        curr = curr->prev;
    }
    return prev;
}