# Backtracking

## 🔍 1. When Should Backtracking Be Used?

### ✅ Use Backtracking when:
- You need to **find all possible combinations**, **permutations**, or **subsets** (e.g., solving for all valid configurations of a problem).
- The problem involves making a sequence of decisions where some of them might not lead to a solution (i.e., the solution space is large, and we need to backtrack to explore other possibilities).
- You want to **prune the search space** by discarding invalid options early and avoiding unnecessary work.
- You are solving problems involving **constraint satisfaction**, such as Sudoku, N-Queens, or graph coloring.

### 🧠 Keywords to look for:
- "All combinations"
- "All subsets"
- "Permutations"
- "Backtrack"
- "Find all solutions"
- "Recursive search"
- "State space tree"
- "Pruning"

---

## 💣 2. Brute Force Approach

In a brute-force approach, you might try every possible solution without any pruning or backtracking. This means:
- **Checking all possible combinations** or **permutations** one by one.
- **Trying all possible paths** in a decision tree without any pruning, which can lead to **high time complexity**.

For example, in the **N-Queens problem**, the brute force method would involve trying to place queens in every row and column, checking for validity each time, without pruning invalid partial solutions early.

While backtracking is efficient by pruning dead ends early, brute force would simply generate all possibilities and check each one.

---

## 🛠️ 3. How Backtracking Works + C++ Template

Backtracking is typically implemented using **recursion** and involves the following steps:

1. **Choose an option** and try it.
2. **Explore** the option (recursively).
3. **Backtrack** (undo the choice) if it leads to an invalid solution, and then try the next option.
4. **Repeat** until all possibilities are explored.

### Backtracking Steps:
- Start with an initial state (e.g., an empty board or an empty combination).
- Try all possible values for the current state.
- For each value, check if the current state is **valid**.
- If valid, **recurse** deeper (make the next choice).
- If the current state is **invalid**, backtrack and try the next choice.

---

### ✅ Template: Solving Combinations using Backtracking

Here’s an example of solving the **combinations** problem using backtracking.

**Problem**: Given `n` and `k`, find all possible combinations of `k` numbers chosen from 1 to `n`.

```cpp
void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if the current combination is of size k
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Try all numbers from 'start' to 'n'
    for (int i = start; i <= n; i++) {
        // Make a choice: add i to the current combination
        current.push_back(i);
        
        // Recurse: move to the next choice
        backtrack(i + 1, k, n, current, result);
        
        // Backtrack: remove the last element and try the next option
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, k, n, current, result);
    return result;
}
```

In this template:
- `current` is the current combination we are building.
- `backtrack` is a recursive function that tries adding each number to the combination.
- **Pruning** happens when the current combination size exceeds `k` or when the combination reaches a valid size.

### ✅ Template: Solving N-Queens using Backtracking

The **N-Queens problem** involves placing `n` queens on an `n x n` chessboard such that no two queens threaten each other. This problem is solved via backtracking by exploring the rows and columns recursively.

```cpp
bool isSafe(int row, int col, vector<string>& board, int n) {
    // Check this column on the left side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void solveNQueens(int row, vector<string>& board, vector<vector<string>>& result, int n) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';  // Place the queen
            solveNQueens(row + 1, board, result, n);  // Recurse for next row
            board[row][col] = '.';  // Backtrack (remove the queen)
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));  // Initialize empty board
    solveNQueens(0, board, result, n);
    return result;
}
```

### Explanation:
- We are placing one queen at a time and **checking if it’s safe** to place it on the board (i.e., no other queen threatens it).
- If placing the queen results in a valid configuration, we recurse to the next row.
- If not, we backtrack by **removing the queen** and trying the next column.

---

## 📚 4. Problems Related to Backtracking

### 🟢 Easy
- [Leetcode 78](https://leetcode.com/problems/subsets/) – Subsets (Find all subsets of a set)
- [Leetcode 46](https://leetcode.com/problems/permutations/) – Permutations (Find all permutations of a set)

### 🟡 Medium
- [Leetcode 39](https://leetcode.com/problems/combination-sum/) – Combination Sum (Find all combinations of numbers that sum up to a target)
- [Leetcode 40](https://leetcode.com/problems/combination-sum-ii/) – Combination Sum II (Find all combinations with duplicates allowed)
- [Leetcode 51](https://leetcode.com/problems/n-queens/) – N-Queens (Place N queens on an N x N chessboard)
- [Leetcode 77](https://leetcode.com/problems/combinations/) – Combinations (Find all combinations of size `k` from a set of `n` elements)

### 🔴 Hard
- [Leetcode 51](https://leetcode.com/problems/n-queens/) – N-Queens (N-Queens problem)
- [Leetcode 37](https://leetcode.com/problems/sudoku-solver/) – Sudoku Solver (Fill a partially filled Sudoku board)
- [Leetcode 212](https://leetcode.com/problems/word-search-ii/) – Word Search II (Find all words in a board)
  
---

### Key Takeaways:
- **Backtracking** is a systematic approach used to solve problems by exploring all possibilities and **pruning invalid choices** early.
- Backtracking is often used for problems involving **combinations**, **permutations**, **subsets**, and **constraint satisfaction**.
- The core of backtracking is **recursion** and **backtracking** (undoing a choice if it leads to an invalid solution).

Would you like to explore any specific backtracking problems or see more examples?