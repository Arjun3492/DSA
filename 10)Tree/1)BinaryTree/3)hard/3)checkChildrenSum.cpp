// Check Children Sum Property
//  Problem statement:
//  Return true if all non-leaf nodes in a given binary tree have a value that is equal
//  to the sum of their child nodes, otherwise return false.

// Link : https://www.naukri.com/code360/problems/children-sum-property_8357239

// Approach:
// We will follow a depth order traversal .
// Base case: If the node is null or if the node is a leaf node, we will return true.
// For each node, we will check if the sum of the values of its children is equal to the value of the node.
// If the condition is satisfied, we will continue checking for the left and right subtrees.
// If the condition is not satisfied, we will return false.
// Time complexity: O(N), where N is the number of nodes in the tree.
// Space complexity: O(N) [Stack space] .

// Recursive function to check if the children sum property is satisfied
bool helper(Node *root)
{
    // Empty subtree is considered valid
    if (!root)
        return true;
    // Leaf node is considered valid
    if (!root->left && !root->right)
        return true;

    // Checking for children sum property
    int sumOfChildren = 0;
    if (root->left)
        sumOfChildren += root->left->data;
    if (root->right)
        sumOfChildren += root->right->data;

    if (root->data == sumOfChildren)
    // Continue checking for the left and right subtrees
    {
        return helper(root->left) && helper(root->right);
    }
    // If the condition is not met, return false
    else
    {
        return false;
    }
}

// Driver code
bool isParentSum(Node *root) { return helper(root); }
