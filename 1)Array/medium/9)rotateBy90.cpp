// Rotate Image by 90 degree
// Problem Statement: Given a matrix, your task is to
// rotate the matrix 90 degrees clockwise.

// IMAGE REF:Rotate Image by 90 degree
// https://miro.medium.com/v2/resize:fit:1400/1*wzh-y6cNX_jNDbvbpiwpJw.png

// BRUTE FORCE APPROACH
// creating a dummy array and inserting elements to it
void rotateMatrix(vector<vector<int>> &matrix, int n)
{
  vector<vector<int>> ans(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ans[j][n - i - 1] = matrix[i][j];
    }
  }
  return ans;
}

// OPTIMAL APPROACH
// Step1: Transpose the matrix ,  by swapping arr[i][j] and arr[j][i] till first half of main diagonal
// Step2: reverse each row of the matrix
// Sc:O(1)
// Tc:O(n^2)
void rotateMatrix(vector<vector<int>> &matrix, int n, int m)
{

  // Transpose the matrix ,  by swapping arr[i][j] and arr[j][i] till first half of main diagonal
  vector<vector<int>> ans(n, vector<int>(n, 0));
  // //transposing the matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      // first half of main diagonal
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  // reversing each row of the matrix
  for (int i = 0; i < n; i++)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}
