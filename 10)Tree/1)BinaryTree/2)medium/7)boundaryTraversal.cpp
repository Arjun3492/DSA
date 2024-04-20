// Boundary Traversal of Binary Tree
// Problem statement:
// You are given a binary tree having 'n' nodes.
// The boundary nodes of a binary tree include the nodes from the left and right
// boundaries and the leaf nodes, each node considered once.

// Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction
// starting from the root node.

// Link : https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725

// Approach :
//  We will divide the boundary traversal into three parts:
// Left Boundary, Leaf Nodes, Right Boundary
// For the left boundary, we will traverse the left subtree in a top-down manner and add the nodes.
// For the leaf nodes, we will traverse the tree in an inorder manner and add the leaf nodes.
// For the right boundary, we will traverse the right subtree in a top-down manner and add the nodes in reverse.
// We will add the root node to the left boundary and leaf nodes and then add the right boundary nodes in reverse.

// checks weather a node is a leaf node
bool isLeaf(TreeNode<int> *root)
{
    return root->left == nullptr && root->right == nullptr;
}

// inserts the element of left boundary into the ans list
void addLeftBoundary(TreeNode<int> *root, vector<int> &ans)
{

    // edge case: if leaft child of root node does not exist
    if (root->left == nullptr)
        return;

    // starting from the first left child of root node
    TreeNode<int> *curr = root->left;

    // traversing the left boundary until a leaf node isn't encountered
    while (!isLeaf(curr))
    {

        // adding the node to ans list
        ans.push_back(curr->data);

        // first check for left child then for right
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

// inserts the element of right boundary into the ans list
void addRightBoundary(TreeNode<int> *root, vector<int> &ans)
{

    // edge case: if right child of root node does not exist

    if (root->right == nullptr)
        return;

    // starting from the first right child of root node

    TreeNode<int> *curr = root->right;

    // temp list to store the right boundary nodes so that it can be added to ans
    // list in reverse order
    //  as anti-clockwise traversal is needed
    vector<int> temp;

    // traversing the right boundary until a leaf node isn't encountered
    while (!isLeaf(curr))
    {
        // adding the node to temp list

        temp.push_back(curr->data);

        // first check for right child then for left

        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    // inserting temp into ans list in reverse order
    ans.insert(ans.end(), temp.rbegin(), temp.rend());
}

// inserts the leaf elements into the ans list
void addLeaves(TreeNode<int> *root, vector<int> &ans)
{
    // base case
    if (root == nullptr)
        return;

    // only adding the leaf nodes to ans list
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    // left to right traversal
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    // adding the root to the ans list initially
    ans.push_back(root->data);

    // handling left boundary logic
    addLeftBoundary(root, ans);
    // handling leaf nodes logic
    addLeaves(root, ans);
    // handling right boundary logic
    addRightBoundary(root, ans);
    return ans;
}

// Time Complexity : O(N) ,as we are traversing each node once.
// Space Complexity : O(1) ,as we are not using any extra space.
