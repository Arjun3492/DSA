// Problem Statement:To rotate a given LL right by k places

// Approach
//  1) Calculate the length of the linked list and find the last node.
//  2) Calculate the effective rotation position by taking the remainder.
//  3) If the effective position is 0, no rotation is needed, so return the original head.
//  4) Reset the current pointer to the head.
//  5) Calculate the new position to which rotation will be performed.
//  6) Move 'curr' and 'prev' to the position before the rotation.
//  7) Set the 'next' pointer of 'prev' to nullptr, cutting the linked list.
//  8) Set 'newHead' to the current position where rotation starts.
//  9) Connect the last node of the original list to the original head.
//  10) Return the new head after rotation.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

Node *rotate(Node *head, int k)
{
    // Check for special cases where rotation is not needed or not possible.
    if (k == 0 || !head || !head->next)
    {
        return head;
    }

    int n = 0;
    Node *curr = head;
    Node *last = curr;

    // Calculate the length of the linked list and find the last node.
    while (curr)
    {
        n++;
        last = curr;
        curr = curr->next;
    }

    // Calculate the effective rotation position by taking the remainder.
    int pos = k % n;

    // If the effective position is 0, no rotation is needed, so return the original head.
    if (pos == 0)
    {
        return head;
    }

    // Reset the current pointer to the head.
    curr = head;
    Node *prev = curr;

    // Calculate the new position to which rotation will be performed.
    // (n - pos) gives the position from the beginning where rotation should start.
    pos = n - pos;

    // Move 'curr' and 'prev' to the position before the rotation.
    while (pos--)
    {
        prev = curr;
        curr = curr->next;
    }

    // Set the 'next' pointer of 'prev' to nullptr, cutting the linked list.
    prev->next = nullptr;

    // Set 'newHead' to the current position where rotation starts.
    Node *newHead = curr;

    // Connect the last node of the original list to the original head.
    last->next = head;

    // Return the new head after rotation.
    return newHead;
}

// Approach 2:Linking the last node to first node , then spilliting the list at the required position
// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

node *rotateRight(node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    // calculating length
    node *temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        ++length;
        temp = temp->next;
    }
    // link last node to first node
    temp->next = head;
    k = k % length;       // when k is more than length of list
    int end = length - k; // to get end of the list
    while (end--)
        temp = temp->next;
    // breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;

    return head;
}