// Construct Binary Tree from Inorder and Postorder Traversal

// Problem statement:
//  You are given arrays 'inOrder' and 'postOrder', which represent 'inorder'
//  traversal and 'postorder' traversal of a 'Binary Tree' respectively.

// Construct a 'Binary Tree' represented by the given arrays and return it's head.

// Link : https://www.naukri.com/code360/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106

// Approach:
// We know that the last element of the postorder traversal is the root of the tree.
// So we will take the last element of the postorder traversal and find its index in the inorder traversal.
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

BinaryTreeNode<int> *constructTreeHelper(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int> &mp)
{
    // Base case: If the start of the postorder traversal is greater than the end of the postorder traversal or the start of the inorder traversal is greater than the end of the inorder traversal
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    // Creating a new node with the value of the root of the tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postEnd]);

    // Finding the index of the root element in the inorder traversal
    int rootIndex = mp[postorder[postEnd]];

    // Calculating the size of the left subtree
    int leftSubtreeSize = rootIndex - inStart;

    // Recursively constructing the left and right subtree of the root,along with the new start and end indices
    root->left = constructTreeHelper(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1, mp);
    root->right = constructTreeHelper(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1, mp);

    return root;
}