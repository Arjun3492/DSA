// Problem Statement:
//  Given an postfix expression, Your task is to convert the given postfix expression to a prefix expression.

// Video explanation: https://youtu.be/smQ88h1qzQY?si=U69KO7Lt7wtEG7qN

// Example 1:
// Input: postfix = ABC/-AK/L-*
// Output: *-A/BC-/AKL

// Example 2:
// Input: postfix = AB+CD-*
// Output: *+AB-CD

// Steps involved:
//  1. Scan the postfix expression from left to right.
//  2. If the scanned character is an operand, push it onto the stack.
//  3. Else, if the scanned character is an operator, pop two operands from the stack, concatenate them with the operator as [operator operand2 operand1] and push it onto the stack.
//  4. Repeat steps 2 and 3 until the postfix expression is ended.
//  5. Return the top of the stack as the result.

string postfixToPrefix(string &s)
{
    stack<string> st;

    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '1' && ch <= '9')
        {
            // If the character is an operand (letter or digit), create a string from it
            string str;
            str += ch;
            st.push(str); // Push the operand onto the stack
        }
        else
        {
            // If the character is an operator, pop the top two operands from the stack,
            // apply the operator, and push the result back onto the stack
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string rexp = ch + op2 + op1; // Combine the two operands with the operator
            st.push(rexp);                // Push the result back onto the stack
        }
    }

    return st.top(); // The final result on the stack is the prefix expression
}
