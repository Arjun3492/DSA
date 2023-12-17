// Problem Statement:Given a doubly linked list, delete nodes with data k

// Approach: Traverse the list and delete the nodes with data k
// Edge cases: 1) If the node to be deleted is the head node
//             2) If the node to be deleted is the last node
//             3) If the node to be deleted is the only node in the list
// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

Node *deleteAllOccurrences(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            { // if the node to be deleted is the head node
                head = temp->next;
                if (temp->next != NULL) // if the node to be deleted is the only node in the list
                    temp->next->prev = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                if (temp->next != NULL) // if the node to be deleted is the last node
                    temp->next->prev = temp->prev;
            }
        }
        temp = temp->next;
    }
    return head;
}
