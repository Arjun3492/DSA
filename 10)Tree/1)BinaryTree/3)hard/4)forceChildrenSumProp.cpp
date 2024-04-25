// Convert an arbitrary Binary Tree to a tree that holds Children Sum Property
//  Problem statement:
//  Given an arbitrary binary tree, convert it into a tree that holds the Children Sum Property.
//  The Children Sum Property is a property in which the sum of the values of the left child and the right child of a node is equal to the value of the node.
//  If the node is a leaf node, then the value of the node is equal to the sum of the values of its children.
// You can increment the value of any node in the tree in order to satisfy the Children Sum Property.

// Link : https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

// Approach:
//  Since we can only increment the value of nodes , we will try to increase the value of children node to suffice the children sum property while following depth order traversal.
// This will ensure that there is never a shortage of value in the children nodes to sum up to the parent node.(In a case where the parent node has a greater value than the sum of its children and we can only increment the value of nodes)
//  And while returning from the recursion, we will update the value of node to the sum of its children.

// Function to change the values of the nodes
// based on the sum of its children's values.
void changeTree(TreeNode *root)
{
    // Base case: If the current node
    // is NULL, return and do nothing.
    if (root == NULL)
    {
        return;
    }

    // Calculate the sum of the values of
    // the left and right children, if they exist.
    int child = 0;
    if (root->left)
    {
        child += root->left->val;
    }
    if (root->right)
    {
        child += root->right->val;
    }

    // Compare the sum of children with
    // the current node's value and update
    if (child >= root->val)
    {
        root->val = child; // Update the current node's value
    }
    else
    {
        // If the sum is smaller, update the
        // child with the current node's value.
        // This will ensure there is no shortage of value in the children nodes.
        if (root->left)
        {
            root->left->val = root->val;
        }
        else if (root->right)
        {
            root->right->val = root->val;
        }
    }

    // Recursively call the function
    // on the left and right children.
    changeTree(root->left);
    changeTree(root->right);

    // While backtracking, update the value of the current node to the sum of its children.
    int tot = 0;
    if (root->left)
    {
        tot += root->left->val;
    }
    if (root->right)
    {
        tot += root->right->val;
    }

    if (root->left or root->right)
    {
        root->val = tot;
    }
}
