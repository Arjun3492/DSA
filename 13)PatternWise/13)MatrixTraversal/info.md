# Matrix Traversal

## 🔍 1. When Should Matrix Traversal Be Used?

### ✅ Use Matrix Traversal when:
- You need to **visit every element** in a 2D matrix or grid.
- You're solving problems that require navigating the matrix in **specific directions** (e.g., up, down, left, right, diagonals).
- You're dealing with **pathfinding** problems in a grid, such as finding the shortest path, detecting obstacles, or searching for specific values.
- You are working with **dynamic programming** problems that involve 2D grids (like **Longest Common Subsequence**, **Knapsack**, or **Matrix Chain Multiplication**).

### 🧠 Keywords to look for:
- "Traverse the matrix"
- "2D grid"
- "Grid path"
- "Find element in matrix"
- "Matrix traversal"
- "Find shortest path"
- "Dynamic programming on grids"
- "Top-left to bottom-right"
- "Boundary traversal"
- "Diagonal traversal"

---

## 💣 2. Brute Force Approach

In a brute force approach, you might visit each cell of the matrix one by one using **nested loops** or **recursive calls**, which is inefficient for larger matrices.

For example, in a **searching problem**, a brute force approach might involve checking each element in the matrix individually to see if it matches a target, resulting in a time complexity of O(m * n), where m is the number of rows and n is the number of columns.

In other cases, you might not optimize the traversal direction, leading to repetitive checks.

---

## 🛠️ 3. How Matrix Traversal Works + C++ Template

Matrix traversal generally involves iterating over the rows and columns of the matrix. Depending on the problem, the traversal might be **row-major** (left to right) or **column-major** (top to bottom), and it may follow **specific directions** such as up, down, left, right, or diagonally.

Here are a few common traversal techniques:

### ✅ Template 1: Basic Traversal (Row-major order)

In this type of traversal, we simply visit each element in the matrix, row by row.

```cpp
void traverseMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();      // Number of rows
    int n = matrix[0].size();   // Number of columns
    
    for (int i = 0; i < m; i++) {       // Iterate through rows
        for (int j = 0; j < n; j++) {   // Iterate through columns
            cout << matrix[i][j] << " "; // Process each element
        }
        cout << endl;  // Move to the next row
    }
}
```

### ✅ Template 2: Traversal (Column-major order)

If you want to traverse the matrix **column by column** (e.g., from top to bottom for each column):

```cpp
void traverseMatrixByColumns(vector<vector<int>>& matrix) {
    int m = matrix.size();      // Number of rows
    int n = matrix[0].size();   // Number of columns
    
    for (int j = 0; j < n; j++) {       // Iterate through columns
        for (int i = 0; i < m; i++) {   // Iterate through rows
            cout << matrix[i][j] << " "; // Process each element
        }
        cout << endl;  // Move to the next column
    }
}
```

### ✅ Template 3: Boundary Traversal

Some problems require **boundary traversal** (visiting the outer edges of the matrix). This is often used in problems related to spiral traversal or finding the perimeter of a grid.

```cpp
void boundaryTraversal(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Print the first row
    for (int j = 0; j < n; j++) {
        cout << matrix[0][j] << " ";
    }
    
    // Print the last column
    for (int i = 1; i < m; i++) {
        cout << matrix[i][n-1] << " ";
    }
    
    // Print the last row (if it exists)
    if (m > 1) {
        for (int j = n-2; j >= 0; j--) {
            cout << matrix[m-1][j] << " ";
        }
    }
    
    // Print the first column (if it exists)
    if (n > 1) {
        for (int i = m-2; i > 0; i--) {
            cout << matrix[i][0] << " ";
        }
    }
}
```

### ✅ Template 4: Diagonal Traversal

If the problem requires **diagonal traversal** (e.g., visiting elements from top-left to bottom-right diagonally), you can handle this by adjusting the indices appropriately.

```cpp
void diagonalTraversal(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Traverse the upper triangle (including the main diagonal)
    for (int i = 0; i < m; i++) {
        int row = i, col = 0;
        while (row < m && col < n) {
            cout << matrix[row][col] << " ";
            row++;
            col++;
        }
    }

    // Traverse the lower triangle (excluding the main diagonal)
    for (int j = 1; j < n; j++) {
        int row = 0, col = j;
        while (row < m && col < n) {
            cout << matrix[row][col] << " ";
            row++;
            col++;
        }
    }
}
```

---

## 📚 4. Problems Related to Matrix Traversal

### 🟢 Easy
- [Leetcode 54](https://leetcode.com/problems/spiral-matrix/) – Spiral Matrix (Boundary traversal with spiral order)
- [Leetcode 88](https://leetcode.com/problems/merge-sorted-array/) – Merge Sorted Array (Matrix-like two-pointer technique)
- [Leetcode 240](https://leetcode.com/problems/search-a-2d-matrix-ii/) – Search a 2D Matrix II (Matrix search in a sorted matrix)

### 🟡 Medium
- [Leetcode 79](https://leetcode.com/problems/word-search/) – Word Search (Matrix traversal with DFS)
- [Leetcode 733](https://leetcode.com/problems/flood-fill/) – Flood Fill (Matrix traversal with BFS or DFS)
- [Leetcode 73](https://leetcode.com/problems/set-matrix-zeroes/) – Set Matrix Zeroes (Modify matrix elements during traversal)

### 🔴 Hard
- [Leetcode 329](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) – Longest Increasing Path in a Matrix (DFS with memoization)
- [Leetcode 174](https://leetcode.com/problems/dungeon-game/) – Dungeon Game (Dynamic programming with matrix traversal)
- [Leetcode 1326](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/) – Minimum Number of Taps to Open (Matrix with dynamic programming)

---

### Key Takeaways:
- **Matrix Traversal** is essential when dealing with problems on 2D grids, including grid-based pathfinding, dynamic programming, and matrix manipulations.
- Traversal can be done in several ways: **row-major**, **column-major**, **boundary**, or **diagonal** traversal depending on the problem’s requirements.
- Efficient matrix traversal is crucial in solving **graph-related problems**, **flood-fill problems**, and **shortest path problems** in grids.