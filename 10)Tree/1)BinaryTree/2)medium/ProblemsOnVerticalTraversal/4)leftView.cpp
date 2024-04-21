// Left View Of Binary Tree
// Problem statement
// You have been given a Binary Tree of 'n' nodes, where the nodes have integer values
// Print the left view of the binary tree.

// Link : https://www.naukri.com/code360/problems/left-view-of-binary-tree_625707

// Level order traversal Approach:
// We will use the level order traversal technique to solve this problem.
// We will use a queue to store the nodes at each level and print the first node at each level.
// This will give us the left view of the binary tree.
vector<int> printLeftView(BinaryTreeNode<int> *root)
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

        // pushing the node children into the queue
        if (currNode->left)
            q.push({currNode->left, level + 1});
        if (currNode->right)
            q.push({currNode->right, level + 1});

        // Storing the node data into the map only for a given new vertical
        if (level == ans.size())
            ans.push_back(currNode->data);
    }

    return ans;
}

// Inorder Traversal Approach:
// We will use the inorder traversal technique to solve this problem.
// We will keep track of the level of the current node and only print the first node at each level.
// This will give us the left view of the binary tree.

// Recursive function to store the left view of the binary tree
void helper(BinaryTreeNode<int> *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    //  add the first node of the new to ans list
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    helper(root->left, level + 1, ans);
    helper(root->right, level + 1, ans);
}

vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    helper(root, 0, ans);
    return ans;
}
