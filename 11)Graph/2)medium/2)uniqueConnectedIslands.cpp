// Distinct Islands
// Problem statement
// You are given a two-dimensional array/list of integers consisting of 0s and 1s.
// In the list, 1 represents land and 0 represents water.

// The task is to find the number of distinct islands where a group of connected 1s
// (horizontally or vertically) forms an island.

// Note:
// Two islands are considered to be the same if and only if one island is equal to another
// (not rotated or reflected) i.e if we can translate one island on another without rotating
// or reflecting then it would be considered as the same islands.

// Link : https://www.naukri.com/code360/problems/distinct-islands_630460

// Video explanation : https://youtu.be/7zmgQSJghpo?si=u4aPhJDC3DrUip4w

// Approach:
// Similar to the number of islands problem, we will traverse the grid and look for the entry points to start the traversal.
// On encountering an entry to start with, we will traverse and mark its unvisited neighbouring nodes as visited in all the 4  directions.
// Once all its neighbouring islands are marked we will store the path in a vector using relative indexing following the same order of traversal.
// We will store the path in a set to keep track of the distinct islands.
// Once all the islands are traversed we will return the size of the set which will give us the number of distinct islands.

// helper function to mark adjacent islands and store the path in vector
void markNeighbours(int **grid, queue<pair<int, int>> &q,
                    vector<pair<int, int>> &distInlands, int i, int j,
                    int rowSize, int colSize, int origin_i, int origin_j)
{

    // Traversing the adjacent neighbours
    int dirRow[] = {0, 0, -1, 1};
    int dirCol[] = {-1, 1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int row = i + dirRow[k];
        int col = j + dirCol[k];
        // if within the grid boundary and is island
        if ((row >= 0 && row < rowSize) && (col >= 0 && col < colSize) &&
            (grid[row][col] == 1))
        {
            // marking visited grids as -1
            grid[row][col] = -1;
            // pushing the island to queue for traversal
            q.push({row, col});
            // storing the path in vector ,using relative indexing
            distInlands.push_back({row - origin_i, col - origin_j});
        }
    }
}

// helper function to traverse neighbouring islands using BFS traversal

void traverseNeigbours(int **grid,
                       vector<pair<int, int>> &distInlands,
                       int origin_i, int origin_j, int rowSize, int colSize)
{
    // marking the island as visited
    grid[origin_i][origin_j] = -1;
    // pushing the island to queue for traversal
    distInlands.push_back({0, 0});

    // BFS Traversal
    queue<pair<int, int>> q;
    q.push({origin_i, origin_j});
    while (!q.empty())
    {
        pair<int, int> frontEl = q.front();
        q.pop();
        // marking its adj islands
        markNeighbours(grid, q, distInlands, frontEl.first, frontEl.second, rowSize, colSize, origin_i, origin_j);
    }
}

// Main function
int distinctIslands(int **grid, int rowSize, int colSize)
{
    // stores the unique islands
    set<vector<pair<int, int>>> s;

    // Traversing the grid
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            // if island is found
            if (grid[i][j] == 1)
            {
                // storing the origin of the island
                int origin_i = i;
                int origin_j = j;
                // storing the path of the island
                vector<pair<int, int>> distInlands;

                // traversing the island
                traverseNeigbours(grid, distInlands, origin_i, origin_j, rowSize, colSize);
                // storing the path in set
                s.insert(distInlands);
            }
        }
    }
    return s.size();
}