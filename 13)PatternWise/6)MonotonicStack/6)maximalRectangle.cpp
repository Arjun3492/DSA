// 85. Maximal Rectangle

// https://leetcode.com/problems/maximal-rectangle

class Solution
{

private:
    // Function to calculate the largest rectangle area in a histogram
    int areaOfHistogram(vector<int> &heights)
    {
        // Add a sentinel value (0) at the end
        // This ensures all bars in the stack get processed by the end of the loop
        heights.push_back(0);

        int n = heights.size();
        stack<int> st; // Stack to store indices of bars
        int maxArea = 0;

        // Traverse through all histogram bars
        for (int i = 0; i < n; i++)
        {
            // If current bar is shorter than the bar on top of the stack,
            // we've found the "next smaller element" for the top bar
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int height = heights[st.top()]; // Height of the bar to be processed
                st.pop();                       // Remove it from stack

                // The right boundary is the current index (i)
                int right = i;

                // The left boundary is the index on top of the stack after popping
                int left = st.empty() ? -1 : st.top();

                // Width is the number of bars between left and right (exclusive)
                int width = right - left - 1;

                // Calculate area with the current height
                int area = height * width;

                // Update maximum area found so far
                maxArea = max(maxArea, area);
            }

            // Push the current index to the stack
            st.push(i);
        }

        return maxArea;
    }

    // Function to compute the maximal rectangle of 1s in a binary matrix
    int optimal(vector<vector<char>> &matrix)
    {
        // Handle empty matrix case
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size();

        // This will store the "height" of 1s in each column (like histogram bars)
        vector<int> prefixRow(m, 0);
        int maxRectangleArea = 0;

        // Go row by row
        for (int i = 0; i < n; i++)
        {
            // Update the histogram height for each column
            for (int j = 0; j < m; j++)
            {
                // If the current cell is '1', add to the height
                // Otherwise, reset height to 0
                prefixRow[j] = (matrix[i][j] == '1') ? prefixRow[j] + 1 : 0;
            }

            // For each row (now treated as a histogram), find max area
            int area = areaOfHistogram(prefixRow);

            // Update the global max rectangle area
            maxRectangleArea = max(maxRectangleArea, area);
        }

        return maxRectangleArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        return optimal(matrix);
    }
};