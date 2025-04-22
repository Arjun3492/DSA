# Depth-First Search (DFS) - Pattern Wise

## 🔍 1. When Should Depth-First Search (DFS) Be Used?

### ✅ Use DFS when:
- You need to **explore all nodes** in a graph or tree.
- You’re solving problems that require **exploring deeper into a structure before backtracking**.
- The problem involves **finding connected components**, **cycles**, **pathfinding**, or **backtracking**.

### 🧠 Keywords to look for:
- "Traverse all nodes"
- "Explore each node"
- "Connected components"
- "Pathfinding"
- "Cycle detection"
- "Backtracking"
- "All possible paths"
- "Depth-first traversal"
- "Graph search"
- "Tree search"

---

## 💣 2. Brute Force Approach

The brute force approach to traversing a graph or tree usually involves visiting each node using **nested loops** or **recursive calls**. Without DFS, you might end up re-visiting nodes or exploring nodes inefficiently.

### Example: **Graph Traversal Without DFS (Brute Force)**

In a naive approach without DFS, you might simply visit every node without any direction, which leads to redundant work and inefficient traversal.

For example, if we’re trying to find a path from node A to node B, you might try every node and check connections one by one, without considering the structure of the graph.

This can result in an exponential time complexity for pathfinding in large graphs, as you're not leveraging the depth-first approach.

---

## 🛠️ 3. How DFS Works + C++ Template

DFS can be implemented **recursively** or **iteratively** (using a stack). The core idea is to explore deeper into a branch of the graph/tree before backtracking. If you find a solution (or hit a dead end), you backtrack and try other possible branches.

### DFS Steps:
1. **Start at a node** (root or any starting node).
2. **Visit the node**, mark it as visited.
3. **Explore its neighbors** (in the case of a graph) or children (in the case of a tree).
4. **Backtrack** if necessary when you hit a dead end.

DFS is often implemented using a **recursive approach** (for trees) or using a **stack** (for graphs).

---

### ✅ Template: DFS for Tree Traversal (Recursive)

For a binary tree, DFS can be used to visit nodes in **preorder**, **inorder**, or **postorder**.

#### Preorder DFS Traversal (Root, Left, Right):

```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    cout << node->val << " ";  // Process node
    dfs(node->left);  // Visit left child
    dfs(node->right); // Visit right child
}
```

#### Inorder DFS Traversal (Left, Root, Right):

```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    dfs(node->left);  // Visit left child
    cout << node->val << " ";  // Process node
    dfs(node->right); // Visit right child
}
```

#### Postorder DFS Traversal (Left, Right, Root):

```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    dfs(node->left);  // Visit left child
    dfs(node->right); // Visit right child
    cout << node->val << " ";  // Process node
}
```

### ✅ Template: DFS for Graph Traversal (Recursive)

For graph traversal, DFS can be implemented using a **visited set** or **visited array** to keep track of visited nodes.

```cpp
void dfs(GraphNode* node, unordered_set<GraphNode*>& visited) {
    if (visited.count(node)) return;
    visited.insert(node);
    cout << node->val << " ";  // Process node
    
    for (auto neighbor : node->neighbors) {
        dfs(neighbor, visited);  // Visit neighbors
    }
}
```

### ✅ Template: DFS Using Stack (Iterative)

DFS can also be implemented using a stack for an **iterative** approach.

```cpp
void dfsIterative(GraphNode* start) {
    stack<GraphNode*> s;
    unordered_set<GraphNode*> visited;
    
    s.push(start);
    while (!s.empty()) {
        GraphNode* node = s.top();
        s.pop();
        
        if (visited.count(node)) continue;
        visited.insert(node);
        
        cout << node->val << " ";  // Process node
        
        // Push neighbors to the stack
        for (auto neighbor : node->neighbors) {
            s.push(neighbor);
        }
    }
}
```

---

## 📚 4. Problems Related to Depth-First Search (DFS)

### 🟢 Easy
- [Leetcode 104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) – Maximum Depth of Binary Tree (DFS for depth calculation)
- [Leetcode 100](https://leetcode.com/problems/same-tree/) – Same Tree (DFS for tree comparison)
- [Leetcode 226](https://leetcode.com/problems/invert-binary-tree/) – Invert Binary Tree (DFS for flipping)

### 🟡 Medium
- [Leetcode 200](https://leetcode.com/problems/number-of-islands/) – Number of Islands (DFS for finding connected components in a grid)
- [Leetcode 1026](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/) – Maximum Difference Between Node and Ancestor (DFS for tree traversal)
- [Leetcode 144](https://leetcode.com/problems/binary-tree-preorder-traversal/) – Binary Tree Preorder Traversal (DFS for visiting nodes)

### 🔴 Hard
- [Leetcode 291](https://leetcode.com/problems/word-pattern-ii/) – Word Pattern II (DFS with backtracking)
- [Leetcode 46](https://leetcode.com/problems/permutations/) – Permutations (DFS with backtracking)
- [Leetcode 329](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) – Longest Increasing Path in a Matrix (DFS with memoization)
- [Leetcode 22](https://leetcode.com/problems/generate-parentheses/) – Generate Parentheses (DFS with backtracking)

---

### Key Takeaways:
- **DFS** is great for **tree and graph traversal**, especially when you're interested in exploring all possible paths or searching for a solution deep in the structure before backtracking.
- It's commonly used in **backtracking problems** (e.g., generating permutations) and **graph search problems** (e.g., detecting cycles, finding connected components).
- DFS can be implemented recursively or iteratively using a **stack**.

Would you like to explore a particular problem or dive into a more advanced use case for DFS?