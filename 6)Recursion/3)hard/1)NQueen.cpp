// N-Queens Problem
// The n-queens puzzle is the problem of placing
// n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to
// the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Link : https://leetcode.com/problems/n-queens/

// Intuition : We can solve this problem using backtracking.
//  For each column , we will try to place the queen in each row and check if it is safe to place the queen in that cell.
//  If it is safe then we will place the queen in that cell and move to the next column.
//  If we are able to place the queen in all the columns then we will add the current board configuration to the result.
//  We will backtrack and try to place the queen in the next row in the current column.

// Brute Force Solution
//  For each cell in the board we will check if it is safe to place the queen in that cell using iterative approach.
// Time Complexity : O(n!*n), n! is the number of possible configurations of the board and n is the time taken to check if the current configuration is safe or not.
// Space Complexity : O(n^2), n^2 is the space taken by the board.

class Solution
{
public:
    // Since we are moving in the right direction checking for each next column, and within the column we are checking for each row down the column
    // we don't need to check for the right side of the current column as we have not placed any queen in the right side of the current column.
    // So we only need to check for the left side of the current column and the left upper and lower diagonal of the current cell.
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        int rowCopy = row;
        int colCopy = col;

        // checking for left side
        while (colCopy >= 0)
        {
            if (board[row][colCopy] == 'Q')
                return false;
            colCopy--;
        }

        colCopy = col; // reset value

        // left upper diagonal
        while (colCopy >= 0 && rowCopy >= 0)
        {
            if (board[rowCopy][colCopy] == 'Q')
                return false;
            colCopy--;
            rowCopy--;
        }

        colCopy = col; // reset value
        rowCopy = row;

        // left lower diagonal
        while (colCopy >= 0 && rowCopy < n)
        {
            if (board[rowCopy][colCopy] == 'Q')
                return false;
            colCopy--;
            rowCopy++;
        }

        return true;
    }

    void helper(int n, int col, vector<string> board,
                vector<vector<string>> &ans)
    {

        if (col == n)
        {
            ans.push_back(board); // if we have placed the queen in all the columns then add the current board configuration to the result
            return;
        }

        for (int row = 0; row < n; row++) // trying to place the queen in each row of the current column, moving down the column
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                helper(n, col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string boardRow(n, '.');
        vector<string> board(n, boardRow); // forming the board
        vector<vector<string>> ans;
        helper(n, 0, board, ans);
        return ans;
    }
};

// Optimized Solution
//  We can optimize the isSafe using 3 hash arrays to keep track if a Queen is already placed in the current row, left diagonal and right diagonal.

// On observing we can form the following three relations one for each of the left diagonal and right diagonal and left side of the current column.
// left  : "row"  remains same
// left lower diagonal :"row + col" remains same
// left upper diagonal : "n-1 + col - row" remains same
// Refer : https://lh6.googleusercontent.com/UZm_6j1v5WQYlA0Y7wMo4LObyB2TdWcWGeZegccZ9VxeDkgf3en9IG9-gnSKtZLAH3b0auF75tyc0oNWC6J1_MFgeqKOGsvQTny6nBD2padF6sISb0LWv16wj9Acy3-Q-4gU_FlB

// Time Complexity : O(n!), n! is the number of possible configurations of the board.
// Space Complexity : O(n^2), n^2 is the space taken by the board.

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> board, int n, vector<int> &leftUpperDiagnol, vector<int> &leftLowerDiagonal, vector<int> &leftRow)
    {
        if (leftRow[row] == 1 || leftUpperDiagnol[n - 1 + col - row] == 1 || leftLowerDiagonal[row + col] == 1)
            return false;
        return true;
    }

    void helper(int n, int col, vector<string> board,
                vector<vector<string>> &ans, vector<int> &leftUpperDiagnol, vector<int> &leftLowerDiagonal, vector<int> &leftRow)
    {

        if (col == n)
        {
            ans.push_back(board); // if we have placed the queen in all the columns then add the current board configuration to the result
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n, leftUpperDiagnol, leftLowerDiagonal, leftRow))
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;                        // marking the current row as visited
                leftUpperDiagnol[n - 1 + col - row] = 1; // marking the left upper diagonal as visited
                leftLowerDiagonal[row + col] = 1;        // marking the left lower diagonal as visited

                // moving to the next column
                helper(n, col + 1, board, ans, leftUpperDiagnol, leftLowerDiagonal, leftRow);

                // backtracking
                board[row][col] = '.';
                leftRow[row] = 0;
                leftUpperDiagnol[n - 1 + col - row] = 0;
                leftLowerDiagonal[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string boardRow(n, '.');
        vector<string> board(n, boardRow); // forming the board
        vector<vector<string>> ans;
        vector<int> leftUpperDiagnol(2 * n - 1, 0);
        vector<int> leftLowerDiagonal(2 * n - 1, 0);
        vector<int> leftRow(n, 0);
        helper(n, 0, board, ans, leftUpperDiagnol, leftLowerDiagonal, leftRow);
        return ans;
    }
};