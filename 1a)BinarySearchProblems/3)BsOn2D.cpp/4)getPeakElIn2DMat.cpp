// Find A Peak Element

// Problem statement
// You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, where each cell contains a positive integer, and adjacent cells are distinct.
// You need to find the location of a peak element in it. If there are multiple answers, find any of them.
// A peak element is a cell with a value strictly greater than all its adjacent cells.
// Assume the grid to be surrounded by a perimeter of ‘-1s’.
// You must write an algorithm that works in O(n * log(m)) or O(m * log(n)) complexity.

// Note:
// In the output, you will see '0' or '1', where '0' means your answer is wrong, and '1' means your answer is correct.

// Example:
// Input: 'n' = 2, 'm' = 2
// 'g' = [[8, 6], [10, 1]]
// Output: 1
// Sample Explanation: Only one peak element is present at [1, 0].

// Link : https://www.codingninjas.com/studio/problems/find-peak-element_7449073

// Brute Force Approach
// We can iterate through the matrix and check if the current element is greater than all its adjacent elements.
// If it is greater than all its adjacent elements, we can return the current element.
// Time Complexity: O(n*m)
// Space Complexity: O(1)

vector<int> findPeakGrid(vector<vector<int>> &g)
{

    int n = g.size();
    int m = g[0].size();
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (g[i][j] > g[i - 1][j] && g[i][j] > g[i + 1][j] && g[i][j] > g[i][j - 1] && g[i][j] > g[i][j + 1])
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// OPTIMAL APPROACH
//  We can use binary search to solve this problem.
//  We will eliminate the rows with no peak element.
//  For a given row, we will find the maximum element in the row.
//  Since the element in the row is greater than all elements in the row,
//  we only have check if the element is greater than the elements in the adjacent columns(top and bottom element).
//  If the element is greater than the top and bottom element, we can return the element.
//  If the the top element is greater, we can eliminate the bottom half of the matrix.
//  If the bottom element is greater, we can eliminate the top half of the matrix.
//  Time Complexity: O(n * log(m)) or O(m * log(n))
//  Space Complexity: O(1)

vector<int> findPeakGrid(vector<vector<int>> &g)
{
    // we will use BS to eleminate the rows
    int n = g.size();
    int m = g[0].size();
    int low = 0, high = n - 1; // applying BS on rows
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        vector<int> rowVec = g[mid]; // row vector

        // finding the index of max element of this row
        //  since we will get the max element of row we only have to compare
        // with the adjacent top and bottom element for peak condition
        int maxElOfRowIndex =
            max_element(rowVec.begin(), rowVec.end()) - rowVec.begin();
        int maxElOfRow = rowVec[maxElOfRowIndex];

        // element above this max element
        int adjacentTopElement = (mid > 0) ? g[mid - 1][maxElOfRowIndex]
                                           : -1; // if exist else -1 otherwise
        int adjacentBottomElement = (mid < n - 1)
                                        ? g[mid + 1][maxElOfRowIndex]
                                        : -1; // if exist else -1 otherwise

        // is peak element
        if (maxElOfRow > topElement && maxElOfRow > lowerElement)
            return {mid, maxElOfRowIndex};

        // move to above half matrix row wise
        if (maxElOfRow < topElement)
        {
            high = mid - 1;
        }
        else // move to lower half matrix row wise
            low = mid + 1;
    }
    return {-1, -1};
}