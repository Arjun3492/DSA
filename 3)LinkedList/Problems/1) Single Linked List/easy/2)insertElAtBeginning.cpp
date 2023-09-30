// Problem Statement: To insert the given element at the start of linkedList

//  class Node {
//  public:
//      int data;
//      Node* next;
//      Node() : data(0), next(nullptr) {}
//      Node(int x) : data(x), next(nullptr) {}
//      Node(int x, Node* next) : data(x), next(next) {}
//  };

// Approach 1: Iterative
// We create a new node(new head) for the given element.
// We set the next of the new head to the given head of the linked list.
// We return the newHead.
// Time complexity: O(1)
// Space complexity: O(1)

Node *insertAtFirst(Node *head, int newValue)
{
    Node *newHead = new Node(newValue, head);
    return newHead;
}
