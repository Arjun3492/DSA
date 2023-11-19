// Problem Statement:Given a sorted DLL, remove the duplicates such that every element appears only once

// Example:
// Input: 1 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4 <-> 4 <-> 5
// Output: 1 <-> 2 <-> 3 <-> 4 <-> 5

// Approach 1:
//  1) Initialize a pointer 'curr' to traverse the linked list.
//  2) Store the value of the current node.
//  3) Create a temporary pointer 'temp' to traverse and skip nodes with the same value.
//  4) Traverse 'temp' to skip nodes with the same value as 'val'.
//  5) Update the 'next' pointer of 'curr' to point to the next unique node(current value of temp).
//  6) If 'temp' is not nullptr, set the 'prev' pointer of 'temp' to 'curr'.
//  7) Move 'curr' to the next node in the linked list to continue checking for duplicates.
//  8) Return the modified head of the linked list with duplicates removed.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

Node *removeDuplicates(Node *head)
{
    // Initialize a pointer 'curr' to traverse the linked list.
    Node *curr = head;

    while (curr)
    {
        // Store the value of the current node.
        int val = curr->data;

        // Create a temporary pointer 'temp' to traverse and skip nodes with the same value.
        Node *temp = curr;

        // Traverse 'temp' to skip nodes with the same value as 'val'.
        while (temp != nullptr && temp->data == val)
        {
            delete temp;
            temp = temp->next;
        }

        // Update the 'next' pointer of 'curr' to point to the next unique node.
        curr->next = temp;

        // If 'temp' is not nullptr, set the 'prev' pointer of 'temp' to 'curr'.
        if (temp != nullptr)
        {
            temp->prev = curr;
        }

        // Move 'curr' to the next node in the linked list to continue checking for duplicates.
        curr = curr->next;
    }

    // Return the modified head of the linked list with duplicates removed.
    return head;
}

// Approach 2:
//   1) Initialize a pointer 'curr' to traverse the linked list.
//   2) Traverse the linked list to check for and remove duplicates.
//   3) Check if the current node has a duplicate immediate next node with the same data.
//   4) Save the pointer to the next node (the duplicate node) and the node after it.
//   5) Delete the duplicate node to free the memory.
//   6) Update the 'next' pointer of the current node to point to the second next node to it.
//   7) If no duplicate is found, move to the next node.
//   8) Return the modified head of the linked list with duplicates removed.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

Node *removeDuplicates(Node *head)
{
    // If the linked list is empty or has only one element, return it as is (no duplicates).
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Initialize a pointer 'curr' to traverse the linked list.
    Node *curr = head;

    // Traverse the linked list to check for and remove duplicates.
    while (curr != NULL)
    {
        // Check if the current node has a duplicate next node with the same data.
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            // Save the pointer to the next node (the duplicate node) and the node after it.
            Node *curr_node = curr->next->next;
            Node *node_to_delete = curr->next;

            // Delete the duplicate node to free the memory.
            delete (node_to_delete);

            // Update the 'next' pointer of the current node to point to the next unique node.
            curr->next = curr_node;
        }
        else
        {
            // If no duplicate is found, move to the next node.
            curr = curr->next;
        }
    }

    // Return the modified head of the linked list with duplicates removed.
    return head;
}
