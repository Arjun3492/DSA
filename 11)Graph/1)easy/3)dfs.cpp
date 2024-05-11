// Depth first traversal for a graph

// Problem Statement:
// Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges.
// Your task is to return a list consisting of Depth-First Traversal (DFS) starting from vertex 0.

// In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'.

// Link : https://www.naukri.com/code360/problems/dfs-in-graph_973003

// Approach:
//  We will use a recursive function to perform the DFS traversal. We will start from the source node and explore all its adjacent nodes.
//  We will repeat this process for all the nodes in the graph.

// Complexity Analysis:
// Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
// Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.

// Function to perform DFS traversal starting from a node
void dfs(int &i, bool[] vis, vector<int> &ans)
{
    // marking the starting node as vivited
    vis[i] = true;
    // adding the node to ans list
    ans.push_back(i);

    // exploring the adjacent nodes
    for (int adjacentNode : adj[i])
    {
        // if not previously visited
        if (!vis[adjacentNode])
        {
            dfs(adjacentNode, vis, ans);
        }
    }
}

// Function to perform DFS traversal
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int start = 0;
    // create a list to store dfs
    vector<int> ls;
    // call dfs for starting node
    dfs(start, adj, vis, ls);
    return ls;
}
