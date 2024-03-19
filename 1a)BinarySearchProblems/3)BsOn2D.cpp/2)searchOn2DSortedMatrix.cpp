// Search In A 2D Sorted Matrix
// Problem statement
// You have been given a 2-D array 'mat' of size 'M x N' where 'M' and 'N'
// denote the number of rows and columns, respectively. The elements of each
// row are sorted in non-decreasing order.
// Moreover, the first element of a row is greater than the last
// element of the previous row (if it exists).
// You are given an integer ‘target’, and your task is to find if
// it exists in the given 'mat' or not.

// Example:
// Input: ‘M’ = 3, 'N' = 4, ‘mat’ = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]], ‘target’ = 8
// Output: true
// Explanation: The output should be true as '8' exists in the matrix.

// Link : https://www.codingninjas.com/studio/problems/search-in-a-2d-matrix_980531

// BRUTE FORCE APPROACH
// We can simply iterate through the matrix and check if the target exists in the matrix.
// If it exists, we can return true, else we can return false.
// Time Complexity: O(n*m)
// Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// BETTER APPROACH
//  We can perform BS search on each row of the matrix to find the target.
//  Time Complexity: O(m * logn) , where m is the number of rows and n is the number of columns
//  Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = high - (high - low) / 2;
            if (mat[i][mid] == target)
            {
                return true;
            }
            else if (mat[i][mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

// OPTIMIZED APPROACH
// Since the 2D array is sorted, we can virtually flatten the 2D array into a 1D array and perform binary search on it.
// Using the index of the 1D array, we can calculate the row and column of the element.
// Formula to calculate the row and column of the element:
// row = index / n
// column = index % n
// Time Complexity: O(log(m*n))
// Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    // we will virtually flatten the array, and use the flatten array index to
    // determine the row and column index
    // Using this we can perfom BS on the 2D array
    int low = 0;
    int n = mat.size();
    int m = mat[0].size();
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        int rowIndex = mid / m; // row index
        int colIndex = mid % m; // column index
        if (mat[rowIndex][colIndex] == target)
            return true;
        if (mat[rowIndex][colIndex] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

// OPTIMAL APPROACH
// We can also solve this problem in O(m+n) time complexity using the following approach:
// We start from the top right corner of the matrix.
// If the target is greater than the current element, we move to the next row.
// If the target is less than the current element, we move to the previous column.
// We keep moving until we find the target or reach the end of the matrix.
// Time Complexity: O(m+n)
// Space Complexity: O(1)

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (mat[i][j] == target)
            return true;
        if (mat[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}
