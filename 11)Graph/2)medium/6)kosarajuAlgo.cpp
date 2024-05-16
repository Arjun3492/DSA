// Strongly Connected Components - Kosaraju's Algorithm

// Problem Statement
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
// Find the number of strongly connected components in the graph.

// Link :https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

// Intuition:
// We will use the DFS traversal to find the order of nodes in the graph.
// We will reverse each edge ,this way it would not be possible to each from one SCC to another(Even if the edges are reversed the SCCs will remain the same).
// We will then traverse the graph with inverted edges and count the number of SCCs.(Traversal for connected components)

// helper function to get the order of nodes
void getOrderOfNodesByDfs(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = true; // use bool instead of int for vis array
    for (auto &neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            getOrderOfNodesByDfs(neighbor, vis, adj, st);
        }
    }
    st.push(node);
}

// helper function to traverse the graph with inverted edges
void simpleDfs(int node, vector<bool> &vis, vector<vector<int>> &adjT)
{
    vis[node] = true;
    for (auto &neighbor : adjT[node])
    {
        if (!vis[neighbor])
        {
            simpleDfs(neighbor, vis, adjT);
        }
    }
}

// main function
int stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V); // initialize adj array
    for (const auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]); // build adj array
    }

    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            getOrderOfNodesByDfs(i, vis, adj, st);
        }
    }

    vector<vector<int>> adjT(V); // initialize adjT array
    for (int i = 0; i < V; i++)
    {
        vis[i] = false;
        for (auto &neighbor : adj[i])
        {
            adjT[neighbor].push_back(i); // build adjT array
        }
    }
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            simpleDfs(node, vis, adjT);
        }
    }
    return scc;
}