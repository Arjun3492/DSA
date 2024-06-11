// Count Square Submatrices with all Ones
// Problem statement
// A matrix 'arr' with 'n' rows and 'm' columns is given.
// Count the number of square submatrices in matrix ‘arr’ with all elements equal to 1.
// A square matrix is a matrix with square dimensions.

// Link :https://www.naukri.com/code360/problems/count-square-submatrices-with-all-ones_3751502

// Approach : We will use tabulation to solve this
//  We will create a 2D DP table to store the size of the largest square submatrix ending at each cell
//  We will conclude each cell of Dp matrix as the number of square submatrices ending at that cell(bottom-right corner)
//  We will initialize the first row and first column of the DP table(As they are the base cases)
//  We will fill the DP table in a bottom-up manner
//  If the cell is non-zero, then the size of the largest square submatrix ending at this cell is 1 plus the minimum size of the largest square submatrices ending at the top, left, and top-left cells
//  If the cell is zero, then the size of the largest square submatrix ending at this cell is 0
//  We will calculate the total count of square submatrices by summing up the DP table
//  We will return the total count of square submatrices

// Function to count the number of square submatrices in a matrix with all elements equal to 1
int countSquares(int numRows, int numCols, vector<vector<int>> &matrix)
{
    // Create a 2D DP table to store the size of the largest square submatrix ending at each cell
    vector<vector<int>> dpTable(numRows, vector<int>(numCols, 0));

    // Initialize the first row and first column of the DP table
    for (int col = 0; col < numCols; col++)
        dpTable[0][col] = matrix[0][col];
    for (int row = 0; row < numRows; row++)
        dpTable[row][0] = matrix[row][0];

    // Fill the DP table in a bottom-up manner
    for (int row = 1; row < numRows; row++)
    {
        for (int col = 1; col < numCols; col++)
        {
            // If the current cell in the matrix is 0, the size of the largest square submatrix ending at this cell is 0
            if (matrix[row][col] == 0)
                dpTable[row][col] = 0;
            else
            {
                // The size of the largest square submatrix ending at this cell is 1 plus the minimum size of the largest square submatrices ending at the top, left, and top-left cells
                dpTable[row][col] = 1 + min(dpTable[row - 1][col], min(dpTable[row - 1][col - 1], dpTable[row][col - 1]));
            }
        }
    }

    // Calculate the total count of square submatrices by summing up the DP table
    int totalSquareSubmatrices = 0;
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            totalSquareSubmatrices += dpTable[row][col];
        }
    }
    return totalSquareSubmatrices;
}

// Time complexity: O(n*m)
// Space complexity: O(n*m)
