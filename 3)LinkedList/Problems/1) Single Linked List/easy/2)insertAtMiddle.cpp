// Problem Statement: To insert the given element at kth position of linkedList

//  class Node {
//  public:
//      int data;
//      Node* next;
//      Node() : data(0), next(nullptr) {}
//      Node(int x) : data(x), next(nullptr) {}
//      Node(int x, Node* next) : data(x), next(next) {}
//  };

// Approach 1: Iterative
// We create a new node(new kth node) for the given element.
// We iterate over the linked list to reach the k-1th node.
// We set the next of the new kth node to the next of the k-1th node.
// We set the next of the k-1th node to the new kth node.
// We return the head of the linked list.
// Time complexity: O(k)
// Space complexity: O(1)

Node *insertAtFirst(Node *head, int k, int newValue)
{
    Node *newNode = new Node(newValue);
    if (k == 1)
    {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    int i = 1;
    while (i < k)
    {
        curr = curr->next;
        i++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Approach 2: Recursive
// We return the new node if the head is NULL and k is 1.
// We return the head if the head is NULL and k is not 1.
// We return the head if the k is 1.
// We return the return value of the recursive call for the next of the head and k-1.
// Time complexity: O(k)
// Space complexity: O(k)

Node *insertAtFirst(Node *head, int k, int newValue)
{
    Node *newNode = new Node(newValue);
    if (head == NULL && k == 1)
    {
        return newNode;
    }
    if (head == NULL && k != 1)
    {
        return head;
    }
    if (k == 1)
    {
        newNode->next = head;
        return newNode;
    }
    head->next = insertAtFirst(head->next, k - 1, newValue);
    return head;
}