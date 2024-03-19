// Search in a row and column-wise sorted matrix
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
// This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example :
// Input: matrix = [[1,4,7,11,15],
//                  [2,5,8,12,19],
//                  [3,6,9,16,22],
//                  [10,13,14,17,24],
//                  [18,21,23,26,30]], target = 5
// Output: true
// Explanation: It is present in the matrix.

// Link : https://leetcode.com/problems/search-a-2d-matrix-ii/

// BRUTE FORCE APPROACH
// We can simply iterate through the matrix and check if the target exists in the matrix.
// If it exists, we can return true, else we can return false.
// Time Complexity: O(n*m)
// Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// OPTIMAL APPROACH
// Since the matrix is sorted row-wise and column-wise, we can use the following approach:
// We can start from the top right corner of the matrix.
// If the target is greater than the current element, we move to the next row.(as the elements in the current row are smaller than the current element)
// If the target is less than the current element, we move to the previous column. (as the elements in the current column are greater than the current element)

// Time Complexity: O(m + n) , where m is the number of rows and n is the number of columns
// Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    pair<int, int> p = {0, m - 1}; // starting from the top left corner
    while (p.first < n && p.second > -1)
    {
        int el = matrix[p.first][p.second];
        if (el == target)
            return true;
        if (el < target)
            p.first++; // moving down to a bigger value
        else
            p.second--; // moving left to a smaller value
    }
    return false;
}