// Problem Statement:
//  Remove the middle element of a linked list, if the number of elements is even, remove the second middle element.

// Approach 1: Brute Force
// We find the length of the linked list.
// We iterate over the linked list till the middle element.
// We set the next of the (length/2 - 1)th node to the next of the (length/2)th node.
// We return the head.

// Time complexity: O(n)
// Space complexity: O(1)

Node *deleteMid(Node *head)
{
    int length = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    if (length == 1)
    {
        return NULL;
    }
    if (length == 2)
    {
        Node *toBeDeleted = head->next;
        head->next = NULL;
        delete toBeDeleted;
        return head;
    }
    int mid = length / 2;
    curr = head;
    int count = 0;
    while (count < mid - 1)
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
// We use two pointers slow and fast to keep track of the middle element and the last element respectively.
// First we check if the head is NULL or the next of the head is NULL, if yes, we return NULL.(meaning the linked list is empty or has only one element)
// We initialize the slow pointer to the head and the fast pointer to the next of the next of the head.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// After the end of loop ,We set the next of the slow pointer to the next of the next of the slow pointer.
// We return the head.

// Time complexity: O(n)
// Space complexity: O(1)

Node *deleteMiddle(Node *head)
{

    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;

        fast = fast->next->next;
    }

    Node *toBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete toBeDeleted;

    return head;
}
