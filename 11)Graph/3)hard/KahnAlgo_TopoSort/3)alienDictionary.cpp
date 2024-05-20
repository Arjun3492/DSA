// Alien dictionary
// Problem statement
// You have been given a sorted (lexical order) dictionary of an alien language.

// Write a function that returns the order of characters as a string in the alien language.
// This dictionary will be given to you as an array of strings called 'dictionary', of size 'N'.

// Link : https://www.naukri.com/code360/problems/alien-dictionary_630423

// Intuition:
// At first we will create a graph from the given dictionary by comparing the adjacent words.
// Then we will perform a topological sort on the graph to get the order of characters in the alien language.

// Complexity Analysis:
// Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary,
// ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes,
// and E = no. of edges.

// Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for
// the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and
// O(K) for the adjacency list used in the algorithm.

#include <bits/stdc++.h>

// helper function to get topo sort of the graph
vector<int> topologicalSort(vector<vector<int>> &edges, int numVertices)
{
    // Initialize the adjacency list and in-degree arrays
    vector<vector<int>> adjList(numVertices);
    vector<int> inDegrees(numVertices, 0);

    // Populate the adjacency list and in-degree arrays
    for (auto &edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        adjList[from].push_back(to);
        inDegrees[to]++;
    }

    // Initialize the queue with all vertices that have in-degree 0
    queue<int> q;
    for (int i = 0; i < numVertices; i++)
    {
        if (inDegrees[i] == 0)
        {
            q.push(i);
        }
    }

    // Initialize the answer vector
    vector<int> ans;

    // Perform the topological sort
    while (!q.empty())
    {
        // Dequeue the next vertex from the queue
        int node = q.front();
        q.pop();

        // Add the vertex to the answer vector
        ans.push_back(node);

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

    // Return the answer vector
    return ans;
}

// main function to get the order of characters in the alien language
string getAlienLanguage(vector<string> &dict, int k)
{
    // Graph creation
    vector<vector<int>> edges;
    for (int i = 0; i < dict.size() - 1; i++)
    {
        string s1 = dict[i], s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        int maxi = max(s1.size(), s2.size());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                edges.push_back({s1[j] - 'a', s2[j] - 'a'});
                break;
            }
        }
    }

    // Get the topological sort of the graph
    vector<int> topo = topologicalSort(edges, k);
    string ans;
    for (int i : topo)
    {
        ans += char(i + 'a');
    }
    return ans;
}