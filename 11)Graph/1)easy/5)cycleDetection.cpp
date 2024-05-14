// Cycle Detection In Undirected Graph

// Problem statement
// You have been given an undirected graph with 'N' vertices and 'M' edges.
// The vertices are labelled from 1 to 'N'.
// Your task is to find if the graph contains a cycle or not.
// A path that starts from a given vertex and ends at the same vertex traversing
// the edges only once is called a cycle.
// Return "YES" if the graph contains a cycle, otherwise return "NO".

// Link :https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670

// Approach :
//  We will follow a bfs traversal and maintain a visited array to keep track of visited nodes.
//  For traversal we will use a queue that will store the current node and its parent.
//  And during traversal if we find a node that is already visited and is not the parent of the current node then we can say that there is a cycle in the graph.
// i.e. this adjacent node was already visited and is not the parent of the current node then there is a cycle in the graph.

#include <bits/stdc++.h>

// Using BFS traversal to check for cycle formation in any given graph component

// helper function to check for cycle formation in any given graph component using BFS traversal
bool checkCycleInComponentBFS(int node, int parent, bool vis[],
                              vector<vector<int>> adj_list)
{

    // marking visited as true
    vis[node] = true;
    //{node,parent}
    queue<pair<int, int>> q;
    q.push({node, parent});

    // bfs traversal of graph
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it.first;
        int parent = it.second;
        for (int adjacentNode : adj_list[node])
        {
            if (!vis[adjacentNode])
            {
                q.push({adjacentNode, node});
                vis[adjacentNode] = true;
            }
            // if was already visited and isn't the parent node of the curr node
            //(means cycle formation as this node is previously visited by any other node)
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
    }
    return false;
}

// Using DFS traversal to check for cycle formation in any given graph component

// helper function to check for cycle formation in any given graph component using DFS traversal
bool checkCycleInComponentDFS(int node, int parent, bool vis[],
                              vector<vector<int>> adj_list)
{

    // marking visited as true
    vis[node] = true;

    // traversing the adjacent nodes
    for (int adjacentNode : adj_list[node])
    {
        // if adjacent node is not visited
        if (!vis[adjacentNode])
        {
            // recursively checking for cycle in the component
            if (checkCycleInComponentDFS(adjacentNode, node, vis, adj_list))
                return true;
        }
        // if adjacent node is visited and is not the parent node of the current node
        //(means cycle formation as this node is previously visited by any other node)
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    // creating adjacency list from given edges
    vector<vector<int>> adj_list(n + 1);
    for (vector<int> edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    // initialising the visited list initially with all false
    bool vis[n + 1] = {false};

    // loop for traversing the connected components
    for (int i = 1; i <= n; i++)
    {
        // if this node is a potential starting of a component
        if (!vis[i])
        {
            // check for cycle in component
            bool res = checkCycleInComponentBFS(i, -1, vis, adj_list);

            // OR
            //  bool res = checkCycleInComponentDFS(i, -1, vis, adj_list);

            if (res == true)
                return "Yes";
        }
    }

    // at the end ,if no cycles were found in any component
    return "No";
}
