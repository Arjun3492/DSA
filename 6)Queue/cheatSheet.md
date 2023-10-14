# Certainly! Here's a cheat sheet for queues in C++:

** Tutorial https://youtu.be/M6GnoUDpqEE?si=zZ4BAFe0YgFDnrBd **

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Declaration and Initialization
    queue<int> q;

    // Basic Operations
    q.push(10);         // Insert an element at the back
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Access the front element
    cout << "Queue size: " << q.size() << endl;     // Get the size of the queue

    q.pop();            // Remove the front element
    cout << "Front element after pop: " << q.front() << endl;

    // Checking if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    // Iterating through the queue
    while (!q.empty()) {
        cout << q.front() << " ";  // Print front element
        q.pop();                  // Remove front element
    }
    cout << endl;

    return 0;
}
```

This cheat sheet covers the basic operations and usage of queues in C++. You can copy and paste this code into a C++ environment and modify it as needed for your specific application.

# Queue implementation using array

Sure, here's an implementation of a queue using an array with method names similar to those used in the C++ STL:

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

class MyQueue {
private:
    int front, rear, capacity;
    int* array;

public:
    MyQueue(int size) {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }

    ~MyQueue() {
        delete[] array;
    }

    bool empty() {
        return front == -1;
    }

    bool full() {
        return (rear + 1) % capacity == front;
    }

    void push(int item) {
        if (full()) {
            throw overflow_error("Queue is full. Cannot push.");
        }
        if (empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        array[rear] = item;
    }

    void pop() {
        if (empty()) {
            throw underflow_error("Queue is empty. Cannot pop.");
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int front() {
        if (empty()) {
            throw underflow_error("Queue is empty. Cannot access front.");
        }
        return array[front];
    }

    int size() {
        if (empty()) {
            return 0;
        }
        if (rear >= front) {
            return rear - front + 1;
        } else {
            return capacity - front + rear + 1;
        }
    }
};

int main() {
    MyQueue myQueue(5);

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    cout << "Front element: " << myQueue.front() << endl;
    cout << "Queue size: " << myQueue.size() << endl;

    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}
```

This code implements a queue using an array with method names similar to those used in the C++ STL, such as `empty()`, `full()`, `push()`, `pop()`, `front()`, and `size()`. It also includes error handling for cases when attempting to push or pop from an empty or full queue.
