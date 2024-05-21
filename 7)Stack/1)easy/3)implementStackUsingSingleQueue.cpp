// Problem statement:Implement stack using single queue

// Link : https://www.geeksforgeeks.org/implement-a-stack-using-single-queue/

// Solution:
// We compute the current the size of the queue and then push the new element into the queue.
//  then using a loop we pop the elements from the front and push them back into the queue.
//  This way the new element is at the front of the queue and the rest of the elements are in the same order as before.

//  Time complexity: O(n)
//  Space complexity: O(n)
class Stack
{
private:
    queue<int> mainQueue;

public:
    // Constructor for the Stack class
    Stack()
    {
        // Initialize the mainQueue (no additional setup needed)
    }

    /*----------------- Public Functions of Stack -----------------*/

    // Get the size of the stack
    int getSize()
    {
        return mainQueue.size();
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return mainQueue.empty();
    }

    // Push an element onto the stack
    void push(int element)
    {
        int n = mainQueue.size(); // Get the current size of the queue
        mainQueue.push(element);  // Push the new element onto the queue

        // Reorganize the queue to simulate a stack
        for (int i = 0; i < n; i++)
        {
            mainQueue.push(mainQueue.front()); // Move each element to the back of the queue
            mainQueue.pop();                   // Remove the element from the front
        }
    }

    // Pop the top element from the stack
    int pop()
    {
        if (mainQueue.empty())
            return -1; // Return -1 if the stack is empty

        int el = mainQueue.front(); // Get the front element (top of the stack)
        mainQueue.pop();            // Remove the top element from the stack
        return el;                  // Return the popped element
    }

    // Get the top element of the stack without removing it
    int top()
    {
        if (mainQueue.empty())
            return -1; // Return -1 if the stack is empty

        return mainQueue.front(); // Return the front element (top of the stack)
    }
};
