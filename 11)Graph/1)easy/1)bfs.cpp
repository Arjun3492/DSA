// BFS in Graph
// Problem Statement:
// Given an adjacency list representation of a directed graph with ‘n’
// vertices and ‘m’ edges. Your task is to return a list consisting of
// Breadth-First Traversal (BFS) starting from vertex 0.

// In this traversal, one can move from vertex 'u' to vertex 'v' only
// if there is an edge from 'u' to 'v'. The BFS traversal should include
// all nodes directly or indirectly connected to vertex 0.

// Link : https://www.naukri.com/code360/problems/bfs-in-graph_973002

// Approach:
//  We will use a queue for the BFS traversal. We will start from the
//  source node and push it into the queue. Then we will pop the front
//  element from the queue and push all its adjacent nodes into the queue.
//  We will repeat this process until the queue is empty.

// Complexity Analysis:
// Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
// Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // list to store the traversal
    vector<int> ans;

    // queue for bfs traversal
    queue<int> q;
    // pushing the starting node to queue
    q.push(0);
    // visited array to maintain the list of visited nodes
    bool vis[n] = {false};
    // marking the starting node as vivited
    vis[0] = true;

    while (!q.empty())
    {
        int currNode = q.front();
        // adding the node to ans list
        ans.push_back(currNode);
        q.pop();
        // exploring the adjacent nodes
        for (int adjacentNode : adj[currNode])
        {
            // if not previously visited
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = true;
                q.push(adjacentNode);
            }
        }
    }
    return ans;
}