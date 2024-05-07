// Construct BST from Preorder Traversal
// Problem statement:
// You are given a preorder traversal of a binary search tree.
// Your task is to find the postorder from the preorder.

// Return the root of the BST constructed from the given preorder.
// The driver code will then use this root to print the post-order traversal.

// Link : https://www.naukri.com/code360/problems/construct-bst-from-preorder-traversal_2689307

// BRUTE FORCE APPROACH:
//  Since we know the insertion of node to BST, we will manually create a node for the given value in preorder traversal
//  and insert it to its correct position in the current BST.

// TC: O(n*n)
// SC:O(1)

// Helper function to insert a node to the BST
void insertNode(TreeNode *root, TreeNode *node)
{
    // if the value of the new node is less than the value of the current node
    if (node->val < root->val)
    {
        // if the left child of the current node is not null
        if (root->left)
        {
            insertNode(root->left, node);
        }
        else
        { // insert the new node as the left child of the current node
            root->left = node;
        }
    }
    else
    {
        // if the right child of the current node is not null
        if (root->right)
        {
            insertNode(root->right, node);
        }
        // insert the new node as the right child of the current node
        else
        {
            root->right = node;
        }
    }
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // if emtpy list
    if (preOrder.size() == 0)
        return nulltree;

    // create a root node
    TreeNode *root = new TreeNode(preOrder[0]);

    // insert the rest of the nodes
    for (int i = 1; i < preOrder.size(); i++)
    {
        // create a new node
        TreeNode *node = new TreeNode(preOrder[i]);

        // insert the node to the BST
        insertNode(root, node);
    }

    return root;
}

// Better approach:
// Since we know the inorder traversal of BST if a sorted array
//  So we can get the inorder traversal by sorted the giving preorder list
// We know that the first element of the preorder traversal is the root of the tree.
// So we will take the first element of the preorder traversal and find its index in the inorder traversal.
// The elements to the left of the root element in the inorder traversal will be the left subtree of the root and the elements to the right of the root element in the inorder traversal will be the right subtree of the root.
// We will recursively construct the left and right subtree of the root and link them to the root.
// We will keep track of the index of the elements in the inorder traversal using a hashmap.
// The key of the hashmap will be the element and the value will be the index of the element in the inorder traversal.
// Time complexity: O(N)
// Space complexity: O(N) //for the list to store inorder

// Optimal Approach

// Since we know that in a BST the elements to the left of a node should be less than the node and the elements to the right of the node ,
// so we will maintain an upper bound and check if the element can be inserted to the left of the current node.
// while backtracking, we will check if the element can be inserted to the right of the current node(upper bound will be the value of the parent node).
// TC: O(n)
// SC:O(1)

// Explanation:
//  https://youtu.be/UmJT3j26t1I?si=41v8MOHFrnzAKlzf&t=390

TreeNode *helper(vector<int> &preOrder, int &i, int ub)
{
    // Base case: If reached the end of the preorder traversal or the current element is greater than the upper bound
    if (i == preOrder.size() || preOrder[i] > ub)
        return nullptr;
    // Create a node for the current element
    TreeNode *node = new TreeNode(preOrder[i]);
    // Increment the index
    i++;
    // Check if the next element can be inserted to the left of the current node
    node->left = helper(preOrder, i, node->data);
    // While backtracking,check if the next element can be inserted to the right of the current node
    node->right = helper(preOrder, i, ub);
    // Return the created node
    return node;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Global variable to keep track of the index
    int i = 0;
    // Intially the upper bound will be INT_MAX
    return helper(preOrder, i, INT_MAX);
}