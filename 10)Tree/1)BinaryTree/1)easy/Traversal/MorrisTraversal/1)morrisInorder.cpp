// Morris Inorder Traversal
//  Problem Statement
//  Given the root of a binary tree, return the inorder traversal of its nodes' values using the Morris Traversal technique.

// Link : https://www.naukri.com/code360/problems/inorder-traversal_3839605

// Approach :
//  The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.
//  We will point the right pointer of the rightmost node of the left subtree to the current subtree root to make the tree threaded.
//  Now we will follow the three cases:
// 1. If the current node does not have a left child, we will print the current node and move to the right child.
// 2. If the current node has a left child
// 2.1 We will find the rightmost node of the left subtree and point its right pointer to the current node.
// 2.2 If the right pointer of the rightmost node already points to the current node, we will revert the changes,print the curr subtree root and move to the right node.

// Time Complexity: O(n)
// Space Complexity: O(1) //Speciality of Morris Traversal

void morrisInorderTraversal(TreeNode<int> *node, vector<int> &ans)
{
    TreeNode<int> *curr = node;
    // While current is not null
    while (curr != nullptr)
    {
        // Case 1: If the current node does not have a left child
        if (curr->left == nullptr)
        { // Print the current node and move to the right child
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // Case 2: If the current node has a left child
            TreeNode<int> *prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right;
            }

            // Case 2.1: If the right pointer of the rightmost node already points to the current node
            if (prev->right == nullptr)
            {
                // Point the right pointer of the rightmost node to the current node(Threading the tree)
                prev->right = curr;

                curr = curr->left;
            }
            // Case 2.2: If the right pointer of the rightmost node already points to the current node
            else
            { // Revert the changes
                prev->right = nullptr;
                // Print the current node and move to the right child
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}