// Number of Islands II
// Problem statement
// A 2d grid map of m rows and n columns is initially filled with water.
// We may perform an addLand operation which turns the water at position (row, col) into a land.
// Given a list of positions to operate, count the number of islands after each addLand operation.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or
// vertically. You may assume all four edges of the grid are all surrounded by water.

// Link : https://www.naukri.com/code360/problems/largest-island_840701

// Intuition:
// We will use disjoint set to keep track of the connected islands.
// We will keep a count variable.
// When we create a new island we will increment the count var.
// and when we find an adjacent non-connected island , we will connect it and decrement the count.

// Complexity Analysis:
// Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries.
// The term 4α is so small that it can be considered constant.

// Space Complexity: O(Q) + O(N*M) + O(N*M), where Q = no. of queries,
// N = total no. of rows, M = total no. of columns.
// The last two terms are for the parent and the size array used inside the Disjoint set data structure.
// The first term is to store the answer.

vector<int> countIslands(int numRows, int numCols, vector<vector<int>> &queries, int numQueries)
{
    // Initialize the result vector
    vector<int> result;

    // Create a disjoint set for the grid
    DisjointSet disjointSet(numRows * numCols);

    // Initialize the grid with all zeros
    vector<vector<int>> grid(numRows, vector<int>(numCols, 0));

    // Define the directions for DFS (up, right, down, left)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // Initialize the island count
    int islandCount = 0;

    // Process each query
    for (auto query : queries)
    {
        int row = query[0];
        int col = query[1];
        int position = row * numCols + col;

        // If the cell is already land, skip it
        if (grid[row][col] == 1)
        {
            result.push_back(islandCount);
            continue;
        }

        // Mark the cell as land
        grid[row][col] = 1;
        islandCount++;

        // Check the neighboring cells
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            int newPosition = newRow * numCols + newCol;

            // Check if the neighboring cell is within the grid
            if ((newRow >= 0 && newRow < numRows) && (newCol >= 0 && newCol < numCols))
            {
                // If the neighboring cell is land and not in the same island, merge them
                if (grid[newRow][newCol] == 1 && disjointSet.findUParent(position) != disjointSet.findUParent(newPosition))
                {
                    islandCount--;
                    disjointSet.unionBySize(position, newPosition);
                }
            }
        }

        // Add the current island count to the result
        result.push_back(islandCount);
    }

    return result;
}