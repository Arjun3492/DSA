// Height of Binary Tree
// Problem statement
// The height of a tree is equal to the number of nodes on the longest path from the root to a leaf.
// You are given an arbitrary binary tree consisting of 'n' nodes where each node is associated with a certain value.
// Find out the height of the tree.

// Link : https://www.naukri.com/code360/problems/height-of-binary-tree_4609628

// Helper function
int heightOfBinaryTree(TreeNode<int> *root) { return helper(root); }

// Recursive Approach
//  We form a relation given below
//  height of tree = 1 + max(height of left subtree, height of right subtree)
//  with the base case of height of tree = 0 if root is NULL
//  We can use this relation to solve the problem recursively

int recHelper(TreeNode<int> *root)
{

    // base case
    if (root == nullptr)
        return 0;

    int leftSubTreeHeight = recHelper(root->left);         // height of left subtree
    int rightSubTreeHeight = recHelper(root->right);       // height of right subtree
    return 1 + max(leftSubTreeHeight, rightSubTreeHeight); // height of tree
}

// Iterative Approach
// We can solve the problem iteratively using level order traversal
// At each level we increment the height of tree by 1 and pop out the previous level nodes from the queue before pushing the next level nodes

int iterativeHelper(TreeNode<int> *root)
{
    int ans = 0;
    queue<TreeNode<int> *> q; // queue to store the nodes of the tree for level order traversal
    q.push(root);             // push the root node

    while (!q.empty()) // while queue is not empty
    {
        ans++;                    // increment the height of tree
        int levelSize = q.size(); // number of nodes at current level
        while (levelSize > 0)     // remove the nodes present in the queue before pushing the next level nodes
        {
            TreeNode<int> *node = q.front();
            q.pop();

            // for each of the node at the current level, push its left and right child to the queue
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            levelSize--; // decrement the number of nodes at the current level
        }
    }
    return ans;
}
