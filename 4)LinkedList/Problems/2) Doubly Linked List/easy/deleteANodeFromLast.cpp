// Problem Statement: Given a linked list ,delete the last node of the linked list.

Node *deleteLastNode(Node *head)
{

    // Create a reference to the head
    Node *curr = head;

    if (head == nullptr)
    {
        // If the list is empty, return nullptr
        return nullptr;
    }
    if (head->next == nullptr)
    {
        // If the list has only one node, delete it and return nullptr
        delete head;
        return nullptr;
    }
    while (curr->next->next)
    {
        // Traverse the list until the second last node
        curr = curr->next;
    }
    // Delete the last node and update pointers
    delete curr->next;
    curr->next = nullptr;
    return head;
}