// Problem Statement:
//  Given an prefix expression, Your task is to convert the given prefix expression to a infix expression.

// Video explanation: https://youtu.be/U7ATLzWGsbE?si=-GYQJ16iKFHd_9Pa

// Example 1:
// Input: prefix = *-A/BC-/AKL
// Output: ((A-(B/C))*((A/K)-L))

// Example 2:
// Input: prefix = *+AB-CD
// Output: ((A+B)*(C-D))

// Steps involved:
//  1. Scan the prefix expression from right to left.
//  2. If the scanned character is an operand, add it to the result.
//  3. Else, if the scanned character is an operator, pop two operands from the stack, concatenate them with the operator and add it to the result.
//  4. Repeat steps 2 and 3 until the prefix expression is ended.

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

// Function to convert an prefix expression to a infix expression
string prefixToInfix(string exp)
{
    stack<string> st; // Initialize a stack to hold operands

    // Iterate through each character in the input expression
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        // If the character is an operand (letter or digit), add it to the result
        if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' ||
            exp[i] >= '1' && exp[i] <= '9')
        {
            string s;
            s += exp[i];
            st.push(s);
        }
        // If the character is an operator
        else
        {
            // Pop two operands from the stack
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            // Concatenate the operands and operator in the correct order
            string temp = "(" + op1 + exp[i] + op2 + ")";

            // Push the result onto the stack
            st.push(temp);
        }
    }

    // The stack now contains the infix expression
    return st.top();
}
