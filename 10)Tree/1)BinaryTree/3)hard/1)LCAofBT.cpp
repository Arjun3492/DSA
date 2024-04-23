// LCA Of Binary Tree
// Problem statement:
// You have been given a Binary Tree of distinct integers and two nodes ‘X’ and ‘Y’.
// You are supposed to return the LCA (Lowest Common Ancestor) of ‘X’ and ‘Y’.

// The LCA of ‘X’ and ‘Y’ in the binary tree is the shared ancestor of ‘X’ and ‘Y’
// that is located farthest from the root.

// Note :
// You may assume that given ‘X’ and ‘Y’ definitely exist in the given binary tree

// Link : https://www.naukri.com/code360/problems/lca-of-binary-tree_920541

// Approach :
// The intuition is that we will follow a depth wise traversal and look for the nodes ‘X’ and ‘Y’.
// And we will return the X or Y node if we find it else we will return NULL while backtracking.
// If during backtracking we find both the nodes ‘X’ and ‘Y’ in the left and right subtree of the current node, then the current node is the LCA.

// Time complexity: O(N), where N is the number of nodes in the tree.
// Space complexity: O(N)[Stack space] .

// Helper function to find the LCA of the nodes
TreeNode<int> *helper(TreeNode<int> *node, int x, int y)
{

    // base case:if node is null for one of x and y
    if (node == nullptr || node->data == x || node->data == y)
    {
        return node; // return the node
    }
    TreeNode<int> *left = helper(node->left, x, y);   // getting the backtracked value from left subtree
    TreeNode<int> *right = helper(node->right, x, y); // getting the backtracked value from right subtree

    // If both the backtracked left and right values are not NULL, then the current node is the LCA(As it is given in the question that both the nodes exist in the tree)
    if (left && right) // if(left->data==x && right->data==y || left->data==y && right->data==x) return node (this condition is not needed as it is given that both the nodes exist in the tree)
        return node;
    // elif left is null return ,return right(even if null)
    else if (!left)
        return right;
    // else return left(even if null)
    else
        return left;
}

// Function to find the LCA of the nodes
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    return helper(root, x, y)->data;
}