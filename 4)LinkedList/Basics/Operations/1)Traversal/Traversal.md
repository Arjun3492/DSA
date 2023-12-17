# Traversal

## Traversing a Linked List

### Algorithm:

1. Initialize a node pointer, current = head.
2. Do following while current is not NULL
   1. current = current -> next
   2. current -> data

### Code:

```cpp
// Iterative C++ program to traverse
// a linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// This function prints contents of
// linked list starting from head
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

// Driver code
int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with
    // the second node

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    printList(head);
    return 0;
}
```
