// Shortest Path In A Binary Maze
// Problem statement
// Given a maze in the form of a binary rectangular matrix of size M*N,
// where each element can either be 0 or 1, the task is to find the length
// of the shortest path in a maze from a given source cell to a destination cell.

// The path can only be created out of a cell if its value is 1 and at any given
// moment, we can only move one step in one of the four directions

// Link : https://www.naukri.com/code360/problems/shortest-path-in-a-binary-maze_893065

// Intuition:
// We will perform a BFS traversal on the given matrix starting from the source cell.
// With each move, we will increment the distance by 1.
// We will keep track of the visited cells to avoid visiting them again.
// If we reach the destination cell, we will return the distance.
// If we are unable to reach the destination cell, we will return -1.

#include <bits/stdc++.h>

// helper function to check if the cell is within the bounds of the matrix
bool isWithinBound(int x, int y, int n, int m)
{
    return ((x >= 0 && x < n) && (y >= 0 && y < m));
}

// main function
int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src,
                             pair<int, int> dest)
{

    // edge case: if source or destination cell is blocked(ie is 0)
    if (matrix[src.first][src.second] == 0 ||
        matrix[dest.first][dest.second] == 0)
    {
        return -1;
    }

    // BFS traversal
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src.first, src.second}}); // pushing the source to queue to start with
    vis[src.first][src.second] = 1;       // intially marking the src as visited

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        int d = it.first;
        int x = it.second.first;
        int y = it.second.second;
        q.pop();

        // if this is the target
        if (x == dest.first && y == dest.second)
        {
            return d;
        }

        // check for all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int nr = x + dx[i];
            int nc = y + dy[i];

            // if the cell is within bounds and is not visited and is not blocked
            if (isWithinBound(nr, nc, n, m) && !vis[nr][nc] && matrix[nr][nc] == 1)
            {
                // continue the traversal
                vis[nr][nc] = 1;
                q.push({d + 1, {nr, nc}});
            }
        }
    }

    // if we are unable to reach the destination return -1
    return -1;
}