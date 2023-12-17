// The Celebrity Problem
// LinK:https://www.codingninjas.com/studio/problems/the-celebrity-problem_982769?leftPanelTabValue=PROBLEM

// Video Solution:https://youtu.be/LtGnA5L6LIk?si=uutWNVGV-w1tuHHN

// knows(a,b) is a helper function which is defined in the problem statement.
// returns true if a knows b, else returns false.

int findCelebrity(int n)
{
    int ans = -1;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();

        if (knows(p1, p2))
        {
            st.push(p2);
        }
        else
        {
            st.push(p1);
        }
    }

    ans = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != ans && !knows(i, ans) || knows(ans, i))
        {
            return -1;
        }
    }
    return ans;
}