// Check if graph is bipartite
//  A graph is bipartite if the nodes can be partitioned into two independent sets A and B
//  such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

// Link : https://leetcode.com/problems/is-graph-bipartite/
// https://www.naukri.com/code360/problems/check-bipartite-graph-_920551

// Approach :
//  We will follow a bfs traversal and maintain a visited array to keep track of visited nodes.
//  Also for each graph component we will maintain a color array to keep track of the color of each node.
// And during traversal if we encounter a node that is already visited and has the same color as the current node then we can say that the graph is not bipartite.
// i.e. this adjacent node was already visited and has the same color as the current node then the graph is not bipartite.

#include <bits/stdc++.h>

// helper function to check for bipartite graph in any given graph component using BFS traversal
bool isCompBipartite(vector<vector<int>> &graph, vector<bool> &vis, int n,
                     int node)
{

    vis[node] = true;

    // colored array to keep track of the color of each node
    vector<int> colored(n, -1);

    // coloring the start node intially with 0
    colored[node] = 0;

    // bfs traversal
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        // current node
        auto currNode = q.front();
        q.pop();
        // adjacent nodes of the current node
        for (int adjNode : graph[currNode])
        {
            if (!vis[adjNode])
            {
                // if not visited then color it with opposite color of the current node
                colored[adjNode] = !colored[currNode];

                // mark as visited and push to queue
                vis[adjNode] = true;
                q.push(adjNode);
            }
            else
            {
                // if already visited and has the same color as the current node then return false
                if (colored[adjNode] == colored[currNode])
                    return false;
            }
        }
    }

    return true;
}

// main function to check if the graph is bipartite
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();

    // creating adjacency list from given matrix
    vector<vector<int>> adj_list(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // if there is an edge between i and j
            if (edges[i][j] == 1)
            {
                adj_list[i].push_back(j); // Edge from i to j
                adj_list[j].push_back(i); // Edge from j to i (bi-directional)
            }
        }
    }

    // visited array to keep track of visited nodes
    vector<bool> vis(n, false);

    // connected components
    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
            // if any of the component is not bipartite then return false
            if (isCompBipartite(adj_list, vis, n, i) == false)
                return false;
        }
    }

    // lastly if all the components are bipartite then return true
    return true;
}