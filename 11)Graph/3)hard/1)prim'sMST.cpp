// Minimum Spanning Tree
// Given a graph with N nodes and M edges, find the minimum spanning tree of the graph.
// A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

// Link : https://www.naukri.com/code360/problems/minimum-spanning-tree_631769

// Approach(Prim's Algo)
// We will follow a greedy approach to find the minimum spanning tree.
// Using a min heap storing the edge weight and the node , we will we get the minimum edge weight and the node at first.
// We will pull out the minimum edge weight and the node and mark it as visited and add the edge weight to the total weight of the minimum spanning tree.
// If the node is already visited we will skip it meaning that the node is previously visited by a edge of lesser or eq weight.
// We will then traverse the adjacent nodes of the current node and push the edge weight and the node to the min heap if not visited.

// Time Complexity : O(ElogV) where E is the number of edges and V is the number of vertices.
// Space Complexity : O(E+V)

#include <bits/stdc++.h>

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{

    // Step 1 : Create a Adjacency list

    vector<vector<pair<int, int>>> adj(n);

    for (auto it : edges)
    {

        int u = it[0];

        int v = it[1];

        int w = it[2];

        adj[u].push_back({w, v});

        adj[v].push_back({w, u});
    }

    // Step 2 : Create a priority queue to store {w, u}

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    // Step 3 : Create a visited array

    vector<bool> vis(n, 0);

    int sum = 0;

    while (!pq.empty())
    {

        auto p = pq.top();

        pq.pop();

        int node = p.second;

        int w = p.first;

        if (vis[node])
            continue;

        // marking the node as visited after popping it out of the min heap
        vis[node] = 1;
        // adding the edge weight to the total weight of the minimum spanning tree
        sum += w;

        // Traverse its adjacent nodes
        for (auto it : adj[node])
        {

            int v = it.second;

            int w = it.first;

            // if the node is not visited then push the edge weight and the node to the min heap
            if (!vis[v])
                pq.push({w, v});
        }
    }

    return sum;
}
