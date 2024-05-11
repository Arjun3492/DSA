// Number of Connected Islands
// Problem statement
// You have been given a non-empty grid consisting of only 0s and 1s.
// You have to find the number of islands in the given grid.

// An island is a group of 1s (representing land) connected horizontally,
// vertically or diagonally. You can assume that all four edges of the grid are surrounded by 0s
// (representing water).

// Link : https://www.naukri.com/code360/problems/number-of-islands_845181

// Approach:
// At first we will look for entry points to start the traversal by iterating the grid and finding the "1".
// On encountering an entry to start with , we will traverse and mark its  unvisited neighbouring  nodes as visited in all the 8 adj directions(For this purpose we will use a traversal technique here)
// Once all its neighbouring islands are marked we will increment the ans variable and countinue the same process looking for next entry point.

#include <bits/stdc++.h>

// helper function to look for neighbouring islands and mark them as visited
//  here we will mark an island visited using the val -1
void markNeighbours(vector<vector<int>> &grid, queue<pair<int, int>> &q, int i,
                    int j, int n, int m)
{
    // Traversing the adjacent neighbours
    // We can just use all combination of row ± 1 and col ±1 for visiting anf marking adj neighbours
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {

            int row = i + x;
            int col = j + y;
            // if within the grid boundary and is island
            if ((row >= 0 && row < n) && (col >= 0 && col < m) &&
                (grid[row][col] == 1))
            {
                // marking visited grids as -1
                grid[row][col] = -1;
                // pushing the island to queue for traversal
                q.push({row, col});
            }
        }
    }
}

// Helper function to traverse neighbouring islands using BFS traversal
void traverseNeigbours(vector<vector<int>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();

    // BFS Traversal
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {

        pair<int, int> frontEl = q.front();
        q.pop();

        // marking its adj islands
        markNeighbours(grid, q, frontEl.first, frontEl.second, n, m);
    }
}

// Main function
int numberOfIslands(vector<vector<int>> &grid, int n, int m)
{
    // stores the number of connected answers
    int ans = 0;

    // Looking for an entry point
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // new entry found
            if (grid[i][j] == 1)
            {
                // marking visited grids as -1
                grid[i][j] = -1;
                // traverse and mark its neighbours(connect islands)
                traverseNeigbours(grid, i, j);
                // incrementing ans
                ans++;
            }
        }
    }
    return ans;
}
