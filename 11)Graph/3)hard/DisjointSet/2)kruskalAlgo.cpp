// Kruskal’s Minimum Spanning Tree Algorithm
// Problem statement
// A minimum spanning tree is a subset of the edges of a connected,
// edge-weighted undirected graph that connects all the vertices without
// any cycles and with the minimum possible total edge weight.

// A spanning tree’s weight is the sum of the weights of each edge in the spanning tree.

// You have been given a connected undirected weighted graph having 'n' vertices,
// from 1 to 'n', and 'm' edges.

// You are given an array 'edges' of size 'm', containing the details of the edges of the graph.

// Each element of 'edges' contains three integers, the two vertices that are
// being connected and the weight of the edge.

// Find the weight of the minimum spanning tree of the given graph.

// Link : https://www.naukri.com/code360/problems/kruskal-s-minimum-spanning-tree-algorithm_1082553

// Intuition:
//  We will sort the edges based on their weights.
//  Then using disjoint set, we will join the edges in increasing order of their weights if not already joined.
//  We will keep adding the weight of the edge to the answer if the edge is added to the MST.

// Complexity Analysis:
//  Time Complexity: O(ElogE + ElogV), [ElogE for sorting the edges and E*4alpha for union-find operations]
//  Space Complexity: O(V), [for parent, rank and size arrays]

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    // Constructor to create and initialize sets of n elements
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        // rank of all nodes is 0 initially [Used to find union by rank]
        rank.resize(n + 1, 0);
        // size of all nodes is 1 initially [Used to find union by size]
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    // Find the ultimate parent of the set in which element x belongs
    int findUParent(int x)
    {
        if (parent[x] == x)
            return x;
        // Path compression: Make the parent of the nodes in the path from x to
        // parent[x] point to parent[x]
        return parent[x] = findUParent(parent[x]);
    }

    // Union by rank: Attach the smaller rank tree under the root of the larger
    // rank tree
    void unionByRank(int x, int y)
    {
        int xParent = findUParent(x);
        int yParent = findUParent(y);
        // Means x and y are already in the same set(Same Graph component)
        if (xParent == yParent)
            return;
        // Attach the smaller rank tree under the root of the larger rank tree
        if (rank[xParent] < rank[yParent])
            parent[xParent] = yParent;
        else if (rank[xParent] > rank[yParent])
            parent[yParent] = xParent;
        // If ranks are same, then make one as root and increment its rank by 1(as
        // the height of the tree will increase by 1)
        else
        {
            parent[yParent] = xParent;
            rank[xParent]++;
        }
    }

    // Union by size: Attach the smaller size tree under the root of the larger
    // size tree
    void unionBySize(int x, int y)
    {
        int xParent = findUParent(x);
        int yParent = findUParent(y);
        // Means x and y are already in the same set(Same Graph component)
        if (xParent == yParent)
            return;

        // Attach the smaller size tree under the root of the larger size tree and
        // update the size of the larger tree
        if (size[xParent] < size[yParent])
        {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        }
        else
        {
            parent[yParent] = xParent;
            size[xParent] += size[yParent];
        }
    }
};

// helper function to sort the edges based on their weights
bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

// Function to find the weight of the minimum spanning tree of the given graph
int kruskalMST(int n, vector<vector<int>> &edges)
{
    // sorting the given edges in increasing order of w
    // edge={u,v,w}
    // TC: O(ElogE)
    sort(edges.begin(), edges.end(), comp);

    // total weight of the minimum spanning tree
    int ans = 0;

    // Initialize the disjoint set
    DisjointSet ds(n);

    // TC:O(E*4alpha) post path compression OR  O(ElogV)
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        // if not connected
        if (ds.findUParent(u) != ds.findUParent(v))
        {
            // connect
            ds.unionBySize(u, v);
            // increase total edge weight
            ans += w;
        }
    }
    return ans;
}
