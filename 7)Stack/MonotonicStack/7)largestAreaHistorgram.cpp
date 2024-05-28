// Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
// return the area of the largest rectangle in the histogram.

// Video:https://www.youtube.com/watch?v=X0X6G-eWgQ8

// Link : https://www.naukri.com/code360/problems/largest-rectangle-in-a-histogram_1058184

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Approach: Monotonic Stack
// We find the next smaller element on the left and next smaller element on the right for each element of the array.
//  Which marks the left and right bounds of each bar up to which the bar can extend in width.
//  We calculate the area of each bar and return the maximum area.
// Formula used (numberOfBarsToTheLeft + numberOfBarsToTheRight + 1) * heightOfBar

// Time complexity: O(n)
// Space complexity: O(n)

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;

    vector<int> leftBound(n);
    vector<int> rightBound(n);

    // left bound, traversing left to right and using decreasing monotonic stack
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
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
        while (!st.empty() && heights[st.top()] >= heights[i])
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
        int area = heights[i] * width;
        maxi = max(maxi, area);
    }
    return maxi;
}
