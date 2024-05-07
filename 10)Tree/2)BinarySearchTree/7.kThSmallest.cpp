// Kth smallest node in BST
// Problem statement
// You have been given a Binary Search Tree of integers.
// You are supposed to return the k-th (1-indexed) smallest element in the tree.

// Link : https://www.naukri.com/code360/problems/kth-smallest-node-in-bst_920441

// Brute force approach
// Traverse the entire tree and store its element in a list/vector
//  Sort the list/vector (O(nlogn)),return the kth element from the list
// TC : O(n+nlogn)
// SC: O(n) storing the list

// Better approach
// Since we know that the inorder traversal of a BST is a sorted array, we can perform an inorder traversal and return the kth element from the traversal
// TC : O(n)
// SC: O(n) storing the list

// Optimal Approach
// We can perform an inorder traversal and keep track of the count of nodes visited so far
// If the count of nodes visited so far is equal to k, we return the value of the current node
// TC : O(n)
// SC: O(1)

void helper(TreeNode<int> *node, int k, int &ans, int &cnt)
{
    if (!node)
        return;

    // Traverse the left subtree
    helper(node->left, k, ans, cnt);

    // Increment the count
    cnt++;

    // If the current node is the kth smallest element, return its data
    if (cnt == k)
    {
        ans = node->data;
        return;
    }

    // Traverse the right subtree
    return helper(node->right, k, ans, cnt);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1;
    int cnt = 0;
    helper(root, k, ans, cnt);
    return ans;
}