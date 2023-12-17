// Problem statement:Given a number represented as a linked list of digits, add one to it.
// Example 1:
// Input: LinkedList: 4->5->6
// Output: 457

// Example 2:
// Input: LinkedList: 1->5->9
// Output: 160

// Example 3:
// Input: LinkedList: 9->9->9
// Output: 1000

// Approach 1: Brute Force
// We reverse the linked list.
// We add one to the first node.
// We iterate over the linked list and if the data of the current node is 10, we set the data of the current node to 0 and add one to the data of the next node.
// We reverse the linked list.
// We return the head.
// Time Complexity:O(n)
// Space Complexity:O(1)

Node *addOne(Node *head)
{
    // Reverse the linked list and store the new head in 'revHead'.
    Node *revHead = reverse(head);
    Node *curr = revHead;
    while (curr)
    {
        if (curr->data != 9)
        {
            // If the current digit is not 9, simply increment it by 1 and break out of the loop.
            curr->data++;
            break;
        }
        if (curr->next == NULL) // curr->data == 9 && curr->next == NULL (means most significant digit(last node of rev LL) is 9)
        {
            // If the current digit is 9 and we have reached the end of the list,
            // create a new node with a value of 1 ,set the current digit to 0
            // and append the Node with value 1 to the end of the list.
            Node *newNode = new Node(1);
            curr->data = 0;
            curr->next = newNode;
            break;
        }
        // If the current digit is 9, set it to 0 and move to the next digit.
        curr->data = 0;
        curr = curr->next;
    }
    // Reverse the modified linked list again to get the original order.
    head = reverse(revHead);
    return head;
}
