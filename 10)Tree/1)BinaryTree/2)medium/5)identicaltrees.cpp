// Check Identical Trees
// Problem statement
// You are given two binary trees with 'n' and 'm' nodes respectively.
// You need to return true if the two trees are identical. Otherwise, return false.

// Link : https://www.naukri.com/code360/problems/check-identical-trees_799364

// Approach
// We will traverse both the trees in a recursive manner and check if the data of the current node of both the trees is equal or not.
// If the data of the current node is not equal, we will return false.

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // base case:if we have reached the end of either of the trees
    if (root1 == nullptr || root2 == nullptr)
    {
        return root1 == root2; // if both are null, return true else false
    }

    // equal data and both left and right subtrees are identical , return true
    return (root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}
