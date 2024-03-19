// Row with max 1s
// Problem statement
// You are given a 2D matrix 'ARR' (containing either ‘0’ or ‘1’) of size 'N' x 'M',
// where each row is in sorted order.
// Find the 0-based index of the first row with the maximum number of 1's.
// Note :
// If two rows have the same number of 1’s, return the row with a lower index.
// If no row exists where at-least one '1' is present, return -1.

// Example:
// Input: ‘N’ = 3, 'M' = 3
// 'ARR' =
// [     [ 1,  1,  1 ],
//       [ 0,  0,  1 ],
//       [ 0,  0,  0 ]   ]
// Output: 0
// Explanation: The 0th row of the given matrix has the maximum number of ones.

// Link : https://www.codingninjas.com/studio/problems/row-of-a-matrix-with-maximum-ones_982768

// BRUTE FORCE APPROACH
// We can simply iterate through the matrix and count the number of 1's in each row.
// We can then return the index of the row with the maximum number of 1's.
// Time Complexity: O(n*m)
// Space Complexity: O(1)

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxOnes = 0;
    int row = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxOnes)
        {
            maxOnes = count;
            row = i;
        }
    }
    return row;
}

// OPTIMIZED APPROACH
// To bring down the time complexity from O(n*m) we can use binary search to solve this problem.
// We use use the lower_bound function to find the first occurrence of 1 in each row.
// Using the index of the first occurrence of 1, we can calculate the number of 1's in each row.
// Using the formula (m - index of first occurrence of 1), we can calculate the number of 1's in each row.
// We can then return the index of the row with the maximum number of 1's.
// Time Complexity: O(n * log(m))
// Space Complexity: O(1)

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    // var for count and index
    int c = -1, index = -1;
    for (int i = 0; i < n; i++) // iteration through the rows
    {
        vector<int> rowVec = matrix[i];
        // Getting the index of  first occurence of 1
        int firstOccurence = lower_bound(rowVec.begin(), rowVec.end(), 1) - rowVec.begin();

        // Number of 1's in this row= size- index of firstOccurence of 1(since 0 and 1 are continuos)
        int freqOfOnes = m - firstOccurence;

        if (freqOfOnes > c)
        {
            c = freqOfOnes;
            index = i;
        }
    }
    return index;
}