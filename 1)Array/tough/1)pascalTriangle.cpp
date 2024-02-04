// Program to generate Pascal’s Triangle
// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1 : Given row number r and column number c.Print the element at position(r, c)
// in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3:Print the first N rows of a pascal triangle

// Link:https://www.codingninjas.com/studio/problems/print-pascal-s-triangle_6917910

// Variation 1
// The element at row r and column c in a Pascal’s triangle is given by the formula:
// (r-1)! / (c-1)!(r-c)!
// i.e. nCr

int getPascalElement(int r, int c)
{
    int res = 1;
    for (int i = 1; i <= c; i++)
    {
        res *= (r - i + 1);
        res /= i;
    }
    return res;
}

// Variation 2
// Approach: Looping from 0 to n-1 , computing each element of row through the above method getPascalElement
// Time Complexity: O(n^2)
// Space Complexity: O(1)

vector<int> getPascalRow(int N)
{
    vector<int> res;
    for (int i = 0; i < N; i++)
    {
        res.push_back(getPascalElement(N, i));
    }
    return res;
}

// Optimal Approach:
// By observation we find that for a given row N,
//  it's element are given as 1,N/1,N*N-1/1*2,N*N-1*N-2/1*2*3,....,N/1
// so if we take 0 based indexing for each row ,and start the iteration from 1 ,the general formula would become
// ∏(N-i)/i

// Space Complexity: O(n)
// Time Complexity: O(n)

vector<int> getPascalRow(int N)
{
    vector<int> res;
    res.push_back(1);
    int temp = 1;
    for (int i = 1; i < N; i++)
    {
        temp *= (N - i);
        temp /= i;
        res.push_back(temp);
    }
    return res;
}

// Variation 3
//  Approach: Using the above method getPascalRow to print the first N rows of Pascal Triangle
// Time Complexity: O(n^2)

vector<vector<int>> generatePascalTriangle(int N)
{
    vector<vector<int>> res;
    for (int i = 1; i < = N; i++)
    {
        res.push_back(getPascalRow(i));
    }
    return res;
}
