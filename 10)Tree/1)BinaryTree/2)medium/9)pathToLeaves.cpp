// All Root to Leaf Paths In Binary Tree.
// Problem statement
// You are given an arbitrary binary tree consisting of 'N' nodes numbered from 1 to 'N'.
// Your task is to print all the root to leaf paths of the binary tree.

// A leaf of a binary tree is the node which does not have a left child and a right child.

// Link : https://www.naukri.com/code360/problems/all-root-to-leaf-paths-in-binary-tree._983599

// Approach :
//  We will recursively traverse the tree in a preorder fashion and keep track of the path from root to leaf.
//  At each recursive call, we will add the current node to the path and if the current node is a leaf node, we will add the path to the ans.
// Time complexity: O(N), where N is the number of nodes in the tree.
// Space complexity: O(N)[Stack space] .
// Helper function to recursively traverse the tree and keep track of the path
void helper(BinaryTreeNode<int> *node, vector<string> &ans, string path)
{
    // Base case: if null node
    if (!node)
    {
        return;
    }

    // Concatenating node data to the path
    path += to_string(node->data);

    // Checking if it's a leaf node
    if (!node->left && !node->right)
    {
        ans.push_back(path);
        return;
    }

    // Recursively call for left and right subtrees
    helper(node->left, ans, path + " ");
    helper(node->right, ans, path + " ");
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *node)
{
    vector<string> ans;

    // Edge case: if null tree
    if (!node)
        return ans;

    string path;
    helper(node, ans, path);
    return ans;
}
