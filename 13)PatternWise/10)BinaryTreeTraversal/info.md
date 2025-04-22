# Binary Tree Traversal

## 🔍 1. When Should Binary Tree Traversal Be Used?

### ✅ Use this pattern when:
- You’re asked to visit all the nodes in a binary tree.
- The problem involves **processing nodes** in a particular order, such as:
  - **Inorder** (Left, Root, Right)
  - **Preorder** (Root, Left, Right)
  - **Postorder** (Left, Right, Root)
  - **Level-order** (Breadth-first traversal)
  
### 🧠 Keywords to look for:
- "Inorder traversal"
- "Preorder traversal"
- "Postorder traversal"
- "Level-order traversal"
- "Binary Tree DFS" (Depth First Search)
- "Binary Tree BFS" (Breadth First Search)
- "Iterative traversal"
- "Recursive traversal"

---

## 💣 2. Brute Force Approach

A brute force approach typically involves manually traversing the tree without any optimization, often using recursion in a straightforward manner.

### Example: **Inorder Traversal (Recursive)**

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);     // Visit left subtree
    cout << root->val << " "; // Process current node
    inorder(root->right);    // Visit right subtree
}
```

This is recursive, but we can also implement iterative solutions using **stacks** for depth-first search or **queues** for breadth-first search.

---

## 🛠️ 3. How Binary Tree Traversal Works + C++ Template

### 💡 Key Idea:
- **Inorder Traversal**: Useful for problems related to binary search trees (BST). It visits nodes in ascending order.
- **Preorder Traversal**: Used to process the root before its children (often for cloning trees or for use with expression trees).
- **Postorder Traversal**: Useful for problems that involve processing children before the parent node (like deleting nodes in a tree).
- **Level-order Traversal (BFS)**: Often used for problems like finding the shortest path, levels, or tree height.

---

### ✅ Template: Inorder Traversal (Recursive)

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);       // Visit left subtree
    cout << root->val << " ";  // Process node
    inorder(root->right);      // Visit right subtree
}
```

---

### ✅ Template: Preorder Traversal (Recursive)

```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";  // Process node
    preorder(root->left);      // Visit left subtree
    preorder(root->right);     // Visit right subtree
}
```

---

### ✅ Template: Postorder Traversal (Recursive)

```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);     // Visit left subtree
    postorder(root->right);    // Visit right subtree
    cout << root->val << " ";  // Process node
}
```

---

### ✅ Template: Level-order Traversal (BFS)

For level-order traversal, we typically use a **queue** to store nodes at each level.

```cpp
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";  // Process current node

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
```

---

### ✅ Template: Iterative Inorder Traversal Using Stack

```cpp
void inorderIterative(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);  // Go to leftmost node
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->val << " ";  // Process node

        current = current->right;  // Visit right subtree
    }
}
```

---

## 📚 4. Problems Related to Binary Tree Traversal

### 🟢 Easy
- [Leetcode 94](https://leetcode.com/problems/binary-tree-inorder-traversal/) – Binary Tree Inorder Traversal
- [Leetcode 144](https://leetcode.com/problems/binary-tree-preorder-traversal/) – Binary Tree Preorder Traversal
- [Leetcode 145](https://leetcode.com/problems/binary-tree-postorder-traversal/) – Binary Tree Postorder Traversal

### 🟡 Medium
- [Leetcode 102](https://leetcode.com/problems/binary-tree-level-order-traversal/) – Binary Tree Level Order Traversal
- [Leetcode 107](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) – Binary Tree Level Order Traversal II
- [Leetcode 98](https://leetcode.com/problems/validate-binary-search-tree/) – Validate Binary Search Tree (Inorder Traversal)
- [Leetcode 101](https://leetcode.com/problems/symmetric-tree/) – Symmetric Tree (Mirror Check)
- [Leetcode 145](https://leetcode.com/problems/binary-tree-postorder-traversal/) – Postorder Traversal (Iterative)

### 🔴 Hard
- [Leetcode 236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) – Lowest Common Ancestor of a Binary Tree
- [Leetcode 297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) – Serialize and Deserialize Binary Tree
- [Leetcode 105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) – Construct Binary Tree from Preorder and Inorder Traversal
