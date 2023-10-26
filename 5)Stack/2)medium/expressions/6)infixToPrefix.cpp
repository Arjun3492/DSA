// Problem Statement:
//  Given an infix expression, Your task is to convert the given infix expression to a prefix expression.

// Video explanation: https://youtu.be/snDDBjT8jYA?si=jvd9-wGHpm5SiPPh

// Example 1:
// Input: infix = (a-b/c)*(a/k-l)
// Output: *-a/bc-/akl

// Example 2:
// Input: infix = A*(B+C)/D
// Output: /*A+BCD

// Steps involved:
//  1. Scan the infix expression from right to left.
//  2. If the scanned character is an operand, add it to the result.
//  3. Else, if the scanned character is an operator, pop two operands from the stack, concatenate them with the operator and add it to the result.
//  4. Repeat steps 2 and 3 until the infix expression is ended.

// Function to determine the precedence of an operator
int getPrecedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
        return 0;
}

// Function to convert an infix expression to a prefix expression
string infixToPrefix(string exp)
{
    string ans;     // Initialize the resulting prefix expression
    stack<char> st; // Initialize a stack to hold operators

    // Iterate through each character in the input expression
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        // If the character is an operand (letter or digit), add it to the result
        if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' ||
            exp[i] >= '1' && exp[i] <= '9')
        {
            ans += exp[i];
        }
        // If the character is an closing parenthesis, push it onto the stack
        else if (exp[i] == ')')
        {
            st.push(exp[i]);
        }
        // If the character is a opening parenthesis, pop and output from the stack until an closing parenthesis is encountered
        else if (exp[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // If the character is an operator
        else
        {
            // Pop and output from the stack until an operator with lower precedence than the scanned operator is encountered
            while (!st.empty() && getPrecedence(st.top()) >= getPrecedence(exp[i]))
            {
                ans += st.top();
                st.pop();
            }
            // Push the scanned operator to the stack
            st.push(exp[i]);
        }
    }
    // Pop and output from the stack until it is empty
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    // Reverse the result
    reverse(ans.begin(), ans.end());
    return ans;
}
