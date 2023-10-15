// Problem Statment: implement queue using stack
// Queue: A Queue is a linear data structure that works on the basis of FIFO(First in First out).
// This means the element added at first will be removed first from the Queue.

// Solution
// For the enQueue operation, we reverse the order of elements in mainStack by moving them to tempStack,
// then push the new element onto mainStack, and finally move the elements back from tempStack to mainStack.
// This ensures that the most recently enqueued element is placed at the bottom of mainStack.
#include <stack>

class Queue
{
    // Define the data members(if any) here.
    stack<int> mainStack, tempStack;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        while (!mainStack.empty())
        {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        mainStack.push(val);
        while (!tempStack.empty())
        {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (mainStack.empty())
            return -1;
        int ans = mainStack.top();
        mainStack.pop();
        return ans;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (mainStack.empty())
            return -1;
        return mainStack.top();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return mainStack.empty();
    }
};