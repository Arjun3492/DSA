// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Problem statement
// You are given ‘N’ cities numbered from 0 to N-1 and ‘M’ edges.
// These cities are connected with undirected weighted edges.
// You are also given a positive integer, ‘distanceThreshold’.

// Your task is to find the ‘city’ to which the minimum number of cities are reachable
// through some path whose distance is no more than the given ‘distanceThreshold’.

// Note:
// 1. If multiple such cities exist, you have to find the city with the greatest number.
// 2. The distance of a path connecting two cities, ‘U’ and ‘V’, is the sum of the weight of the edges along that path.
// 3. The distance between two cities is the minimum of all possible path distances.

// Link : https://www.naukri.com/code360/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance_1264289

// Intuition:
// At first we will find the shortest distance between all pairs of cities using any shortest path algorithm.
// We will then iterate over all the cities and for each city, we will count the number of cities that are reachable from it within the given distanceThreshold.
// We will then return the city with the minimum number of reachable cities .

#include <bits/stdc++.h>

// helper function to get the shortest distance between all pairs of cities using Floyd Warshall Algorithm
void getPathDistances(int n, vector<vector<int>> &edges,
                      vector<vector<int>> &dist)
{

    // Initializing distances to self element to  0
    for (int i = 0; i < n; ++i)
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
        dist[c][r] = w;
    }

    // Flloyd Warshall Algorithm
    //  We will consider each vertex as an intermediate vertex and update the
    //  distance matrix
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
}

// main function
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    // Initializing the distance matrix with a large value
    vector<vector<int>> distances(n, vector<int>(n, 1e9));
    // Getting the shortest distance between all pairs of cities
    getPathDistances(n, edges, distances);
    int ansCity = -1;
    int minCnt = n;

    // Iterating over all the cities
    for (int city = 0; city < n; city++)
    {
        int cityCnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++)
        {
            // Checking if the distance between the cities is less than or equal to the given distanceThreshold
            if (distances[city][adjCity] <= distanceThreshold)
            {
                cityCnt++;
            }
        }
        // Updating the city with the minimum number of reachable cities within the given distanceThreshold
        if (cityCnt <= minCnt)
        {
            ansCity = city;
            minCnt = cityCnt;
        }
    }
    return ansCity;
}