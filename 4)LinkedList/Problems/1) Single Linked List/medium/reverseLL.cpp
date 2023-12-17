// Problem Statement: To reverse a given linkedList

// Approach 1: Brute force
// We create a vector to store the data of the linked list.
// We reverse the vector.
// We create a new linked list using the data of the vector.
// We return the head of the new linked list.
// Time complexity: O(n)
// Space complexity: O(n)
Node *reverseLinkedList(Node *head)
{
    // Brute Force using Vector copy
    vector<int> vec;
    Node *curr = head;
    while (curr)
    {
        vec.push_back(curr->data);
        curr = curr->next;
    }
    reverse(vec.begin(), vec.end());
    int n = vec.size();
    Node *newHead = new Node(vec[0]);
    curr = newHead;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(vec[i]);
        if (i == 1)
        {
            newHead->next = newNode;
        }
        curr->next = newNode;
        curr = newNode;
    }
    return newHead;
}

// OPTIMAL APPROACH
// We create three pointers prevNode, currNode and nextNode.
// We iterate over the linked list till the curr is not NULL.
// We set the nextNode to immediate next of the currNode.
// We set the next of the currNode to the prevNode.
// We set the prevNode to the currNode.
// We set the currNode to the nextNode.
// After the iteration, we set the head to the prevNode.

Node *reverseLinkedList(Node *head)
{
    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;
    while (currNode != NULL)
    {
        // pointing the nextNode to the immediate next of the currNode
        nextNode = currNode->next;
        // pointing the next of the currNode to the prevNode(Reversing the link)
        currNode->next = prevNode;
        // moving the prevNode to the currNode(to keep track of the previous node for the next iteration)
        prevNode = currNode;
        // moving the currNode to the nextNode (to continue the iteration)
        currNode = nextNode;
    }
    head = prevNode;
    return head;
}

// Approach 2: Recursive
// We return the head if the head is NULL or the next of the head is NULL.
// We create a new node for the current node.
// We set the next of the current node to NULL.
// We set the next of the current node to the return value of the recursive call for the next of the head.
// We return the current node.
// Time complexity: O(n)
// Space complexity: O(n)

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *newNode = reverseLinkedList(head->next);
    curr->next->next = curr;
    curr->next = NULL;
    return newNode;
}
