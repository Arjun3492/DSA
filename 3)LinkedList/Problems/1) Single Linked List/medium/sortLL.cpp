// Problem statement:
// Sort the given linked list in ascending order.

// Approach 1: Brute Force
// We store the data of the linked list in an array.
// We sort the array.
// We iterate over the linked list and set the data of the nodes to the data of the array.
// We return the head.
// Time complexity: O(nlogn)
// Space complexity: O(n)

Node *sortList(Node *head)
{
    vector<int> arr;
    Node *curr = head;
    while (curr)
    {
        arr.push_back(curr->data);
        curr = curr->next;
    }
    sort(arr.begin(), arr.end());
    curr = head;
    int i = 0;
    while (curr)
    {
        curr->data = arr[i++];
        curr = curr->next;
    }
    return head;
}

// Approach 2: Optimal Approach
// We use merge sort to sort the linked list.
// We use two functions merge and mergeSort.
// We call mergeSort on the head of the linked list.
// In mergeSort, we first check if the head is NULL or the next of the head is NULL, if yes, we return the head.
// We use two pointers slow and fast to keep track of the middle element and the last element respectively.
// We iterate over the linked list till the next of the fast pointer is NULL.
// We move the slow pointer by one and the fast pointer by two.
// After the end of loop, we set the next of the slow pointer to NULL.
// We call mergeSort on the head and the next of the slow pointer.
// We call merge on the head and the next of the slow pointer.
// In merge, we first check if the first linked list is NULL, if yes, we return the second linked list.
// We also check if the second linked list is NULL, if yes, we return the first linked list.
// We create a new linked list and initialize it to NULL.
// We check if the data of the first linked list is less than or equal to the data of the second linked list, if yes, we set the head of the new linked list to the first linked list and call merge on the next of the first linked list and the second linked list.
// Else, we set the head of the new linked list to the second linked list and call merge on the first linked list and the next of the second linked list.
// We return the head of the new linked list.
// We return the head.
// Time complexity: O(nlogn)
// Space complexity: O(1)

Node *merge(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    Node *newHead = NULL;
    if (first->data <= second->data)
    {
        newHead = first;
        newHead->next = merge(first->next, second);
    }
    else
    {
        newHead = second;
        newHead->next = merge(first, second->next);
    }
    return newHead;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is standing at the middle of the linked list(i.e the last node of the first linked list)
    Node *second = slow->next;
    // second is now the head of the second linked list
    slow->next = NULL;
    // breaking the linked list into two halves ,by setting the next of the slow pointer to NULL
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}

Node *sortList(Node *head)
{
    return mergeSort(head);
}