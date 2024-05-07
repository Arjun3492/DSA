// Search In BST
// Problem statement
// There is a Binary Search Tree (BST) consisting of ‘N’ nodes.
// Each node of this BST has some integer data.

// You are given the root node of this BST, and an integer ‘X’.
// Return true if there is a node in BST having data equal to ‘X’,
// otherwise return false.

// A binary search tree (BST) is a binary tree data structure that has the following properties:
// 1. The left subtree of a node contains only nodes with data less than the node’s data.
// 2. The right subtree of a node contains only nodes with data greater than the node’s data.
// 3. The left and right subtrees must also be binary search trees.
// Note:
// It is guaranteed that all nodes have distinct data.

// Link : https://www.naukri.com/code360/problems/search-in-bst_1402878

// Approach
//  Since we know that in a BST, the left subtree elements are always smaller than the root and the right subtree elements are always greater than the root.
//  So, we can start from the root and compare the root value with the given value.
//  If the root value is equal to the given value, then we have found the element and we can return true.
//  If the root value is greater than the given value, then we need to search in the left subtree.
//  If the root value is smaller than the given value, then we need to search in the right subtree.
//  If we reach the leaf node and still not found the element, then we can return false.

// Time complexity: O(h), where h is the height of the tree.(Generally, h is log(n) in a balanced tree)
// Space complexity: O(1)

// Helper function to search in BST
bool helper(BinaryTreeNode<int> *root, int x)
{
    if (!root)
        return false;

    if (root->data == x)
        return true;

    return x < root->data ? helper(root->left, x) : helper(root->right, x);
}

// Main function to search in BST
bool searchInBST(BinaryTreeNode<int> *root, int x) { return helper(root, x); }