// Problem statement: Segrregate odd and even nodes in LL while maintaining the order of the nodes.

//  BRUTE FORCE: Using two LinkedLists
// We use two linked lists odd and even to store the odd and even nodes respectively.
// We iterate over the linked list and store the odd and even nodes in the odd and even linked lists respectively.
// We append the odd linked list to the even linked list.
// We return the head of the even linked list.
// Time complexity: O(n)
// Space complexity: O(n)

Node *segregateEvenOdd(Node *head)
{
    Node *odd = NULL;
    Node *even = NULL;
    Node *curr = head;
    Node *oddHead = NULL;
    Node *evenHead = NULL;
    while (curr)
    {
        if (curr->data % 2 == 0)
        {
            if (even == NULL)
            // means even is not initialized yet
            {
                even = curr;
                evenHead = even;
            }
            else
            {
                even->next = curr;
                even = curr;
            }
        }
        else
        {
            if (odd == NULL)
            // means odd is not initialized yet
            {
                odd = curr;
                oddHead = odd;
            }
            else
            {
                odd->next = curr;
                odd = curr;
            }
        }
        curr = curr->next;
    }
    if (odd)
    {
        // we terminate the odd linked list
        odd->next = NULL;
    }
    if (even)
    {
        // if even linked list is not empty , then we append the odd linked list to the even linked list
        even->next = oddHead;
        return evenHead;
    }

    // if even linked list is empty , then we return the odd linked list
    return oddHead;
}
