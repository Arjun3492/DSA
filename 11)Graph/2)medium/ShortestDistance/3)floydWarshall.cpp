// Floyd Warshall Algorithm
//  Problem statement
//  You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges.
//  Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.

// Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to
// you in the graph using Flloyd warshall’s algorithm. The graph may contain negatively weighted edges.

// Link : https://www.naukri.com/code360/problems/floyd-warshall_2041979

// Intuition:
// We will use the Floyd Warshall algorithm to find the shortest path between all pairs of vertices.
// Floyd Warshall algo considers all the vertices as intermediate vertices and tries to find the shortest path.
// We will initialize the distance matrix with the given weights and then update the distance matrix by considering each vertex as an intermediate vertex one by one and updating the distance matrix.
// We will then return the distance between the source and destination vertices.

int floydWarshall(int n, int m, int a, int b, vector<vector<int>> &edges)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    // Initializing distances to self element to  0
    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
    }

    // Initializing the weights of the edges
    for (auto &edge : edges)
    {
        int r = edge[0];
        int c = edge[1];
        int w = edge[2];
        dist[r][c] = w;
    }

    // Flloyd Warshall Algorithm
    //  We will consider each vertex as an intermediate vertex and update the distance matrix
    for (int via = 0; via < n; ++via)
    {
        for (int from = 0; from < n; ++from)
        {
            for (int to = 0; to < n; ++to)
            {
                //( from -> to) ==> (from -> via -> to)
                if (dist[from][via] != 1e9 && dist[via][to] != 1e9)
                    dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
            }
        }
    }

    return dist[a][b];
}
