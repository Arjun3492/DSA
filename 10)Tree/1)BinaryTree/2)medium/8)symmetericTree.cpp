// Symmetrical Binary Tree
// Problem statement
// You have been given a Binary Tree having 'n' nodes.
// A Symmetric tree is a binary tree whose mirror image is the same as the original tree.
// Find out whether the given tree is symmetric or not.

// Link : https://www.naukri.com/code360/problems/symmetric-tree_981177

// Approach:
// We will use the recursive approach to solve this problem.
// We will check if the left subtree of the root is the mirror image of the right subtree of the root.
// To check if the left subtree is the mirror image of the right subtree, we will check if the left child of the left subtree is the mirror image of the right child of the right subtree and vice versa.
// We will use a helper function to check if the left subtree is the mirror image of the right subtree.
// The helper function will take two nodes as input and return true if the nodes are the mirror image of each other.
// The helper function will return false if the nodes are not the mirror image of each other.

bool helper(TreeNode<int> *left, TreeNode<int> *right)
{

    // base case
    if (!left || !right)
    {
        return left == right;
    }

    // check if the data of the nodes is equal and the left child of the left subtree is the mirror image of the right child of the right subtree and vice versa
    return (left->data == right->data) &&
           helper(left->left, right->right) &&
           helper(left->right, right->left);
}

bool isSymmetric(TreeNode<int> *root)
{
    if (root == nullptr)
        return true;
    return helper(root->left, root->right);
}