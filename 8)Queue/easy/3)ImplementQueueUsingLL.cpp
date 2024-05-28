// Implement Queue using Linked List
//  Problem Statement: Implement Queue Data Structure using Linked List with the following functions:

// enqueue() which takes an integer as input and adds it to the queue.
// dequeue() which removes an element from the front of the queue.

// SOLUTION: use linked list
// Take two pointers front and rear, both pointing to NULL, for empty queue
// Enqueue: if queue is empty, create a newNode and make front and rear point to it
//          else create a newNode and make rear->next point to it and update rear to the newNode

// Dequeue: if queue is empty, return -1
//          else store the data of the node pointed to by front in a variable, delete the node and update front to the next node
//          if front becomes NULL, update rear to NULL as well
//          return the variable storing the data of the deleted node

// Link : https://www.naukri.com/code360/problems/implement-queue-using-linked-list_8161235

/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 *
 * Definition of Queue
 * struct Queue {
 *   Node* front; // Pointer to the front of the queue
 *   Node* rear;  // Pointer to the rear of the queue
 *   void push(int); // Function to push an element into the queue
 *   int pop();     // Function to pop an element from the queue
 *
 *   Queue() {
 *       front = rear = NULL; // Initialize the queue as empty
 *   }
 * };
 */

void Queue::push(int x)
{
    // Push an element into the queue
    Node *newNode = new Node(x); // Create a new node with the given data
    if (front == NULL)
    {
        front = newNode; // If the queue is empty, set both front and rear to the new node
        rear = newNode;
    }
    else
    {
        rear->next = newNode; // Point the current rear to the new node
        rear = newNode;       // Update the rear to the new node
    }
}

int Queue::pop()
{
    if (front == nullptr)
        return -1;              // If the queue is empty, return -1 to indicate an empty queue
    Node *toBeDeleted = front;  // Create a temporary pointer to the front node
    int el = toBeDeleted->data; // Get the data from the front node
    front = front->next;        // Update the front to the next node
    if (front == nullptr)
        rear = nullptr; // If the queue is now empty, set rear also to nullptr
    delete toBeDeleted; // Free the memory of the popped node
    return el;          // Return the popped element
}
