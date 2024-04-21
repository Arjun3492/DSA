// Top View Of Binary Tree
// Problem statement
// You are given a Binary Tree of 'n' nodes.
// The Top view of the binary tree is the set of nodes visible when we see the tree from the top.
// Find the top view of the given binary tree, from left to right.

// Link : https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401

// Approach:
// We will follow the vertical order traversal approach to solve this problem.
// We will use a map<int,int> to store the vertical value(x) and the value of the node.
// Since the level order traversal follows a top to bottom and left to right approach, we will only store the first node at a particular vertical value.
// This will ensure that we only store the topmost node at a particular vertical value,giving us the top view of the binary tree.

#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{

    // stores the result
    vector<int> ans;

    // edge case: if null tree
    if (!root)
        return ans;
    // to store the vertical along with node data
    map<int, int> mpp;

    // stores node along with the vertical
    queue<pair<TreeNode<int> *, int>> q;

    q.push({root, 0});

    // Level order traversal technique
    while (!q.empty())
    {

        // popping the front element from queue
        pair<TreeNode<int> *, int> currEl = q.front();
        q.pop();
        TreeNode<int> *currNode = currEl.first;
        int x = currEl.second;

        // pushing the node children into the queue along the the value of x
        if (currNode->left)
            q.push({currNode->left, x - 1});
        if (currNode->right)
            q.push({currNode->right, x + 1});

        // Storing the node data into the map only for a given new vertical
        if (mpp.find(x) == mpp.end())
        {
            mpp[x] = currNode->data;
        }
    }

    // since map stored the keys in increasing order
    // we can directly push the key values to the ans list
    for (auto it : mpp)
    {
        int nodeVal = it.second;
        ans.push_back(nodeVal);
    }

    return ans;
}
