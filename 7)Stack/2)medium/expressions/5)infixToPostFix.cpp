// Problem Statement:
// Given an infix expression, Your task is to convert the given infix expression to a postfix expression.

// Video explanation:https://youtu.be/mg9yi6YuAVk?si=khtuo-rrc3sZ9Two

// Example 1:
// Input: infix = a+b*(c^d-e)^(f+g*h)-i
// Output: abcd^e-fgh*+^*+i-

// Example 2:
// Input: infix = A*(B+C)/D
// Output: ABC+*D/

// Steps involved:
//  1. Scan the infix expression from left to right.
//  2. If the scanned character is an operand, output it.
//  3. Else,
//  …..3.1 If the scanned character is an ‘(‘, push it to the stack.
//  …..3.2 Else, If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered .
//  …..3.3 Else, pop and output from the stack until an operator with lower precedence than the scanned operator is encountered.
//  …..3.4 Push the scanned operator to the stack.
//  4. If the infix expression is ended, pop and output from the stack until it is empty.

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

// Function to convert an infix expression to a postfix expression
string infixToPostfix(string exp)
{
    string ans;     // Initialize the resulting postfix expression
    stack<char> st; // Initialize a stack to hold operators

    // Iterate through each character in the input expression
    for (char ch : exp)
    {
        // If the character is an operand (letter or digit), add it to the result
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ||
            ch >= '1' && ch <= '9')
        {
            ans += ch;
        }
        // If the character is an opening parenthesis, push it onto the stack
        else if (ch == '(')
        {
            st.push(ch);
        }
        // If the character is a closing parenthesis, pop and add operators from the stack
        // to the result until an opening parenthesis is encountered, then pop the opening parenthesis
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the opening parenthesis from the stack
        }
        // If the character is an operator, pop and add operators from the stack
        // to the result as long as their precedence is greater than or equal to
        // the precedence of the current operator, then push the current operator onto the stack
        else
        {
            while (!st.empty() && getPrecedence(ch) <= getPrecedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // After processing all characters in the input, pop and add any remaining operators from the stack to the result
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans; // Return the final postfix expression
}
