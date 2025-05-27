// 84. Largest Rectangle in Histogram

// https://leetcode.com/problems/largest-rectangle-in-histogram
class Solution
{

    // Area formed by a bar in histogram can be given by
    //  Bar height* width(index_of_smaller_element_on_right - index_of_smaller_element_on_left -1)

private:
    // Intuition: for each bar we will find the max span in each left and right direction
    // TC:O(n^2)
    // SC:O(1)
    int brute(vector<int> &heights)
    {
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {

            int currHeight = heights[i];
            int leftSpan = 0, rightSpan = 0;
            int prevIndex = i - 1;
            while (prevIndex >= 0 && heights[prevIndex] >= currHeight)
            {
                leftSpan++;
            }
            int nextIndex = i + 1;

            while (nextIndex < n && heights[nextIndex] >= currHeight)
            {
                rightSpan++;
            }

            // edge case if bar bounded by ajacent smaller elements
            if (leftSpan == 0)
                leftSpan = 1;
            if (rightSpan == 0)
                rightSpan = 1;
            int area = currHeight * (leftSpan + rightSpan);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    // Intuition : for each element we precompute the previous smaller and next
    // smaller bar index using the nextSmallerElement and previousSmallerElement
    // monotonic stack techniques

    // TC:O(3n) = O(n)
    // SC:O(n)
    int better(vector<int> &heights)
    {

        // array storing left smaller bar index for each bar at index I
        vector<int> leftSmallerIndex = getPreviousSmallerElements(heights);

        // array storing right smaller bar index for each bar at index I
        vector<int> rightSmallerIndex = getNextSmallerElements(heights);

        // ans
        int maxArea = INT_MIN;
        int n = heights.size();
        for (int i = ; i < n; i++)
        {
            int height = heights[i];
            int width = rightSmallerIndex[i] - leftSmallerIndex[i] - 1;
            maxArea = max(maxArea, height * width);
        }
    }

    // Intuition : We will traverse from left to right and for each each
    // element we know the previous smaller element using monotonic stack
    // technique, but when we pop an element out of stack that is greater
    // than the current element, we know that the current element is the
    // next smaller element of the element that is being popped, and the
    // previous smaller element of the element to be popped is below that in stack
    // TC:O(n)
    // SC:O(n)
    int optimal(vector<int> &heights)
    {

        // adding a 0 at the end to process all the remaining bars in the stack,
        // as 0 is minimum possible height it will pop all the remaining bars in the stack
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        // Traversing from left to right
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            // for each current bar, lets pop elements smaller than it in the stack

            while (!st.empty() && heights[i] < heights[st.top()])
            {
                // current index i is the right smaller element for the
                // element that is being popped out

                int heightOfBarToBeProcessed = heights[st.top()];
                st.pop(); // popping it out
                int rightSmallerBarIndex = i;
                // leftSmallerBarIndex = next element at top of stack
                int leftSmallerBarIndex = st.empty() ? -1 : st.top();

                int width = rightSmallerBarIndex - leftSmallerBarIndex - 1;
                int area = heightOfBarToBeProcessed * width;
                maxArea = max(maxArea, area);
            }
            // pushing current bar index to stack
            st.push(i);
        }
        return maxArea;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        return optimal(heights);
    }
};