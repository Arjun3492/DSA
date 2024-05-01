// Flatten Binary Tree to Linked List
// Problem statement
// You are given a binary tree consisting of 'n' nodes.

// Convert the given binary tree into a linked list where the linked list
// nodes follow the same order as the pre-order traversal of the given binary tree.

// Use the right pointer of the binary tree as the “next” pointer for the linked
// list and set the left pointer to NULL.

// Use these nodes only. Do not create extra nodes.

// Link : https://www.naukri.com/code360/problems/flatten-binary-tree-to-linked-list_1112615

// Approach :
// The idea is to follow the Morris Preorder traversal technique to flatten the binary tree.
// We will do the following steps:
// 1. If the curr node does have a left child, we will find the rightmost node of the left subtree and point its right pointer to the right child of the current node.
// 2. We will point the right child of the current node to the left child and set the left child to NULL.
// 3. Finally,Move to the right child of the current node.

// Video explanation : https://youtu.be/sWf7k1x9XR4?si=AkZbn6Icm6nnugMU&t=1001

// Time Complexity: O(n)
// Space Complexity: O(1)

void flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    // While current is not null
    while (curr)
    {

        // If the current node does  have a left child
        if (curr->left)
        {
            // Moving to the rightmost node of the left subtree
            TreeNode<int> *prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }

            // Point the right pointer of the rightmost node to the right child of the current node
            prev->right = curr->right;
            // Point the right child of the current node to the left child
            curr->right = curr->left;
            // Set the left child to NULL
            curr->left = nullptr;
        }

        // Finally, Move to the right child
        curr = curr->right;
    }
}
