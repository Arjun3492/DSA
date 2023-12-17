// Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time,
// and return the modified list. k is a positive integer and is less than or equal to the length
// of the linked list. If the number of nodes is not a multiple of k then left-out nodes,
// in the end, should remain as it is.

// Example:
// Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10->11, k = 3
// Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> 10->11

// Approach:
//  1) Check if the linked list is empty or has only one Node.
//  2) Calculate the length of the linked list.
//  3) Create a dummy head Node and link it to the original head.
//  4) Initialize pointers for previous, current, and next nodes.
//  5) Iterate while there are at least 'k' nodes left to reverse.
//  6) Reverse 'k' nodes within the group.
//  7) Return the modified linked list starting from the dummy head's 'next'.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

Node *reverseKNodes(Node *head, int k)
{
    // Check if the linked list is empty or has only one Node.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Calculate the length of the linked list.
    int length = lengthOfLinkedList(head);

    // Create a dummy head Node and link it to the original head.
    Node *dummyHead = new Node(0);
    dummyHead->next = head;

    // Initialize pointers for previous, current, and next nodes.
    Node *pre = dummyHead; // Pointer to the Node before the current group.
    Node *cur;             // Pointer to the current Node within the group.
    Node *nex;             // Pointer to the next Node within the group.

    // Iterate while there are at least 'k' nodes left to reverse.
    while (length >= k)
    {
        cur = pre->next; // Initialize 'cur' with the first Node in the group.
        nex = cur->next; // Initialize 'nex' with the second Node in the group.

        // Reverse 'k' nodes within the group.
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next; // Reverse the 'next' pointers.
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }

        pre = cur;   // Move 'pre' to the last Node of the reversed group.
        length -= k; // Decrement the remaining length by 'k'.
    }

    // Return the modified linked list starting from the dummy head's 'next'.
    return dummyHead->next;
}
