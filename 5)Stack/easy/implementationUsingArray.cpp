// Problem statement: Implement a stack using an array.
//  Note: Stack is a data structure that follows the Last In First Out (LIFO) rule.

// Solution: use array
// Take pointer topIndex as -1, for empty stack
// Push: increment topIndex and add the element to the stack
// Pop: return the top element and decrement topIndex
// Top: return the top element without removing it
// isEmpty: return 1 if topIndex is -1, else return 0
// isFull: return 1 if topIndex is equal to size - 1, else return 0
//  Stack class.
class Stack
{
private:
    int *arr;     // Array to store stack elements
    int size;     // Maximum capacity of the stack
    int topIndex; // Index of the top element (-1 when empty)

public:
    Stack(int capacity)
    {
        size = capacity;     // Initialize the stack size
        arr = new int[size]; // Create an array of integers to hold the stack elements
        topIndex = -1;       // Initialize topIndex to -1 to represent an empty stack
    }

    void push(int num)
    {
        if (topIndex == size - 1)
        {
            return; // Stack is full, so return without pushing
        }
        arr[++topIndex] = num; // Increment topIndex and add the element to the stack
    }

    int pop()
    {
        if (topIndex == -1)
            return -1;          // Stack is empty, return -1 to indicate underflow
        return arr[topIndex--]; // Return the top element and decrement topIndex
    }

    int top()
    {
        if (topIndex == -1)
            return -1;        // Stack is empty, return -1 to indicate underflow
        return arr[topIndex]; // Return the top element without removing it
    }

    int isEmpty()
    {
        if (topIndex == -1)
            return 1; // Stack is empty, return 1 to indicate true
        return 0;     // Stack is not empty, return 0 to indicate false
    }

    int isFull()
    {
        if (topIndex == size - 1)
            return 1; // Stack is full, return 1 to indicate true
        return 0;     // Stack is not full, return 0 to indicate false
    }
};
