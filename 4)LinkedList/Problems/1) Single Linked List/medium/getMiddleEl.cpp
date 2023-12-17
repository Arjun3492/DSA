// Problem Statement: To return the middle element of a linkedList, if the number of elements is even, return the second middle element.

// Approach 1: Optimal Approach
// We use two pointers slow and fast to keep track of the middle element and the last element respectively.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// We return the data of the slow pointer.
// Time complexity: O(n)
// Space complexity: O(1)

int getMiddle(Node *head)
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
    }
    return slow->data;
}

// Approach 2: Brute Force
// We find the length of the linked list.
// We iterate over the linked list till the middle element.
// We return the data of the middle element.
// Time complexity: O(n)
// Space complexity: O(1)

int getMiddle(Node *head)
{
    int length = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    int mid = length / 2;
    curr = head;
    while (mid--)
    {
        curr = curr->next;
    }
    return curr->data;
}
