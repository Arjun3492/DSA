// Immediate Smaller Element
// Problem Statement: Given an integer array arr, for each element in arr, check if the immediate next element is smaller.
// If it is,update the current index with the next smaller element. If not, update the current index with -1.

// Input: arr = [4, 2, 1, 5, 3]
// Output: [2, 1, -1, 3, -1]

// Approach: Stack
// We use a stack to keep the track of the next element.
// We traverse the array from right to left.
// At each iteration, we check if the current element is smaller than the top element of the stack.
// If yes then we update the current element with the top element of the stack else set it to-1.
// We pop the last element of the stack and push the current element to the stack.

void immediateSmaller(vector<int> &a)
{
    // using stack to keep the track of next element
    int n = a.size();
    stack<int> st;

    // traverse the array from right
    for (int i = n - 1; i > -1; i--)
    {
        if (i == n - 1)
        // if its the last element (starting of loop),push the element to stack and
        // update the last index to -1 as their is no element next to it.
        {
            st.push(a[i]);
            a[i] = -1;
            continue;
        }
        if (st.top() < a[i])
        // if the current top(only element) element in stack is smaller than the current element,update the current el
        // store the original val of current el to stack
        {
            int tmp = a[i];
            a[i] = st.top();
            st.pop();
            st.push(tmp);
        }
        else
        {
            // else simply pop the top element and push
            st.pop();
            st.push(a[i]);
            a[i] = -1;
        }
    }
}