// Time To Burn Tree
// //Problem statement
// You have a binary tree of 'N' unique nodes and a Start node
// from where the tree will start to burn. Given that the Start
// node will always exist in the tree, your task is to print the
// time (in minutes) that it will take to burn the whole tree.

// It is given that it takes 1 minute for the fire to travel from
// the burning node to its adjacent node and burn down the adjacent node.

// Link : https://www.naukri.com/code360/problems/time-to-burn-tree_1469067

// Approach:
// Since we know in order to burn the tree from the start node, we need to move radially
// outwards from the start node and increment the time by 1 minute for each adjacent non visited node.
// So at first we will generate the child to parent map .
// Then we will perform a depth order traversal starting from the start node and
// keep track of the time taken to burn the tree and also the nodes that have already been visited/burnt.

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>

int findBurnTime(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &upLink, BinaryTreeNode<int> *target)
{

    queue<BinaryTreeNode<int> *> q;

    q.push(target);

    map<BinaryTreeNode<int> *, int> vis;

    vis[target] = 1;

    int timer = 0;

    while (!q.empty())
    {

        int n = q.size();

        int flag = 0;

        for (int i = 0; i < n; i++)
        {

            auto node = q.front();

            q.pop();

            if (node->left && !vis[node->left])
            {

                flag = 1;

                vis[node->left] = 1;

                q.push(node->left);
            }

            if (node->right && !vis[node->right])
            {

                flag = 1;

                vis[node->right] = 1;

                q.push(node->right);
            }

            if (upLink[node] && !vis[upLink[node]])
            {

                flag = 1;

                vis[upLink[node]] = 1;

                q.push(upLink[node]);
            }
        }

        if (flag)
            timer++;
    }

    return timer;
}

// Helper function to generate parent reference map and find the start node
void generateUpLinkAndFindStartNode(
    BinaryTreeNode<int> *node,
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &upLink, int start,
    BinaryTreeNode<int> *&startNode)
{
    if (!node)
    {
        return;
    }

    // Check if current node is the start node
    if (node->data == start)
    {
        startNode = node;
    }

    // Add parent references for children
    if (node->left)
    {
        upLink[node->left] = node;
    }
    if (node->right)
    {
        upLink[node->right] = node;
    }

    // Recursively find start node in left and right subtrees
    generateUpLinkAndFindStartNode(node->left, upLink, start, startNode);
    generateUpLinkAndFindStartNode(node->right, upLink, start, startNode);
}

// Driver function
int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{

    // Parent reference map
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> upLink;

    BinaryTreeNode<int> *startNode;
    // Generates parent reference map and finds the start node
    generateParentRef(root, upLink, start, startNode);

    // Find the time to burn the tree
    int time = findBurnTime(upLink, startNode);

    return time;
}