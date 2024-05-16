// Nearest 0
// Problem statement
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

// Link : https://leetcode.com/problems/01-matrix/

// Intuition:
// We will use the BFS traversal to find the distance of the nearest 0 for each cell.
// We will start with the cell having 0 and push it into the queue and mark it as visited.
// Then we will traverse the neighbors of the cell and if the neighbor is not visited then we will push it into the queue and mark it as visited.
// We will keep on updating the distance of the cell from the nearest 0 by incrementing the distance with each level of traversal.

// Time complexity: O(m*n)
// Space complexity: O(m*n)

vector<vector<int>> maximumZeroOneDistance(vector<vector<int>> &matrix, int N, int M)
{
    // visited array
    vector<vector<int>> vis(N, vector<int>(M, 0));
    // Intially all distances are marked as INT_MAX
    vector<vector<int>> distance(N, vector<int>(M, INT_MAX));

    //<x,y,dist>
    queue<tuple<int, int, int>> q;

    // Pushing all the cells with 0 into the queue
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] == 0)
            {
                vis[i][j] = 1;
                distance[i][j] = 0;
                q.push(make_tuple(i, j, 0));
            }
        }
    }

    int dCol[] = {-1, 0, 1, 0};
    int dRow[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = get<0>(it);
        int y = get<1>(it);
        int d = get<2>(it);

        // traverse adjacent nodes
        for (int i = 0; i < 4; i++)
        {
            int nRow = x + dRow[i];
            int nCol = y + dCol[i];

            // If the cell is within the matrix and not visited
            if ((nRow >= 0 && nRow < N) && (nCol >= 0 && nCol < M) &&
                vis[nRow][nCol] == 0)
            {
                // Mark the cell as visited
                vis[nRow][nCol] = 1;
                // Update the distance of the cell from the nearest 0
                distance[nRow][nCol] = d + 1;
                // Push the cell into the queue along with the distance
                q.push(make_tuple(nRow, nCol, d + 1));
            }
        }
    }
    return distance;
}