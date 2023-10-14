//Press Ctrl+K V to preview

### Recursion Basics

1. **What is Recursion?**

   - Recursion is a programming technique where a function calls itself in order to solve a problem.

2. **Base Case:**

   - Every recursive function must have one or more base cases to prevent infinite recursion.
   - Base cases are the simplest, terminating cases that do not make further recursive calls.

3. **Recursive Case:**
   - The part of the function that makes the recursive call(s) to solve a smaller or simpler subproblem.

### Steps for Writing Recursive Functions

1. **Define the Recursive Function:**

   - Declare the function with a return type, a name, and parameters.

2. **Define Base Cases:**

   - Determine when the function should stop making recursive calls and return a result.

3. **Define Recursive Cases:**

   - Break down the problem into smaller subproblems.
   - Call the function recursively with these subproblems.

4. **Combine Results:**
   - Combine the results from recursive calls to solve the original problem.

### Example: Factorial Calculation

```cpp
int factorial(int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive Case
    //Since we know that n! = n * (n-1)!, we can use this to calculate the factorial recursively.
    return n * factorial(n - 1);
}
```

### Example: Fibonacci Sequence

```cpp
int fibonacci(int n) {
    // Base Cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive Case
    // Since we know that the Fibonacci sequence is defined by the sum of the previous two numbers, we can use this to calculate the nth Fibonacci number recursively.
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Tips for Using Recursion

1. **Carefully choose base cases:** Ensure that the base cases are well-defined and cover all possible scenarios to avoid infinite recursion.

2. **Optimization:** Some recursive algorithms can be optimized using techniques like memoization or dynamic programming to avoid redundant calculations.

3. **Stack Overflow:** Be cautious of stack overflow errors when dealing with deep recursion. Consider iterative solutions for large inputs.

4. **Test thoroughly:** Test your recursive functions with various inputs, including edge cases, to ensure correctness.

5. **Readability:** Write clear and well-commented code to make it easier for others (and yourself) to understand the recursive logic.

6. **Recursive vs. Iterative:** In some cases, recursion may not be the most efficient solution. Consider iterative alternatives when appropriate.

Remember that recursion can be a powerful tool when used correctly, but it's essential to understand the problem and its requirements before deciding to use recursion.
