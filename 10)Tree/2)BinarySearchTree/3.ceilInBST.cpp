// Ceil from BST
// Problem statement
// Ninja is given a binary search tree and an integer. Now he is given a particular key in the tree and returns its ceil value. Can you help Ninja solve the problem?

// Note:
// Ceil of an integer is the closest integer greater than or equal to a given number.

// Link : https://www.naukri.com/code360/problems/ceil-from-bst_920464

// Approach
// We will maintain a variable ceil and initialize it with -1.
// While traversing the tree, if we found a value greater than or equal to the given value, we will update the ceil value and move to the left subtree to find a closer value.
// else we will move to the right subtree to find a greater value.

// Time complexity: O(h), where h is the height of the tree.(Generally, h is log(n) in a balanced tree)
// Space complexity: O(1)

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans = -1;
    BinaryTreeNode<int> *curr = node;
    while (curr)
    {
        // if we found the exact value, return the value
        if (curr->data == x)
            return x;

        // if the current value is greater than the given value, update the ceil value and move to the left subtree
        if (curr->data > x)
        {
            ans = curr->data;
            // move to the left subtree,in search of closer value
            curr = curr->left;
        }
        else
        {
            // move to the right subtree,in search of greater value
            curr = curr->right;
        }
    }
    return ans;
}