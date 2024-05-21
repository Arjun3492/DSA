// Problem Statement: Implement a Stack using two Queues.

// Link : https://www.naukri.com/code360/problems/stack-using-queue_795152

// Working
//  This implementation of a stack using two queues in C++ works by maintaining the stack's last-in, first-out (LIFO) behavior through a clever arrangement of the two queues (mainQueue and tempQueue). Here's a short explanation of how it works:

// Push Operation: When a new element is to be pushed to stack, it is firstly added to tempQueue(empty) and then all the elements of mainQueue are moved to tempQueue. Finally, the name of the two queues are swapped, making tempQueue the new mainQueue.
// This way, the new element is always added to the front of mainQueue, which is the top of the stack.

// Pop Operation: The pop function simply removes the front element from mainQueue, simulating the
// removal of the top element of the stack. If mainQueue is empty, it means the stack is empty, and -1
// is returned to indicate an error.

// Top Operation: The top function returns the front element of mainQueue,
// which corresponds to the top element of the stack. If mainQueue is empty, it also returns -1 to indicate an error.

// Size and Empty Check: The getSize function returns the size of mainQueue,
// effectively giving the size of the stack. The isEmpty function checks if mainQueue is empty,
// indicating whether the stack is empty or not.

// Time Complexity
//  The time complexity of the push operation is O(n), where n is the number of elements in the stack.
// This is because the push operation involves moving all the elements from mainQueue to tempQueue, which takes O(n) time.
// The time complexity of the pop and top operations is O(1), as these operations do not involve any traversal or
// re-arrangement of elements. The time complexity of the isEmpty and getSize operations is also O(1),

// Space Complexity
//  The space complexity of the stack is O(n), where n is the number of elements in the stack.
// This is because the stack is implemented using two queues, each of which has a space complexity of O(n).

class Stack
{
    // Define the data members.
private:
    queue<int> mainQueue; // First queue to simulate the stack.
    queue<int> tempQueue; // Second queue used for auxiliary operations.

public:
    Stack()
    {
        // Implement the Constructor.
        // Constructor is typically used for initializing data members, but no specific initialization is required here.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return mainQueue.size(); // Return the size of the first queue, which represents the size of the stack.
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return mainQueue.empty(); // Check if the first queue is empty to determine if the stack is empty.
    }

    void push(int element)
    {
        // Implement the push() function.
        tempQueue.push(element); // Push the new element into the second queue.

        // Move elements from the first queue to the second queue to maintain the stack order.
        while (!mainQueue.empty())
        {
            tempQueue.push(mainQueue.front()); // Move elements from the first queue to the second queue.
            mainQueue.pop();                   // Remove the element from the first queue.
        }

        swap(mainQueue, tempQueue); // Swap the names of the two queues to make the first queue contain the elements in stack order.
    }

    int pop()
    {
        // Implement the pop() function.
        if (mainQueue.empty())
            return -1; // Return -1 if the stack is empty.

        int el = mainQueue.front(); // Get the top element of the stack.
        mainQueue.pop();            // Remove the top element from the stack.
        return el;                  // Return the removed element.
    }

    int top()
    {
        if (mainQueue.empty())
            return -1; // Return -1 if the stack is empty.

        // Implement the top() function.
        return mainQueue.front(); // Return the top element of the stack (front of the first queue).
    }
};
