// Delete Node In BST
// Problem statement
// You have been given a Binary Search Tree of integers with ‘N’ nodes.
// You are also given data of a node of this tree. Your task is to delete the given node from the BST.

// Link : https://www.naukri.com/code360/problems/delete-node-in-bst_920381

// Approach :
// To delete a given node from BST we will attach the its left child subtree to the leftmost leaf of right child subtree
// now this right child subtree will be appended to the parent of the node to be deleted

// Helper function to find rightmost child of left subtree
BinaryTreeNode<int> *findRightMost(BinaryTreeNode<int> *node)
{
    if (node->right == nullptr)
        return node;
    return findRightMost(node->right);
}

// Helper Function to delete a node from the BST
BinaryTreeNode<int> *delNode(BinaryTreeNode<int> *root)
{

    // if the target node has only one child ,return the pther child directly
    if (root->right == nullptr)
        return root->left;
    if (root->left == nullptr)
        return root->right;

    // We will attach the rightSubTree to the right of the rightmost leaf node of
    // left sub tree (this will ensure the property of BST)
    // then return the left subtree
    BinaryTreeNode<int> *rightSubTree = root->right;
    BinaryTreeNode<int> *rightMostOfLeftSubtree = findRightMost(root->left);
    rightMostOfLeftSubtree->right = rightSubTree;
    return root->left;
}

// Helper Function to find the parent of a node with a given key
BinaryTreeNode<int> *findNodeParent(BinaryTreeNode<int> *root, int key)
{
    BinaryTreeNode<int> *parent = nullptr;
    BinaryTreeNode<int> *current = root;

    // Traverse the tree to find the node with the given key
    while (current != nullptr && current->data != key)
    {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return parent;
}

// Function to delete a node from the BST
BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int key)
{
    // If the tree is empty, return null
    if (root == nullptr)
        return nullptr;

    // If the node to be deleted is the root node, attach the left subtree to the rightmost leaf of the right subtree and return the left subtree
    if (root->data == key)
    {
        root = delNode(root);
        return root;
    }

    // Find the parent of the node to be deleted
    BinaryTreeNode<int> *parent = findNodeParent(root, key);

    // If the node to be deleted is the left child of its parent
    if (parent->left != nullptr && parent->left->data == key)
    {
        // attach the right subtree to the rightmost leaf of the left subtree and return the left subtree
        // this returned subtree will be attached to the parent of the node to be deleted
        parent->left = delNode(parent->left);
    }
    // If the node to be deleted is the right child of its parent
    else if (parent->right != nullptr && parent->right->data == key)
    {
        // attach the right subtree to the rightmost leaf of the left subtree and return the left subtree
        // this returned subtree will be attached to the parent of the node to be deleted
        parent->right = delNode(parent->right);
    }
    return root;
}
