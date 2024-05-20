// Topological Sort / Kahn's Algorithm
// Problem statement
// A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

// Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge
// from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG.

// Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting
// of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the
// given DAG.

// For example, Consider the DAG shown in the picture.

// Link : https://www.naukri.com/code360/problems/topological-sort_982938

// Intuition:
// We will use the Kahn’s Algorithm to find the topological sort of the given DAG.
// We will first calculate the indegree of all the vertices.
// We will then push all the vertices with indegree 0 into a queue.
// We will then process the vertices one by one and reduce the indegree of the adjacent vertices.
// If the indegree of any vertex becomes 0, we will push it into the queue.
// We will keep a count variable to keep track of the number of vertices processed.
// If the count is not equal to the number of vertices, then the graph has a cycle and we will return an empty array.

// Complexity Analysis:
// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).

// Function to perform topological sort on a directed acyclic graph
vector<int> topologicalSort(vector<vector<int>> &edges, int numVertices, int numEdges)
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