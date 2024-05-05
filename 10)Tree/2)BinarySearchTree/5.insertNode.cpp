// Insert Into A Binary Search Tree
// Problem statement:
// You have been given a root node of the binary search tree and a positive integer value.
// You need to perform an insertion operation i.e. inserting a new node with the given value
// in the given binary search tree such that the resultant tree is also a binary search tree.

// If there can be more than one possible tree, then you can return any.

// Link : https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913

// Approach :
// We will follow the BST traversal as per the value of the node to be inserted.
//  If the value of the node to be inserted is less than the value of the current node, we will move to the left child of the current node else we will move to the right child of the current node.
//  We will keep on moving to the left or right child of the current node until we reach a node whose left or right child is NULL.
//  Once we reach such a node, we will insert the new node with the given value as the left or right child of the current node based on the value of the new node.
//  We will return the root node of the binary search tree after inserting the new node.

TreeNode<int> *insertionInBST(TreeNode<int> *root, int val)
{
    // root is null
    if (!root)
        return new TreeNode<int>(val);
    // curr is the current node
    TreeNode<int> *curr = root;

    // traverse the tree to find the correct position to insert the new node
    while (curr)
    {
        // if the value of the new node is less than the value of the current node
        if (val < curr->val)
        {
            // if the left child of the current node is not null
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            { // insert the new node as the left child of the current node,break
                curr->left = new TreeNode<int>(val);
                break;
            }
        }
        else
        {
            // if the right child of the current node is not null
            if (curr->right)
            {
                curr = curr->right;
            }
            // insert the new node as the right child of the current node,break
            else
            {
                curr->right = new TreeNode<int>(val);
            }
        }
    }

    // return the root node of the binary search tree
    return root;
}