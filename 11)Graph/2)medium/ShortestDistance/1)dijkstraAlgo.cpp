// Dijkstra's shortest path
// Problem statement
// You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1)
// and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting
// the distance between node ‘X’ and node ‘Y’.

// Your task is to find the shortest path distance from the source node,
// which is the node labeled as 0, to all vertices given in the graph.

// Link : https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469

// Intuition:
//  We will maintain a distance array and initially all the distances will be infinity
//  except the source node which will be 0.
// Now we will follow a brute force approach and keep on updating the distance array
//  by checking if the current distance to a node is less than the previous distance stored in the distance array.

// Dijkstra's Algorithm using priority queue
// Time Complexity: O((V+E)*logV). Going through N nodes and E edges and log N for priority queue
//  Space complexity: O(V)
vector<int> dijkstraUsingQueue(vector<vector<pair<int, int>>> &adjacencyList,
                               vector<int> &distances, int source)
{

    // Priority queue to store nodes with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // starting with source
    pq.emplace(0, source);
    distances[source] = 0;

    while (!pq.empty())
    {
        auto top = pq.front();
        pq.pop();
        int edgeWeight = top.first;
        int currentNode = top.second;

        // neighbours
        for (auto neighbor : adjacencyList[currentNode])
        {
            int weight = neighbor.first;
            int adjacentNode = neighbor.second;
            if (weight + edgeWeight < distances[adjacentNode])
            {
                distances[adjacentNode] = weight + edgeWeight;
                pq.emplace(weight + edgeWeight, adjacentNode);
            }
        }
    }

    return distances;
}

// Dijkstra's Algorithm using set
// Time complexity: O(ElogV)
// Space complexity: O(V)

vector<int> dijkstraUsingSet(vector<vector<pair<int, int>>> &adjacencyList,
                             vector<int> &distances, int source)
{

    // Traversal with Set
    set<pair<int, int>> s;
    s.insert({0, source});
    distances[source] = 0;

    while (!s.empty())
    {
        auto it = *(s.begin());
        // current distance and node
        int currentDistance = it.first;
        int currentNode = it.second;
        s.erase(it);

        // neighbours
        for (auto neighbor : adjacencyList[currentNode])
        {
            int weight = neighbor.first;
            int adjacentNode = neighbor.second;
            int newDistance = currentDistance + weight;
            if (newDistance < distances[adjacentNode])
            {
                // If the distance to a node is less than the previous distance stored in the distance array
                // it a path greater than this is already stored in set so we will remove it to avoid unnecessary
                // computation for that path
                if (distances[adjacentNode] != INT_MAX)
                {
                    s.erase({distances[adjacentNode], adjacentNode});
                }

                // Updating the distance array
                distances[adjacentNode] = newDistance;
                // Inserting the new distance and node in the set
                s.insert({newDistance, adjacentNode});
            }
        }
    }
    return distances;
}

// main function
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source)
{
    // Creating adjacency list
    vector<vector<pair<int, int>>> adjacencyList(vertices);
    for (auto edge : vec)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adjacencyList[u].emplace_back(weight, v);
        adjacencyList[v].emplace_back(weight, u);
    }

    // Distances list to store the final result(initializing it with INT_MAX)
    vector<int> distances(vertices, INT_MAX);

    return dijkstraUsingSet(adjacencyList, distances, source);
    // OR
    // return dijkstraUsingQueue(adjacencyList, distances, source);
}