// Problem Statement:Given a vector of intergers, create a doubly linked list from it.

// Approach:
// 1. Create a new node for each element of the vector.
// 2. Update the pointers of the new node.
// 3. Return the head of the doubly linked list.

Node *createDLL(vector<int> &v)
{
    Node *head = nullptr;
    Node *curr = nullptr;

    for (int i : v)
    {
        if (head == nullptr)
        {
            head = new Node(i);
            curr = head;
        }
        else
        {
            curr->next = new Node(i);
            curr->next->prev = curr;
            curr = curr->next;
        }
    }

    return head;
}