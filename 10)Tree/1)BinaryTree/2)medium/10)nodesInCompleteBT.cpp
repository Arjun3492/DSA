// Nodes In Complete Binary Tree
// Problem statement
// You are given the root of a complete binary tree,
// you need to calculate the number of nodes in the given complete binary tree.

// A complete binary tree is a tree in which all the levels
// are completely filled except the last level. Nodes in the last level are as left as possible.

// Link : https://www.naukri.com/code360/problems/nodes-in-complete-binary-tree_1281151

// Bruteforce approach:
// We will perform a level order traversal/depth wise traversal and count the number of nodes in the tree.
// Time complexity: O(N)
// Space complexity: O(N)

int helper(BinaryTreeNode<int> *node)
{
    if (!node)
        return 0;

    int lH = getLeftHeight(node);
    int rH = getRightHeight(node);

    // 1 for current node + solve for left subtree + solve for right subtree
    return 1 + helper(node->left) + helper(node->right);
}

int countNodes(BinaryTreeNode<int> *root) { return helper(root); }

// Optimized approach:
// We can solve this problem in <O(N) time complexity.
// For each subtree, we will calculate its left height and right height.
// If the left height is equal to the right height, then the subtree is a perfect binary tree.
// In this case, the number of nodes in the subtree will be 2^h - 1. (where h is the height of the subtree,1-based indexing)
// Else we will add one for the given root of subtree and recursively calculate the number of nodes in the left and right subtree.

// Time complexity: O(logN * logN), logN for calculating the height of the tree and logN if in the worst case for each node we need to calculate the height of the left and right subtree.(that is left height != right height)
// Space complexity: O(logN) for the recursive stack.

// Helper functions to calculate the left height  of the tree. (Complexity: O(logN))
int getLeftHeight(BinaryTreeNode<int> *node)
{
    int height = 0;
    while (node->left)
    {
        node = node->left;
        height++;
    }
    return height; // returns 0 based height
}
// Helper functions to calculate the right height  of the tree. (Complexity: O(logN))
int getRightHeight(BinaryTreeNode<int> *node)
{
    int height = 0;
    while (node->right)
    {
        node = node->right;
        height++;
    }
    return height; // returns 0 based height
}

int helper(BinaryTreeNode<int> *node)
{
    if (!node)
        return 0;

    // if at any subtree, left height == right height, then the subtree is a perfect binary tree
    // in this case, the number of nodes in the subtree will be 2^h - 1, so we can directly return the number of nodes in the subtree,
    //  without traversing entire whole subtree.
    int lH = getLeftHeight(node);
    int rH = getRightHeight(node);

    if (lH == rH)
        return (1 << lH + 1) - 1; // 2^(h+1) - 1(1 based indexing)

    return 1 + helper(node->left) + helper(node->right);
}

int countNodes(BinaryTreeNode<int> *root) { return helper(root); }