// Bellman Ford
// Problem statement
// You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N'
// and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting
// the distance between them.

// Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.

// Note:
// If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer
// array will be 10^8

// Link : https://www.naukri.com/code360/problems/bellmon-ford_2041977

// Note: Since Dijkstra's algorithm is not able to handle negative weights, as it will stuck in an infinite loop as the distance will keep on reducing due to negative weight

//  Intuition:
//  We will relax the edges V-1 times and if we are able to relax the edges Vth time then there is a negative cycle in the graph.
//  We will maintain a distance array and initially all the distances will be infinity except the source node which will be 0.
// The intuition is that since on the first relaxtion the distance to source node is 0 so the first adjacent node from source node will relax
// and the distance to that node will be updated and so on. So the distance to the last node will be updated in the V-1th relaxation.

// Relaxation : distance[u] + weight < distance[v] then distance[v] = distance[u] + weight

// Complexity Analysis
//  Time complexity: O(V*E) where V is the number of vertices and E is the number of edges
//  Space complexity: O(V) for storing the distances

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{

    // Distance array with initial distances as inf
    vector<int> distances(n + 1, 1e8);
    // Distance to src node set a 0
    distances[src] = 0;

    // Relaxation n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Relaxation logic
            if (distances[u] + w < distances[v])
            {
                distances[v] = distances[u] + w;
            }
        }
    }

    // Checking for negative cycle
    // Relaxing for one more time and if relaxed it means there's a -ve cycle
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        // Relaxation logic
        if (distances[u] + w < distances[v])
        {
            return {-1};
        }
    }

    return distances;
}