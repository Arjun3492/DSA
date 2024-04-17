// Is Height Balanced Binary Tree
// Problem statement
// You are given the root node of a binary tree.
// Return 'true' if it is a height balanced binary tree.

// Note:
// A binary tree is said to be height balanced if the difference between
// the heights of its left and right subtree is not more than 1 for all nodes.

// Link : https://www.naukri.com/code360/problems/is-height-balanced-binary-tree_975497

// Approach
//  We will slightly modify the recursive approach of finding the height of the tree
//  In each recursive call, we will check if the left and right subtree of the current node is balanced or not
//  If either of the left or right subtree is not balanced, we will return -1
//  We will return -1 if the tree is not balanced instead of returning the height of the tree

// this function returns the height of a balanced BT and -1 if unbalanced
int recHelper(TreeNode<int> *root)
{

    // base case
    if (root == nullptr)
        return 0;

    int lh = recHelper(root->left);
    int rh = recHelper(root->right);

    // if at any point we got -1 while backtracking directly return -1
    if (lh == -1 || rh == -1)
        return -1;

    // return a -1 if condition failed at any node
    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}
bool isBalancedBT(TreeNode<int> *root)
{
    return !(recHelper(root) == -1); // not a balanced tree if -1 was returned
}
