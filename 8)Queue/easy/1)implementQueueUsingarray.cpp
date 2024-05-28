// Problem Statement: Implement Queue Data Structure using Array with the following functions:
// 1. enqueue() which takes an integer as input and adds it to the queue.
// 2. dequeue() which removes an element from the front of the queue.

// Link: https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

// Solution: use array
// Take two pointers front and rear, both pointing to 0, for empty queue
// Enqueue: add the element to the rear of the queue and increment rear
// Dequeue: return the element at the front of the queue and increment front

class Queue
{

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    bool isEmpty()
    {
        return front == rear;
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        if (rear == arr.size())
            return;
        arr[rear++] = e;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front == rear)
            return -1;
        return arr[front++];
    }

    // Front Element return the front element of the queue
    int frontElement()
    {
        if (front == rear)
            return -1;
        return arr[front];
    }
};