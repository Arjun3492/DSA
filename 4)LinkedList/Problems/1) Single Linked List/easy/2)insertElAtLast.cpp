// Problem Statement: To insert the given element at the end of linkedList

//  class Node {
//  public:
//      int data;
//      Node* next;
//      Node() : data(0), next(nullptr) {}
//      Node(int x) : data(x), next(nullptr) {}
//      Node(int x, Node* next) : data(x), next(next) {}
//  };

// Approach 1: Iterative
// We create a new node(new last node) for the given element.
// We iterate over the linked list till the current node is NULL.
// We set the next of the current node to the new last node.
// We return the head of the linked list.
// Time complexity: O(n)
// Space complexity: O(1)

Node *insertAtLast(Node *head, int newValue)
{
    Node *lastNode = new Node(newValue);
    if (head == NULL)
    {
        return lastNode;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = lastNode;
    return head;
}

// Approach 2: Recursive
// We return the new node if the head is NULL.
// We return the head if the next of the head is NULL.
// We return the return value of the recursive call for the next of the head.
// Time complexity: O(n)
// Space complexity: O(n)

Node *insertAtLast(Node *head, int newValue)
{
    Node *newNode = new Node(newValue);
    if (head == NULL)
    {
        return newNode;
    }
    if (head->next == NULL)
    {
        head->next = newNode;
        return head;
    }
    head->next = insertAtLast(head->next, newValue);
    return head;
}