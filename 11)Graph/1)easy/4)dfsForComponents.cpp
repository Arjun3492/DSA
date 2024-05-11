// DFS for graph with components

// Problem Statement:
// Given an adjacency list representation of a graph with ‘n’ vertices and ‘m’ edges.
// Your task is to return a list consisting of Depth-First Traversal (DFS) starting from vertex 0.
// It is given that the graph may contain multiple components.

// Problem Link: https://www.naukri.com/code360/problems/dfs-traversal_630462

// Approach:
//  We will maintain a visited array to keep track of the nodes that are visited.
//  We will iterate over all the nodes and if the node is not visited, we will perform DFS traversal starting from that node.
//  We will repeat this process for all the nodes in the graph.

// Complexity Analysis:
// Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
// Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.

// Function to perform DFS traversal starting from a node
void dfsComponent(int &i, bool[] vis, vector<int> &ans)
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
            dfsComponent(adjacentNode, vis, ans);
        }
    }
}

// Function to perform DFS traversal for entire graph
vector<int> dfsTraversal(int n, vector<vector<int>> &adj)
{
    // list to store the traversal
    vector<int> ans;

    // visited array to maintain the list of visited nodes
    bool vis[n] = {false};

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfsComponent(i, vis, ans);
        }
    }
    return ans;
}
