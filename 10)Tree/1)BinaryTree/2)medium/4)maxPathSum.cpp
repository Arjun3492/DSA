// Maximum Sum Path Of A Binary Tree.
// Problem statement:
// You are given a binary tree having 'n' nodes. Each node of the tree has an integer value.

// Your task is to find the maximum possible sum of a simple path between any two
// nodes (possibly the same) of the given tree.

// A simple path is a path between any two nodes of a tree, such that no edge
// in the path is repeated twice. The sum of a simple path is defined as the
// summation of all node values in a path.

// Link : https://www.naukri.com/code360/problems/maximum-sum-path-of-a-binary-tree._1214968

// Approach
// Similar to find the max height of the tree, we will find the maximum sum path of the tree using recursion
// In each recursive call, we will find the sum path of the left and right subtree of the current node
// We will maintain a global variable to store the maximum sum path of the tree and update it if the sum path at the current node is greater than the current maximum sum path

int maxi = INT_MIN;
int recHelper(BinaryTreeNode<int> *root)
{

    // base case
    if (root == nullptr)
        return 0;

    int leftTotal = recHelper(root->left);
    int rightTotal = recHelper(root->right);

    // calculating the sum path for a given node(taking care of negative values)
    int total = root->data;
    if (leftTotal > 0)
        total += leftTotal; // adding if positive
    if (rightTotal > 0)
        total += rightTotal;                        // adding if positive
    maxi = max(maxi, total);                        // updating the maximum path sum
    return root->data + max(leftTotal, rightTotal); // recursive call to find the path sum sub tree for a node
}

// Helper function
int maxPathSum(BinaryTreeNode<int> *root)
{
    recHelper(root);
    return maxi;
}