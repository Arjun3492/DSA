// Print Shortest Path in Weighted undirected graph

// Link : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

// Intuition:
//  We will use the Dijkstra's Algorithm to find the shortest path from the source node to all the other nodes.
//  And we will maintain a parent array to keep track of the parent of each node in the shortest path.
//  After finding the shortest path, we will use the parent array to print the shortest
// path from the source node to the destination node by traversing the parent array from
// the destination node to the source node.(Traceback)

#include <bits/stdc++.h>
int shortestPath(int v, int e, vector<vector<int>> &edges, int src, int dest)
{
    // Creating adjacency list
    vector<vector<pair<int, int>>> adjacencyList(v);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adjacencyList[u].emplace_back(weight, v);
        adjacencyList[v].emplace_back(weight, u);
    }

    // Distances list to store the final result(initializing it with INT_MAX)
    vector<int> distances(v, INT_MAX);

    // BFS Traversal
    queue<pair<int, int>> q;

    // starting with src
    q.emplace(0, src);
    distances[src] = 0;

    // parent array to store the parent of each node in the shortest path(initializing it with -1)
    vector<int> parent(v, -1);

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int edgeWeight = top.first;
        int currentNode = top.second;

        // neighbours
        for (auto neighbor : adjacencyList[currentNode])
        {
            int weight = neighbor.first;
            int adjacentNode = neighbor.second;
            if (weight + edgeWeight < distances[adjacentNode])
            {
                parent[adjacentNode] = currentNode;
                distances[adjacentNode] = weight + edgeWeight;
                q.emplace(weight + edgeWeight, adjacentNode);
            }
        }
    }

    // Traceback logic to find the shortest path from src to dest
    vector<int> path;
    int tracebackNode = dest;
    while (parent[tracebackNode] != -1)
    {
        path.push_back(tracebackNode);
        tracebackNode = parent[tracebackNode];
    }
    path.push_back(src);
    return reverse(path.begin(), path.end());
}
