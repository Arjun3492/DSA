// Floor from BST
// Problem statement
// Given a binary search tree and an integer.
// Find the floor value of a key in a binary search tree .

// (If k lies in BST then is floor equal to k,else floor is equal to
// previous greater value) Note: k would never be less than the minimum element of tree.

// Link : https://www.naukri.com/code360/problems/floor-from-bst_625868

// Approach
// We will maintain a variable floor and initialize it with -1.
// While traversing the tree, if we found a value less than or equal to the given value, we will update the floor value and move to the right subtree to find a closer value.
// else we will move to the left subtree to find a smaller value.

// Time complexity: O(h), where h is the height of the tree.(Generally, h is log(n) in a balanced tree)
// Space complexity: O(1)

int findFloor(BinaryTreeNode<int> *node, int x)
{
    int ans = -1;
    BinaryTreeNode<int> *curr = node;
    while (curr)
    {
        // if we found the exact value, return the value
        if (curr->data == x)
            return x;

        // if the current value is less than the given value, update the floor value and move to the right subtree
        if (curr->data < x)
        {
            ans = curr->data;
            // move to the right subtree,in search of closer value
            curr = curr->right;
        }
        else
        {
            // move to the left subtree,in search of smaller value
            curr = curr->left;
        }
    }
    return ans;
}