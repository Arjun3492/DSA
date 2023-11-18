// Remove K Digits

// Problem Statement:Given string num representing a non-negative integer num, and an integer k,
// return the smallest possible integer after removing k digits from num.

// Video link:https://www.youtube.com/watch?v=ZdWqQs7ADhw&t=434s

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Approach: Monotonic Stack
// We use a stack to keep the track of the digits.
// We traverse the string from left to right.
// At each iteration, we check if the current digit is smaller than the top element of the stack.
// If yes then we pop the top element of the stack and repeat the process until the top element of the
// stack is smaller than the current digit or the stack becomes empty while k is non zero.
// We push the current digit to the stack.
// After the above process, if k is still non-zero we pop the top k elements from the stack(as stack is decreasing monotonic).

string removeKDigits(string num, int k)
{
    // Write your code here.
    stack<char> st;
    int n = num.size();
    if (n == k)
    {

        return "0";
    }
    // using previous smaller element approach to pop the greater top elements
    // from stack
    int i;
    for (i = 0; i < n; i++)
    {
        char digit = num[i];
        while (!st.empty() && st.top() > digit && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    // handling case if no digit were popped(digits were in increasing order)
    // simply popping the last k digits
    while (k > 0)
    {
        st.pop();
        k--;
    }

    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    // if ans consists of leading 0s
    while (!ans.empty() && ans[0] == '0' && ans.size() > 1)
        ans.erase(0, 1);

    return ans;
}
