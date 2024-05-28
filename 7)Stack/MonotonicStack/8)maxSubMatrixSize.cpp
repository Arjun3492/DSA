// Maximum Size Rectangle Sub-matrix With All 1's
// Given a rows x cols binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.

// Problem link: https://leetcode.com/problems/maximal-rectangle/

// Video link:https://www.youtube.com/watch?v=tOylVCugy9k&t=480s

// Approach: Monotonic Stack
// We use the same approach of largest area histogram
// While traversing each row, we calculate the histogram of each row
// and pass the histogram to the largest area histogram function

// Time complexity: O(n*m)
// Space complexity: O(m)

#include <bits/stdc++.h>

// method to calculate largest area histogram
int largestArea(vector<int> &histogram)
{
    int n = histogram.size();
    stack<int> st;

    vector<int> leftBound(n);
    vector<int> rightBound(n);

    // left bound, traversing left to right and using decreasing monotonic stack
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && histogram[st.top()] >= histogram[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            leftBound[i] = i;
        }
        else
        {
            leftBound[i] = i - st.top() - 1;
        }
        st.push(i);
    }

    // clearing stack
    while (!st.empty())
        st.pop();

    // right bound, traversing right to left and using decreasing monotonic stack
    for (int i = n - 1; i > -1; i--)
    {
        while (!st.empty() && histogram[st.top()] >= histogram[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightBound[i] = n - i - 1;
        }
        else
        {
            rightBound[i] = st.top() - i - 1;
        }
        st.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int width = rightBound[i] + leftBound[i] + 1;
        int area = histogram[i] * width;
        maxi = max(maxi, area);
    }
    return maxi;
}

// method to calculate maximum area of sub-matrix of all 1's
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    int maxi = INT_MIN;
    vector<int> histogram(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            // if the element is 0, then we make the bar 0
            {
                histogram[j] = 0;
            }
            else
            // else we add 1 to the bar height
            {
                histogram[j] += 1;
            }
        }
        int area = largestArea(histogram);
        maxi = max(maxi, area);
    }
    return maxi;
}
