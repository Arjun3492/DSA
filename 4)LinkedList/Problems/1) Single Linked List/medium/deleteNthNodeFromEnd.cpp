// Problem statement:
//  To remove the kth node from the end of the linked list.
// Video :https://youtu.be/Lhu3MsXZy-Q?si=D-qvNNGMzcidmm2m

// Approach 1: Brute Force
// We find the length of the linked list.
// We iterate over the linked list till the (length - k)th node.
// We set the next of the (length - k-1 )th node to the next of the (length - k)th node.
// We return the head.
// Time complexity: O(n)
// Space complexity: O(1)

Node *removeKthNodeFromEnd(Node *head, int k)
{
    int length = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    if (k == length)
    {
        return head->next;
    }
    curr = head;
    int count = 0;
    while (count < length - k - 1)
    {
        curr = curr->next;
        count++;
    }
    Node *toBeDeleted = curr->next;
    curr->next = curr->next->next;
    delete toBeDeleted;
    return head;
}

// Approach 2: Optimal Approach
// We use two pointers slow and fast.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// We set the next of the slow pointer to the next of the next of the slow pointer.
// We return the head.
// Time complexity: O(n)
// Space complexity: O(1)

Node *removeKthNodeFromEnd(Node *head, int k)
{
    Node *slow = head;
    Node *fast = head;
    while (k--)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        Node *toBeReturned = head->next;
        delete head;
        return toBeReturned;
    }
    if (fast->next == NULL)
    {
        // Edge case: If the kth node from the end is the first node.(i.e fast reached to the end of the linked list)
        Node *toBeDeleted = head->next;
        head->next = head->next->next;
        delete toBeDeleted;
        return head;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *toBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete toBeDeleted;
    return head;
}