// Implement Disjoint set
// Problem statement:
// Disjoint set is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
// A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
// Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset(in constant time).
// Union: Join two subsets into a single subset.

// It can be used to find connected components in an undirected graph.

// Link : https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

// Intuition:
// We will use the disjoint set data structure to keep track of the connected components in the graph.
// We will initialize the parent array with each node as its parent.
// We will use the findUParent function to find the ultimate parent of the set in which an element belongs.
// We will use the unionByRank function to join two subsets into a single subset based on the rank of the subsets.
// We will use the unionBySize function to join two subsets into a single subset based on the size of the subsets.

// Complexity Analysis:
// Time Complexity: O(logN) to O(4alpha) ~ O(1) for both find and union operations.
// Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the parent array, O(N) for the rank array, and O(N) for the size array.

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
        // Path compression: Make the parent of the nodes in the path from x to parent[x] point to parent[x]
        return parent[x] = findUParent(parent[x]);
    }

    // Union by rank: Attach the smaller rank tree under the root of the larger rank tree
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
        // If ranks are same, then make one as root and increment its rank by 1(as the height of the tree will increase by 1)
        else
        {
            parent[yParent] = xParent;
            rank[xParent]++;
        }
    }

    // Union by size: Attach the smaller size tree under the root of the larger size tree
    void unionBySize(int x, int y)
    {
        int xParent = findUParent(x);
        int yParent = findUParent(y);
        // Means x and y are already in the same set(Same Graph component)
        if (xParent == yParent)
            return;

        // Attach the smaller size tree under the root of the larger size tree and update the size of the larger tree
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
}
