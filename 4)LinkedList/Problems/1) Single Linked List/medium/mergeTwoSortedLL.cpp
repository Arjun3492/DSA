// Problem Statement:Given two sorted linked lists, merge them into one sorted linked list and return its head.

// Example 1:
// Input:
// LinkedList1: 5->10->15->40
// LinkedList2: 2->3->20
// Output: 2->3->5->10->15->20->40

// Brute Force Approach
// We create a new linked list and we iterate over the two linked lists.
// We compare the data of the two nodes and insert the node with the smaller data in the new linked list.
// We return the head of the new linked list.
// Time Complexity:O(n+m)
// Space Complexity:O(n+m)

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *curr = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                curr = head;
            }
            else
            {
                curr->next = head1;
                curr = curr->next;
            }
            head1 = head1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                curr = head;
            }
            else
            {
                curr->next = head2;
                curr = curr->next;
            }
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            curr = head;
        }
        else
        {
            curr->next = head1;
            curr = curr->next;
        }
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            curr = head;
        }
        else
        {
            curr->next = head2;
            curr = curr->next;
        }
        head2 = head2->next;
    }
    return head;
}

// Optimal Approach
// We use three pointers curr1,curr2 and head.
// We initialize curr1 to head1 and curr2 to head2.
// We check if the data of curr1 is less than or equal to the data of curr2, if yes, we set the next of head to curr1 and move curr1 by one.
// Else, we set the next of head to curr2 and move curr2 by one.
// We move head by one.
// We return the next of head.
// Time Complexity:O(n+m)
// Space Complexity:O(1)

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *head = new Node(0);
    Node *curr = head;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            curr->next = curr1;
            curr1 = curr1->next;
        }
        else
        {
            curr->next = curr2;
            curr2 = curr2->next;
        }
        curr = curr->next;
    }
    while (curr1 != NULL)
    {
        curr->next = curr1;
        curr1 = curr1->next;
        curr = curr->next;
    }
    while (curr2 != NULL)
    {
        curr->next = curr2;
        curr2 = curr2->next;
        curr = curr->next;
    }
    return head->next;
}

// Approach 3:Modifying the given linked lists only
// Intuition , we insert the nodes of the second linked list in the first linked list.
// We use four pointers curr1,curr2,next1 and next2.
// We initialize curr1 to head1 and curr2 to head2.
// We initialize next1 to curr1->next and next2 to curr2->next.
// We iterate over the linked lists till curr1 and curr2 are not NULL.
// We check if the data of curr2 is greater than or equal to the data of curr1 and less than or equal to the data of next1, if yes, we insert curr2 between curr1 and next1.
// We insert curr2 between curr1 and next1 by setting the next of curr1 to curr2 and the next of curr2 to next1.
// We move curr1 to next1 and curr2 to next2.
// Else, we move curr1 to next1 and next1 to next1->next.
// At the end of the loop, we check if curr2 is not NULL(meaning elements are remaining in curr2), if yes, we set the next of curr1 to curr2.
// We return head1.

Node<int> *solve(Node<int> *first, Node<int> *second)
{
    Node<int> *curr1 = first;
    Node<int> *next1 = first->next;
    Node<int> *curr2 = second;
    Node<int> *next2 = second->next;

    if (next1 == nullptr)
    {
        // Handle the case where the first list has only one element.
        first->next = second;
        return first;
    }

    while (next1 != nullptr && curr2 != nullptr)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            // Updating links
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            // Updating pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
        }
    }

    // If there are remaining nodes in the second list, append them to the merged list.
    if (curr2 != nullptr)
    {
        curr1->next = curr2;
    }

    return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
