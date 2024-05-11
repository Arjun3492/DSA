// BFS for graph with components
//  Problem Statement:
//  Given an adjacency list representation of a graph with ‘n’ vertices and ‘m’ edges.
//  Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.
//  It is given that the graph may contain multiple components.

// Problem Link: https://www.naukri.com/code360/problems/bfs-in-graph_973002

// Approach:
//  We will maintain a visited array to keep track of the nodes that are visited.
//  We will iterate over all the nodes and if the node is not visited, we will perform BFS traversal starting from that node.

// Complexity Analysis:
// Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
// Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list

// Function to perform BFS traversal starting from a node
void bfsComponent(int &i, bool[] vis, queue<int> &q, vector<int> &ans)
{
    // pushing the starting node to queue
    q.push(i);
    // marking the starting node as vivited
    vis[i] = true;

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
}

// Function to perform BFS traversal for entire graph
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // list to store the traversal
    vector<int> ans;

    // queue for bfs traversal
    queue<int> q;
    // visited array to maintain the list of visited nodes
    bool vis[n] = {false};

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfsComponent(i, vis, q, ans);
        }
    }
    return ans;
}