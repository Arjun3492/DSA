// Soduko
//  Write a program to solve a Sudoku puzzle by filling the empty cells.
//  A sudoku solution must satisfy all of the following rules:
//  Each of the digits 1-9 must occur exactly once in each row.
//  Each of the digits 1-9 must occur exactly once in each column.
//  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//  The '.' character indicates empty cells.

// Link : https://leetcode.com/problems/sudoku-solver/

// Intuition : We can solve this problem using backtracking.
//  For each empty cell in the board we will try to place the digits from 1 to 9 and check if it is safe to place the digit in that cell.
//  If it is safe then we will place the digit in that cell and move to the next cell.
// If we have tried all the digits from 1 to 9 and we are not able to place any digit in the current cell then we will backtrack and try to place a different digit in the previous cell.
//  If we are able to place the digit in all the cells then we will return true.

//  Solution
//  For each empty cell in the board we will try to place the digits from 1 to 9 and check if it is safe to place the digit in that cell using iterative approach.
// Time Complexity : O(9^(m*n)), 9 is the number of possible digits and m*n is the number of empty cells in the board.
// Space Complexity : O(m*n), m*n is the space taken by the board.

class Solution
{
public:
    // checking if the current value can be placed in the cell
    bool isValid(int i, int j, vector<vector<char>> &board, int value)
    {

        for (int k = 0; k < 9; k++)
        {
            // row check
            if (board[i][k] == value) // checking for the same row
                return false;
            // column check
            if (board[k][j] == value) // checking for the same column
                return false;
            // 3*3 box check
            if (board[3 * (i / 3) + (k / 3)][3 * (j / 3) + (k % 3)] == value) // checking for the same 3*3 box
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // check for empty cells
                if (board[i][j] == '.')
                {
                    // insert
                    for (char value = '1'; value <= '9'; value++)
                    {
                        // checking for validity to place the value in the cell
                        if (isValid(i, j, board, value))
                        {
                            board[i][j] = value;
                            // checking for the next cell
                            bool aageKaSolution = solve(board);
                            if (aageKaSolution == true) // if we are able to place the value in the cell
                                return true;
                            // else backtracking , if we are not able to place the value in the cell
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
