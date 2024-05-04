// Minimum element in BST

// Problem statement
// You are given a Binary Search Tree.
// Find the minimum value in it.

// Note:
// All the values in the given binary search tree are unique.

// Link : https://www.naukri.com/code360/problems/minimum-element-in-bst_8160462

// Approach
// We will maintain a variable minimum and initialize it with INT_MAX.
// We will keep traversing the left subtree of the current node and update the minimum value if we find a smaller value.
// We will return the minimum value at the end.

// Time complexity: O(h), where h is the height of the tree.(Generally, h is log(n) in a balanced tree)
// Space complexity: O(1)

#include <bits/stdc++.h>
int minVal(Node *root)
{
    if (!root)
        return -1;
    int mini = INT_MAX;
    Node *curr = root;
    while (curr)
    {
        // update the minimum value
        mini = curr->data;
        // move to the left subtree,in search of smaller value
        curr = curr->left;
    }
    return mini;
}