// Vertical Order Traversal of Binary Tree
// Problem statement :
// You are given a binary tree having 'n' nodes.

// Vertical order traversal is a traversal in which we traverse the nodes from left to
// right and then from top to bottom.

// In the case of multiple nodes in the same place, we traverse them in the non-decreasing
// order of their value.

// Formally, assume for any node at position (x, y), its left child will be at the position
// (x - 1, y + 1), and the right child at position (x + 1, y + 1). Assume the root is at coordinate (0, 0).

// Run vertical lines from 'x' = -infinity to 'x' = +infinity. Now whenever this vertical
// line touches some nodes, we need to add those values of the nodes in order starting from top to bottom with the decreasing 'y' coordinates.

// If multiple nodes have the same 'x' and 'y' coordinates, they will be accessed in
// non-decreasing order of values.

// Find the vertical order traversal of the given tree.

// Link : https://www.naukri.com/code360/problems/vertical-order-traversal_3622711

// Approach:
// To solve the problem, we perform a level order traversal of the binary tree while keeping track
// of each node's coordinates. Using a map structure, we organize nodes based on their x-coordinates,
// and within each x-coordinate, we organize nodes by their y-coordinates using a priority queue
// ( priority queue will help us return nodes at the same x, y value in increasing order as per stated in ques).
// This allows us to maintain the correct vertical order traversal pattern while ensuring nodes
// with the same coordinates are ordered by their values. Finally, we construct the answer list
// by traversing the map and popping elements from the priority queues in the correct order.

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{

    // stores the ans list
    vector<int> ans;

    // edge case: null tree
    if (!root)
        return ans;

    // stores the nodes at a given coordinates {x,{y,[nodes]}}
    // using priority_queue since we want nodes at a given same x,y value in
    // non-decreasing
    map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mpp;

    // queue for level order traversal, with node and its coordinates
    queue<pair<TreeNode<int> *, pair<int, int>>> q;

    // initially inserting the root node into queue taking (0,0) as the
    // coordinates
    q.push({root, {0, 0}});

    while (!q.empty())
    {

        // popping the front el of queue
        pair<TreeNode<int> *, pair<int, int>> currElement = q.front();
        q.pop();
        // Current Node
        TreeNode<int> *currNode = currElement.first;
        // Current Node's coordinates
        int x = currElement.second.first;
        int y = currElement.second.second;

        // Pushing its children into queue along with the coordinates
        if (currNode->left)
            q.push({currNode->left, {x - 1, y + 1}});
        if (currNode->right)
            q.push({currNode->right, {x + 1, y + 1}});

        // if element at a new coordinate if found
        //  construct a priority queue for it and add it to map
        if (mpp[x].count(y) == 0)
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            pq.push(currNode->data);
            mpp[x][y] = pq;
        }
        else
        {
            mpp[x][y].push(currNode->data);
        }
    }

    // traversing the map and storing the nodes in ans list
    for (auto it : mpp)
    { // Iterate over key-value pairs in the outer map
        for (auto pq : it.second)
        { // Iterate over key-value pairs in the inner map (priority queue)
            while (!pq.second.empty())
            {                                   // Accessing the priority queue directly with pq.second
                ans.push_back(pq.second.top()); // Pushing the top element of the priority queue to ans
                pq.second.pop();                // Pop the top element from the priority queue
            }
        }
    }

    return ans;
}