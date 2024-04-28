// //Problem statement
// You have been given the preorder and inorder traversal of a binary tree.
// Your task is to construct a binary tree using the given inorder and preorder traversals

// Link : https://www.naukri.com/code360/problems/construct-binary-tree-from-inorder-and-preorder-traversal_920539

// Approach:
// We know that the first element of the preorder traversal is the root of the tree.
// So we will take the first element of the preorder traversal and find its index in the inorder traversal.
// The elements to the left of the root element in the inorder traversal will be the left subtree of the root and the elements to the right of the root element in the inorder traversal will be the right subtree of the root.
// We will recursively construct the left and right subtree of the root and link them to the root.
// We will keep track of the index of the elements in the inorder traversal using a hashmap.
// The key of the hashmap will be the element and the value will be the index of the element in the inorder traversal.
// Time complexity: O(N)
// Space complexity: O(N)

// Helper function to map the elements of the inorder traversal to their index
void mapInorderIndex(vector<int> &inorder, unordered_map<int, int> &mp)
{
    for (int i = 0; i <= inorder.size() - 1; i++)
    {
        mp[inorder[i]] = i;
    }
}

BinaryTreeNode<int> *constructTreeHelper(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    // Base case: If the start of the preorder traversal is greater than the end of the preorder traversal or the start of the inorder traversal is greater than the end of the inorder traversal
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Creating a new node with the value of the root of the tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preStart]);

    // Finding the index of the root element in the inorder traversal
    int rootIndex = mp[preorder[preStart]];

    // Calculating the size of the left subtree
    int leftSubtreeSize = rootIndex - inStart;

    // Recursively constructing the left and right subtree of the root,along with the new start and end indices
    root->left = constructTreeHelper(preorder, inorder, preStart + 1, preStart + leftSubtreeSize, inStart, rootIndex - 1, mp);
    root->right = constructTreeHelper(preorder, inorder, preStart + leftSubtreeSize + 1, preEnd, rootIndex + 1, inEnd, mp);

    return root;
}