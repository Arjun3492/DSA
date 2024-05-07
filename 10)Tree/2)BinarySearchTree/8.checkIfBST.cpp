// Check BST
// Problem statement
// Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree).
// If yes, return true, return false otherwise.

// Link : https://www.naukri.com/code360/problems/check-bst_5975

// Approach:
// Since we know that in a BST for the given node with value x
// Its left child should have a value less than x
// Its right child should have a value greater than x
// So we will check for all nodes whether it less in the required range or not
//  For this purpose we will use two variables low and high

bool helper(BinaryTreeNode<int> *node, int low, int high)
{
    // if reached a null node,return true
    if (!node)
        return true;

    // if the given node doesn't fall in the given range (low,high) return false;
    if (!(node->data > low && node->data < high))
        return false;

    // return the conjuction of leftsubtree and right subtree child
    return helper(node->left, low, node->data) &&
           helper(node->right, node->data, high);
}
