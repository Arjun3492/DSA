// Rotting Oranges
// Problem statement
// You have been given a grid containing some oranges.
// Each cell of this grid has one of the three integers values:

// Value 0 - representing an empty cell.
// Value 1 - representing a fresh orange.
// Value 2 - representing a rotten orange.
// Every second, any fresh orange that is adjacent(4-directionally) to a rotten orange becomes rotten.

// Your task is to find out the minimum time after which no cell has a fresh orange.
// If it's impossible to rot all the fresh oranges then print -1.

// Approach:
// Maintain a ans variable to store the time taken to rot all oranges.
// Maintain a queue to store the rotten oranges along with time.
// Maintain a 2D array to store the rotten status of each cell.
// (Its a good practice to maintain a separate array to store the status of each cell, as we should not modify the original data provided to us.)
// Steps:
//  1. Traverse the grid and push all rotten oranges to queue along with time.
//  2. Traverse the neighbours of rotten oranges and push them to queue along with time.
//  3. Repeat step 2 until queue is empty.
//  4. While processing the queue, update the ans variable with the time.
//  5. Lastly ,Check if all oranges are rotten, if yes return the time else return -1.

// Link : https://www.naukri.com/code360/problems/rotting-oranges_701655

// helper function to rot the neighbours of a rotten orange
void rottNeighbours(vector<vector<int>> &grid,
                    queue<pair<int, pair<int, int>>> &q, int t, int n, int m,
                    int x, int y, vector<vector<bool>> &rottenOranges)
{

    // traverse in adjacent 4 directions
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int row = x + delRow[i];
        int col = y + delCol[i];
        // if within bound and is a fresh orange and not previously rottenOranges(rotten)
        if ((row >= 0 && row < n) && (col >= 0 && col < m) &&
            (grid[row][col] == 1) && !rottenOranges[row][col])
        {
            // rot the orange
            rottenOranges[row][col] = true;
            // push the rotten orange to queue along with time
            q.push({t + 1, {row, col}});
        }
    }
}

// helper function to process the neighbours of rotten oranges pushed in queue
void traverseNeighbours(vector<vector<int>> &grid,
                        queue<pair<int, pair<int, int>>> &q, int &ans,
                        vector<vector<bool>> &rottenOranges)
{
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
        auto orange = q.front();
        q.pop();
        int x = orange.second.first;
        int y = orange.second.second;
        int t = orange.first;
        ans = max(ans, t);
        rottNeighbours(grid, q, t, n, m, x, y, rottenOranges);
    }
}

// Entry function to find the minimum time to rot all oranges
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // stores the time taken to rot all oranges
    int ans = 0;
    // stores the rotten oranges
    queue<pair<int, pair<int, int>>> q;

    // stores the rotten status of each cell
    vector<vector<bool>> rottenOranges(n, vector<bool>(m, false));

    // push all the intial rotten oranges to queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                // Mark as rottenOrange and push to queue
                rottenOranges[i][j] = true;
                q.push({0, {i, j}});
            }
        }
    }

    // once all rotten oranges are pushed to queue, process them
    traverseNeighbours(grid, q, ans, rottenOranges);

    // checking if all oranges are now rotten
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if fresh orange is still present
            if (grid[i][j] == 1 && rottenOranges[i][j] == false)
            {
                return -1;
            }
        }
    }
    return ans;
}
