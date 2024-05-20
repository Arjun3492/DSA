// Detect Cycle In A Directed Graph
// Problem statement
// You are given a directed graph having ‘N’ nodes.
// A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge
// directed from node EDGES[i][0] to node EDGES[i][1].

// Find whether the graph contains a cycle or not,
// return true if a cycle is present in the given directed graph else return false.

// Link : https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

// Intuition:
// We will use Kahn’s Algorithm to find the topological sort of the given DAG.
// If the size of the topological sort is not equal to the number of vertices, then the graph has a cycle.
// Since Topological sort is only possible in a Directed Acyclic Graph(DAG), if the graph has a cycle,
// then the topological sort will not contain all the vertices.

// Complexity Analysis:
// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).

#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int numVertices, vector<pair<int, int>> &edges)
{
    // Initialize the adjacency list and in-degree arrays
    vector<vector<int>> adjList(numVertices + 1);
    vector<int> inDegrees(numVertices + 1, 0);

    // Populate the adjacency list and in-degree arrays
    for (auto &edge : edges)
    {
        int from = edge.first;
        int to = edge.second;
        adjList[from].push_back(to);
        inDegrees[to]++;
    }

    // Initialize the queue with all vertices that have in-degree 0
    queue<int> q;
    for (int i = 1; i < numVertices + 1; i++)
    {
        if (inDegrees[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;

    // Perform the topological sort
    while (!q.empty())
    {
        // Dequeue the next vertex from the queue
        int node = q.front();
        q.pop();

        count++;

        // Decrement the in-degree of all adjacent vertices
        for (auto &adjNode : adjList[node])
        {
            inDegrees[adjNode]--;

            // If the in-degree of an adjacent vertex becomes 0, enqueue it
            if (inDegrees[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    return count == numVertices ? 0 : 1;
}