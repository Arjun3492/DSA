

## **Dynamic Programming Patterns**

### 1. **When to Use Dynamic Programming (DP)**

**DP** should be used when:
- The problem can be **broken down into smaller overlapping subproblems**.
- The problem has an **optimal substructure**, meaning that the solution to the problem can be constructed efficiently from solutions to its subproblems.
  
### **Keywords to Look For:**
- "Optimal substructure"
- "Subproblem"
- "Memoization"
- "Tabulation"
- "Minimization/Maximization"
- "Fibonacci-style recurrence"
- "Knapsack problem"
- "Edit distance"

---

### 2. **Brute Force Approach (Without DP)**

Without DP, the brute force approach often involves **solving the same subproblems repeatedly**, leading to **exponential time complexity**.

#### Example (Fibonacci Sequence):
- **Brute Force**: Recursively calculating Fibonacci numbers without storing previous results. The time complexity is exponential, \(O(2^n)\), due to recalculating the same Fibonacci numbers multiple times.
  
- **DP**: Solving each subproblem once and storing the results (either using **memoization** or **tabulation**) avoids redundant calculations, leading to linear time complexity, \(O(n)\).

---

### 3. **How Dynamic Programming Works**

Dynamic programming solves problems by breaking them down into smaller **subproblems** and storing their results to avoid redundant work.

### **DP Approaches**:
- **Top-Down (Memoization)**: Solves the problem recursively and stores the results of subproblems as they are computed.
- **Bottom-Up (Tabulation)**: Solves the problem iteratively, starting with the smallest subproblems and building up to the final solution.

### **Steps to Solve DP Problems**:
1. **Characterize the structure of the optimal solution** (Identify subproblems).
2. **Define the state** (State representation of the subproblem).
3. **Write the recurrence relation** (How to compute a solution from its subproblems).
4. **Implement using memoization or tabulation**.

---

### **C++ Template for DP (Bottom-Up)**

Here’s a generic C++ template for solving DP problems using the **bottom-up approach (tabulation)**:

```cpp
#include <vector>
#include <iostream>

using namespace std;

int solveDP(int n) {
    // DP table to store results of subproblems
    vector<int> dp(n + 1, 0);

    // Base case
    dp[0] = 1; // or some other initial condition

    // Bottom-up calculation
    for (int i = 1; i <= n; ++i) {
        // Apply recurrence relation
        dp[i] = dp[i - 1] + (i > 1 ? dp[i - 2] : 0); // example recurrence
    }

    return dp[n]; // Final solution
}

int main() {
    int n = 10;
    cout << "Result: " << solveDP(n) << endl;
    return 0;
}
```

In this template:
- `dp[i]` stores the solution to the subproblem for `i`.
- The solution is built iteratively, using the previously solved subproblems.

---

### **C++ Template for DP (Top-Down with Memoization)**

Here’s a generic C++ template for solving DP problems using **memoization**:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int solveDP(int n, vector<int>& memo) {
    // Base case
    if (n == 0) return 1; // or other base case

    // If result already computed, return it
    if (memo[n] != -1) return memo[n];

    // Solve subproblems and store in memo table
    memo[n] = solveDP(n - 1, memo) + (n > 1 ? solveDP(n - 2, memo) : 0); // example recurrence
    return memo[n];
}

int main() {
    int n = 10;
    vector<int> memo(n + 1, -1); // Initialize memoization table
    cout << "Result: " << solveDP(n, memo) << endl;
    return 0;
}
```

In this template:
- `memo[i]` stores the result for the subproblem for `i`.
- If `memo[i]` has already been computed, it is returned directly to avoid recomputation.

---

### 4. **Common Dynamic Programming Problems**

Here are some common problems that are solved using **Dynamic Programming**:

#### **1. Fibonacci Sequence**
- **Problem**: Find the `n`th Fibonacci number.
- **Approach**: Store previously computed Fibonacci numbers to avoid redundant calculations.
- **Example**:  
  [Leetcode 509](https://leetcode.com/problems/fibonacci-number/)

#### **2. Knapsack Problem**
- **Problem**: Given a set of items, each with a weight and value, determine the maximum value that can be obtained with a knapsack of a given capacity.
- **Approach**: Use a DP table to store the maximum value for each weight capacity up to the given capacity.
- **Example**:  
  [Leetcode 416](https://leetcode.com/problems/partition-equal-subset-sum/)

#### **3. Longest Common Subsequence (LCS)**
- **Problem**: Find the longest subsequence that is common to two strings.
- **Approach**: Use a 2D DP table to store the length of the LCS for substrings of the two strings.
- **Example**:  
  [Leetcode 1143](https://leetcode.com/problems/longest-common-subsequence/)

#### **4. Longest Increasing Subsequence (LIS)**
- **Problem**: Find the longest increasing subsequence in a sequence of numbers.
- **Approach**: Use a DP table to store the length of the longest increasing subsequence for each element.
- **Example**:  
  [Leetcode 300](https://leetcode.com/problems/longest-increasing-subsequence/)

#### **5. Coin Change Problem**
- **Problem**: Given a set of coin denominations, find the minimum number of coins required to make a given amount.
- **Approach**: Use a DP table to store the minimum number of coins for every amount up to the target.
- **Example**:  
  [Leetcode 322](https://leetcode.com/problems/coin-change/)

#### **6. Edit Distance (Levenshtein Distance)**
- **Problem**: Given two strings, find the minimum number of operations (insertions, deletions, substitutions) required to convert one string to another.
- **Approach**: Use a 2D DP table to store the minimum edit distance for substrings of the two strings.
- **Example**:  
  [Leetcode 72](https://leetcode.com/problems/edit-distance/)

#### **7. Subset Sum Problem**
- **Problem**: Given a set of numbers, determine if there is a subset whose sum is equal to a given target.
- **Approach**: Use a DP table to track whether a subset sum exists for every possible sum.
- **Example**:  
  [Leetcode 416](https://leetcode.com/problems/partition-equal-subset-sum/)

---

### Key Takeaways
- **Dynamic Programming (DP)** helps in solving problems that can be broken down into overlapping subproblems and require optimal substructure.
- DP uses **memoization** (top-down) or **tabulation** (bottom-up) techniques to store results of subproblems and avoid redundant work.
- Common DP problems include **Knapsack**, **Longest Common Subsequence**, **Fibonacci**, **Coin Change**, etc.

