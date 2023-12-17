// Problem Statement:Given a doubly linked list, and a number K ,insert K at the end of the doubly linked list.

// Approach:
Node *insertAtTail(Node *head, int k)
{

    // Create a reference to the head
    Node *curr = head;

    if (head == nullptr)
    {
        // If the list is empty, create a new node and return it
        head = new Node(k);
        return head;
    }
    while (curr->next)
    {
        // Traverse the list until the last node
        curr = curr->next;
    }
    // Create a new node and update pointers
    curr->next = new Node(k);
    d
        curr->next->prev = curr;
    return head;
}