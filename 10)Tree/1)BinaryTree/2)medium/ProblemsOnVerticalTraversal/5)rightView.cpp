// Right View
// Problem statement
// You have been given a Binary Tree of integers.

// Your task is to print the Right view of it.

// The right view of a Binary Tree is a set of nodes visible when the tree is viewed
// from the Right side and the nodes are printed from top to bottom order.

// Link : https://www.naukri.com/code360/problems/right-view_764605

// Level order traversal Approach:
// We will use the level order traversal technique to solve this problem.
// We will use a queue to store the nodes at each level and print the last node at each level.
// This will give us the right view of the binary tree.

vector<int> printRightView(BinaryTreeNode<int> *root)
{
    // stores the result
    vector<int> ans;

    // edge case: if null tree
    if (!root)
        return ans;

    // stores node along for level order traversal
    queue<pair<BinaryTreeNode<int> *, int>> q;

    q.push({root, 0});

    // Level order traversal technique
    while (!q.empty())
    {

        // popping the front element from queue
        auto currEl = q.front();
        q.pop();
        BinaryTreeNode<int> *currNode = currEl.first;
        int level = currEl.second;

        // pushing the node children into the queue, right child first then left child
        if (currNode->right)
            q.push({currNode->right, level + 1});
        if (currNode->left)
            q.push({currNode->left, level + 1});

        // Storing the node data into the map only for a given new vertical
        if (level == ans.size())
            ans.push_back(currNode->data);
    }

    return ans;
}

// Inorder Traversal Approach:
// We will use the inorder traversal technique to solve this problem.
// We will keep track of the level of the current node and only print the last node at each level.
// This will give us the right view of the binary tree.

void helper(BinaryTreeNode<int> *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    //  add the first node of the new to ans list
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    helper(root->right, level + 1, ans); // right child first
    helper(root->left, level + 1, ans);  // left child
}
vector<int> printRightView(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;

    // inorder traversal
    helper(root, 0, ans);
    return ans;
}