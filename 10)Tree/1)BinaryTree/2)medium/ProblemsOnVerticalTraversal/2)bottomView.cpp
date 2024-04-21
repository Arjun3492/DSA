// Bottom View Of Binary Tree
// Problem statement :
// You are given a binary tree having 'n' nodes.
// The bottom view of the binary tree is the set of nodes visible when we see the tree from the bottom.
// Find the bottom view of the given binary tree, from left to right.

// Link : https://www.naukri.com/code360/problems/bottom-view-of-binary-tree_893110

// Approach:
// We will follow the vertical order traversal approach to solve this problem.
// We will use a map<int,int> to store the vertical value(x) and the value of the node.
// Since the level order traversal follows a top to bottom and left to right approach, we will update the node value for a given vertical in the map.
// This will ensure that we only have the bottommost node at a particular vertical value(by the end of traversal), giving us the bottom view of the binary tree.
// We will use a queue to store the nodes along with their vertical values and perform a level order traversal to update the map.
// Finally, we will push the values from the map to the answer list.

#include <bits/stdc++.h>
vector<int> bottomView(TreeNode<int> *root)
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

        // Storing and updating the node data in the map ,
        // as the last node at a given vertical will form the bottom view
        mpp[x] = currNode->data;
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
