# Certainly! Here's a cheat sheet for basic stack operations in C++:

** Tutorial https://youtu.be/GYptUgnIM_I?si=uz19kJESaZjT-2vY **

```cpp
#include <iostream>
#include <stack>

int main() {
    // Create a stack
    std::stack<int> myStack;

    // Push an element onto the stack
    myStack.push(5);

    // Check if the stack is empty
    bool isEmpty = myStack.empty(); // Returns false

    // Get the size of the stack
    int size = myStack.size(); // Returns 1

    // Access the top element of the stack
    int topElement = myStack.top(); // Returns 5

    // Pop the top element from the stack
    myStack.pop();

    // Check if the stack is empty after popping
    isEmpty = myStack.empty(); // Returns true

    return 0;
}
```

This cheat sheet covers the following basic stack operations:

1. Creating a stack.
2. Pushing an element onto the stack using `push`.
3. Checking if the stack is empty using `empty`.
4. Getting the size of the stack using `size`.
5. Accessing the top element of the stack using `top`.
6. Popping the top element from the stack using `pop`.

Remember to include the necessary `#include` directives and the `using` statement for `std::stack` at the beginning of your C++ program.

# Stack implementation using array

```cpp
#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the stack

template <typename T>
class Stack {
private:
    T arr[MAX_SIZE]; // Array to store stack elements
    int top; // Index of the top element (-1 for an empty stack)

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = -1;
    }

    // Push an element onto the stack
    void push(const T& value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
        } else {
            std::cout << "Stack overflow!" << std::endl;
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (!empty()) {
            --top;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Get a reference to the top element of the stack
    T& top() {
        if (!empty()) {
            return arr[top];
        } else {
            std::cout << "Stack is empty. Cannot get top." << std::endl;
            // Return a reference to a sentinel value for an empty stack
            static T emptyValue;
            return emptyValue;
        }
    }

    // Check if the stack is empty
    bool empty() const {
        return (top == -1);
    }

    // Get the number of elements in the stack
    std::size_t size() const {
        return static_cast<std::size_t>(top + 1);
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(5);
    myStack.push(10);

    std::cout << "Top element: " << myStack.top() << std::endl; // Should print 10
    std::cout << "Stack size: " << myStack.size() << std::endl; // Should print 2

    myStack.pop();

    std::cout << "Top element after pop: " << myStack.top() << std::endl; // Should print 5

    return 0;
}
```

In this code, we define a `Stack` class with method names that mimic the STL `std::stack` library while implementing the stack using an array:

1. `push`: To push an element onto the stack.
2. `pop`: To pop the top element from the stack.
3. `top`: To get a reference to the top element of the stack.
4. `empty`: To check if the stack is empty.
5. `size`: To get the number of elements in the stack.

This class uses a static array to store stack elements, and you can create a `Stack` object with a specific data type (e.g., `Stack<int>` for integers) and use it similarly to `std::stack`.

# Stack implementation using linked list

Certainly! You can create a custom `Stack` class in C++ with method names that mimic the names used in the STL `std::stack` library. Here's how you can define such a class:

```cpp
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    // Constructor to initialize an empty stack
    Stack() {}

    // Push an element onto the stack
    void push(const T& value) {
        data.push_back(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (!empty()) {
            data.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Get a reference to the top element of the stack
    T& top() {
        if (!empty()) {
            return data.back();
        } else {
            std::cout << "Stack is empty. Cannot get top." << std::endl;
            // Return a reference to a sentinel value for an empty stack
            static T emptyValue;
            return emptyValue;
        }
    }

    // Check if the stack is empty
    bool empty() const {
        return data.empty();
    }

    // Get the number of elements in the stack
    std::size_t size() const {
        return data.size();
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(5);
    myStack.push(10);

    std::cout << "Top element: " << myStack.top() << std::endl; // Should print 10
    std::cout << "Stack size: " << myStack.size() << std::endl; // Should print 2

    myStack.pop();

    std::cout << "Top element after pop: " << myStack.top() << std::endl; // Should print 5

    return 0;
}
```

In this code, we define a `Stack` class with method names that mimic the STL `std::stack` library:

1. `push`: To push an element onto the stack.
2. `pop`: To pop the top element from the stack.
3. `top`: To get a reference to the top element of the stack.
4. `empty`: To check if the stack is empty.
5. `size`: To get the number of elements in the stack.

The class uses a `std::vector` to store the stack elements. You can create a `Stack` object with a specific data type (e.g., `Stack<int>` for integers) and use it similarly to `std::stack`.
