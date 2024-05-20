# Shortest Path Algorithms: Dijkstra, Bellman-Ford, and Floyd-Warshall

## Introduction

Shortest path algorithms are fundamental in computer science for solving problems related to finding the shortest path between nodes in a graph. Three commonly used algorithms for this purpose are Dijkstra's algorithm, Bellman-Ford algorithm, and Floyd-Warshall algorithm. Each of these algorithms has its own strengths, weaknesses, and specific use cases.

## Dijkstra's Algorithm

### Overview
Dijkstra's algorithm finds the shortest path from a single source node to all other nodes in a graph with non-negative edge weights.

### Complexity
- **Time Complexity:** \(O(V^2)\) with an adjacency matrix, or \(O(E + V \log V)\) with a priority queue and adjacency list, where \(V\) is the number of vertices and \(E\) is the number of edges.
- **Space Complexity:** \(O(V)\) for storing the shortest path estimates and the priority queue.

### Use Cases
- **Shortest path from one to all nodes in a graph with non negative weights**

### Advantages and Disadvantages
- **Advantages:** Efficient for graphs with non-negative weights, and relatively simple to implement.
- **Disadvantages:** Cannot handle graphs with negative edge weights.

## Bellman-Ford Algorithm

### Overview
The Bellman-Ford algorithm computes the shortest paths from a single source node to all other nodes in a graph and can handle graphs with negative edge weights.

### Complexity
- **Time Complexity:** \(O(VE)\)
- **Space Complexity:** \(O(V)\) for storing distances and predecessors.

### Use Cases
- **Shortest path from one to all nodes in a graph , negative weights are allowed**

### Advantages and Disadvantages
- **Advantages:** Handles negative weights and can detect negative weight cycles.
- **Disadvantages:** Slower compared to Dijkstra's algorithm for graphs with non-negative weights.

## Floyd-Warshall Algorithm

### Overview
The Floyd-Warshall algorithm finds shortest paths between all pairs of nodes in a graph. It uses dynamic programming to achieve this and handles graphs with negative weights but no negative weight cycles.

### Complexity
- **Time Complexity:** \(O(V^3)\)
- **Space Complexity:** \(O(V^2)\) for the distance matrix.

### Use Cases
- **Shortest path between all pair of nodes ,negative weights allowed**

### Advantages and Disadvantages
- **Advantages:** Simple to implement and can handle graphs with negative weights.
- **Disadvantages:** Inefficient for large graphs due to its cubic time complexity.

## Summary

Each of these algorithms serves a specific purpose and is suited for different types of problems:
- **Dijkstra's Algorithm:** Best for graphs with non-negative weights and applications requiring single-source shortest paths efficiently.
- **Bellman-Ford Algorithm:** Suitable for graphs with negative weights and applications needing detection of negative weight cycles.
- **Floyd-Warshall Algorithm:** Ideal for applications needing shortest paths between all pairs of nodes, especially in smaller graphs or dense graphs.

Understanding the strengths and weaknesses of each algorithm allows for choosing the appropriate one based on the specific requirements of the problem at hand.
