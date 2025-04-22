# Breadth-First Search (BFS) 

## 🔍 1. When Should Breadth-First Search (BFS) Be Used?

### ✅ Use BFS when:
- You need to explore a graph or tree **level by level**.
- You are solving problems that require **finding the shortest path** or **minimum number of steps** in an unweighted graph (or grid).
- You need to **explore all neighbors of a node before visiting deeper nodes**.
- The problem asks for things like **levels** or **distances from the start node**.

### 🧠 Keywords to look for:
- "Shortest path"
- "Level order"
- "Minimum distance"
- "Graph search"
- "Level traversal"
- "Connected components"
- "Breadth-first traversal"
- "Find all nodes at distance k"
- "Breadth-first search"

---

## 💣 2. Brute Force Approach

The brute force approach often involves **recursively visiting** nodes or iterating over each node without considering the level structure, leading to inefficient solutions for pathfinding or distance calculations.

For example, to find the shortest path from a source node to a target node in an unweighted graph, a brute-force approach might involve trying all possible paths without keeping track of the minimum path length or already visited nodes, which is highly inefficient.

---

## 🛠️ 3. How BFS Works + C++ Template

### 💡 Key Idea:
- **BFS explores nodes level by level**. It starts from a source node and explores all neighbors at the current level before moving on to the next level.
- It uses a **queue** to manage the order of nodes to be processed.
- BFS is typically used to find the **shortest path** in an unweighted graph or to explore all nodes in a level-wise manner (like in a tree).

### BFS Steps:
1. **Start at a node** (typically the source or root).
2. **Enqueue** the starting node.
3. **While the queue is not empty**, dequeue a node, process it, and enqueue all its unvisited neighbors.
4. Repeat until all reachable nodes are processed.

---

### ✅ Template: BFS for Tree Traversal (Level-order)

In a binary tree, BFS (Level-order traversal) processes nodes level by level. This is often done using a queue.

```cpp
void bfs(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";  // Process node
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

### ✅ Template: BFS for Graph Traversal (Shortest Path)

BFS is commonly used in unweighted graphs to find the shortest path between a source and a target node. We can track the distance from the source node to every other node.

```cpp
void bfsShortestPath(GraphNode* start) {
    if (!start) return;
    
    queue<GraphNode*> q;
    unordered_map<GraphNode*, int> distance;
    
    q.push(start);
    distance[start] = 0;  // Distance to source is 0
    
    while (!q.empty()) {
        GraphNode* node = q.front();
        q.pop();
        
        // Process node
        cout << "Node " << node->val << " has distance " << distance[node] << endl;
        
        for (auto neighbor : node->neighbors) {
            if (distance.find(neighbor) == distance.end()) {  // If neighbor hasn't been visited
                q.push(neighbor);
                distance[neighbor] = distance[node] + 1;  // Distance is current node's distance + 1
            }
        }
    }
}
```

---

### ✅ Template: BFS for Graph (Level Order)

BFS can be used to process nodes in a graph **level by level** (similar to trees). Here’s a BFS implementation to find nodes at each level.

```cpp
void bfsLevelOrder(GraphNode* start) {
    if (!start) return;
    
    queue<GraphNode*> q;
    unordered_set<GraphNode*> visited;
    
    q.push(start);
    visited.insert(start);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            GraphNode* node = q.front();
            q.pop();
            
            cout << node->val << " ";  // Process node
            
            for (auto neighbor : node->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        cout << endl;  // Move to next level
    }
}
```

---

## 📚 4. Problems Related to Breadth-First Search (BFS)

### 🟢 Easy
- [Leetcode 102](https://leetcode.com/problems/binary-tree-level-order-traversal/) – Binary Tree Level Order Traversal (BFS for tree levels)
- [Leetcode 104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) – Maximum Depth of Binary Tree (BFS for level calculation)
- [Leetcode 111](https://leetcode.com/problems/minimum-depth-of-binary-tree/) – Minimum Depth of Binary Tree (BFS for level calculation)

### 🟡 Medium
- [Leetcode 200](https://leetcode.com/problems/number-of-islands/) – Number of Islands (BFS for finding connected components in a grid)
- [Leetcode 547](https://leetcode.com/problems/friend-circles/) – Friend Circles (BFS for connected components)
- [Leetcode 127](https://leetcode.com/problems/word-ladder/) – Word Ladder (BFS for shortest transformation sequence)

### 🔴 Hard
- [Leetcode 529](https://leetcode.com/problems/minesweeper/) – Minesweeper (BFS for exploring all cells in a grid)
- [Leetcode 316](https://leetcode.com/problems/remove-duplicate-letters/) – Remove Duplicate Letters (BFS for lexicographically smallest string)
- [Leetcode 279](https://leetcode.com/problems/perfect-squares/) – Perfect Squares (BFS for finding the least number of perfect squares)

---

### Key Takeaways:
- **BFS** explores nodes level by level and is used in problems like **shortest path**, **finding connected components**, **level order traversal** in trees, and **minimum distances**.
- BFS typically uses a **queue** for efficient level-wise exploration.
- It's especially effective in **unweighted graphs** to find the **shortest path** from a source node.

Would you like to dive deeper into any of the BFS problems or explore more complex use cases?