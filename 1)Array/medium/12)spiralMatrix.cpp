// Spiral Traversal of Matrix
// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Create 4 pointers ,top,bottom,left and right
// Initialise top=0,bottom=noOfRows-1,left=0,right=noOfColumns-1;
// Step 1: print left to right from top then increment top
// Step 2: print top to bottom from right then decrement right
// Step 3: print right to left from bottom then decrement bottom
// Step 4: print bottom to top from left then increment left
// Repeat the above steps till top<=bottom and left<=right
// IMAGE REF: Spiral Traversal of Matrix
// https://www.google.com/search?q=spiral+matrix&tbm=isch
// edge case: if top<=bottom and left<=right, cause if only one row or column is left then it will be repeated twice
// Time Complexity: O(n*m), since each element is traversed once
vector<int> spiralMatrix(vector<vector<int>> &MATRIX)
{
  // Write your code here.
  vector<int> ans;
  int n = MATRIX.size();
  int m = MATRIX[0].size();
  int top = 0;
  int bottom = n - 1;
  int right = m - 1;
  int left = 0;
  while (top <= bottom && left <= right)
  {
    // left to right from top
    for (int i = left; i <= right; i++)
    {
      ans.emplace_back(MATRIX[top][i]);
    }
    top++;

    // top to bottom from right
    for (int i = top; i <= bottom; i++)
    {
      ans.emplace_back(MATRIX[i][right]);
    }
    right--;
    // edge case if only one row is left
    // left to right is already done, so no need to repeat right to left on same row
    if (top <= bottom)
    {
      // right to left from bottom
      for (int i = right; i >= left; i--)
      {
        ans.emplace_back(MATRIX[bottom][i]);
      }
      bottom--;
    }
    // edge case if only one column is left
    // top to bottom is already done, so no need to repeat bottom to top on same column
    if (left <= right)
    {
      // bottom to top from left
      for (int i = bottom; i >= top; i--)
      {
        ans.emplace_back(MATRIX[i][left]);
      }
      left++;
    }
  }

  return ans;
}