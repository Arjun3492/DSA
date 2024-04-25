// // Print Nodes at Distance K From a Given Node
// Problem statement
// You are given an arbitrary binary tree, a node of the tree, and an integer 'K'.
// You need to find all such nodes which have a distance K from the given node and
// return the list of these nodes.

// Distance between two nodes in a binary tree is defined as the number of connections
// edges in the path between the two nodes.

// Link: https://www.naukri.com/code360/problems/print-nodes-at-distance-k-from-a-given-node_842560

// Approach:
// We will first create a map to store parent references of each node using a depth order traversal.
// We will then perform a depth order traversal starting from the target node to find all nodes at distance K.
// We will keep track of the visited nodes to avoid revisiting them.
// We will also keep track of the distance of each node from the target node.

// Time complexity: O(N)[Parent Reference Map creation] + O(N)[DFS] = O(N).
// Space complexity: O(N) [Map space] + O(N) [Stack space] + O(N) [Result space] = O(N).

#include <bits/stdc++.h>

// helper function to generate the parent reference map
void generateUpLink(
    BinaryTreeNode<int> *node,
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &upLink)
{
    if (!node)
        return;
    // Adding parent refernce to children nodes
    if (node->left)
        upLink[node->left] = node;
    if (node->right)
        upLink[node->right] = node;

    // Moving to left and right subtree
    generateUpLink(node->left, upLink);
    generateUpLink(node->right, upLink);
}

// Helper function to get the nodes at distance K
void getNodesAtDistKRec(
    BinaryTreeNode<int> *node,
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> upLink,
    unordered_map<BinaryTreeNode<int> *, bool> &visitedNodes,
    vector<BinaryTreeNode<int> *> &ans, int K, int currDistance)
{

    // Base case:if reached a null node,
    if (!node)
        return;

    if (currDistance == K)
    {

        ans.push_back(node);
        return;
    }

    // adding the current node to visited nodes set
    // so that we don't move to it again
    visitedNodes[node] = true;

    // Will radily move in all possible directions if not visited and increase
    // distance by 1
    BinaryTreeNode<int> *leftNode = node->left;
    BinaryTreeNode<int> *rightNode = node->right;
    BinaryTreeNode<int> *upNode = upLink[node];

    // Left child direction
    // If left node exists and is not visited, move to left node
    if (leftNode && !visitedNodes[leftNode])
    {
        getNodesAtDistKRec(leftNode, upLink, visitedNodes, ans, K,
                           currDistance + 1);
    }

    // Right child direction
    // If right node exists and is not visited, move to right node
    if (rightNode && !visitedNodes[rightNode])
    {
        getNodesAtDistKRec(rightNode, upLink, visitedNodes, ans, K,
                           currDistance + 1);
    }

    // Parent Direction
    // If parent node exists and is not visited, move to parent node
    if (upNode && !visitedNodes[upNode])
    {
        getNodesAtDistKRec(upNode, upLink, visitedNodes, ans, K, currDistance + 1);
    }
}

vector<BinaryTreeNode<int> *> printNodesAtDistanceK(BinaryTreeNode<int> *root,
                                                    BinaryTreeNode<int> *target,
                                                    int K)
{
    vector<BinaryTreeNode<int> *> ans;
    if (!root)
        return ans;

    // to maintain the child to parent reference
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> upLink;

    // generates the child to parent reference mapping(uplink)
    generateUpLink(root, upLink);

    // will store the visited nodes
    unordered_map<BinaryTreeNode<int> *, bool> visitedNodes;

    // adds the nodes at K distance to the ans list
    getNodesAtDistKRec(target, upLink, visitedNodes, ans, K, 0);
    return ans;
}
