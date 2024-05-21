// Implement stack using linked list

// Link : https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475

// Solution:
// We use a linked list to implement a stack. The top of the stack is the head of the linked list.
//  We can push an element onto the stack by creating a new node with the given data and pointing it to the current top and updating the top to the new node.
//  We can pop an element from the stack by removing the current top and updating the top to the next node.
class Stack
{
private:
    int size = 0;        // Initialize the size of the stack to 0
    Node *top = nullptr; // Initialize the top of the stack as nullptr

public:
    Stack()
    {
        // Constructor: Initialize the stack (no additional setup needed)
    }

    int getSize()
    {
        // Get the current size of the stack
        return size;
    }

    bool isEmpty()
    {
        // Check if the stack is empty
        return top == nullptr;
    }

    void push(int data)
    {
        // Push an element onto the stack
        Node *newNode = new Node(data); // Create a new node with the given data
        newNode->next = top;            // Point the new node to the current top
        top = newNode;                  // Update the top to the new node
        size++;                         // Increase the size of the stack
    }

    void pop()
    {
        // Pop the top element from the stack
        if (top == nullptr)
            return; // If the stack is empty, no need to pop

        Node *toBeDeleted = top; // Create a temporary pointer to the current top
        top = top->next;         // Update the top to the next node
        delete toBeDeleted;      // Free the memory of the popped node
        size--;                  // Decrease the size of the stack
    }

    int getTop()
    {
        // Get the top element of the stack without removing it
        if (top == nullptr)
            return -1;    // If the stack is empty, return -1
        return top->data; // Return the data of the top node
    }
};
