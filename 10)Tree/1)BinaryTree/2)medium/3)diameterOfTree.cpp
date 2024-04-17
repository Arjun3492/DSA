// Diameter Of Binary Tree
// You are given a Binary Tree.
// Return the length of the diameter of the tree.

// Note :
// The diameter of a binary tree is the length of the longest path between any two end nodes in a tree.
// The number of edges between two nodes represents the length of the path between them.

// Link : https://www.naukri.com/code360/problems/diameter-of-binary-tree_920552

// Approach
// We will modify the recursive approach of finding the height of the tree to find the diameter of the tree
// In each recursive call, we will find the height of the left and right subtree of the current node
// We will calculate the diameter of the tree at the current node as the sum of the height of the left and right subtree
// We will update the diameter of the tree if the diameter at the current node is greater than the current maximum diameter

int maxi = 0; // global variable to store the maximum diameter of the tree
int recHelper(TreeNode<int> *root)
{

    // base case
    if (root == nullptr)
        return 0;

    int leftSubTreeHeight = recHelper(root->left);
    int rightSubTreeHeight = recHelper(root->right);
    // calculate the diameter of the tree at the current node and update the maximum diameter if required
    maxi = max(maxi, leftSubTreeHeight + rightSubTreeHeight);
    return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    recHelper(root);
    return maxi;
}