// LCA in BST
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of
// two given nodes in the BST.

// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Brute Force Approach
// Same as done for LCA in normal BT
// The intuition is that we will follow a depth wise traversal and look for the nodes ‘X’ and ‘Y’.
// And we will return the X or Y node if we find it else we will return NULL while backtracking.
// If during backtracking we find both the nodes ‘X’ and ‘Y’ in the left and right subtree of the current node, then the current node is the LCA.
// Time complexity: O(N), where N is the number of nodes in the tree.
// Space complexity: O(N)[Stack space] .

// Optimal Force Approach
//  On observation , we can notice that for a given value x and y , the LCA is the first node where
//  the nodes x and y fall in opposite direction.
//  So we will leverage this , to find the LCA in a BST
// Time complexity: O(N), where N is the number of nodes in the tree.
// Space complexity: O(1) .

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // if nulltree directly return root
    if (!root)
        return nullptr;

    TreeNode *curr = root;
    int pV = p->val, qV = q->val;
    // BST Traversal
    while (curr)
    {
        int v = curr->val;
        // if both are smaller than the current node ,move to left subtree
        if (pV < v && qV < v)
        {
            curr = curr->left;
        }
        // if both are larger than the current node ,move to left subtree

        else if (pV > v && qV > v)
        {
            curr = curr->right;
        }
        // Else if both occur in opposite subtrees
        else
        {
            return curr;
        }
    }
    return nullptr;
}
