// Problem Statement:
// Given an prefix expression, Your task is to convert the given prefix expression to a postfix expression.

// Video explanation: https://youtu.be/jZxII0guwUo?si=jghmM-vML8pXhMPW

// Example 1:
// Input: prefix = *-A/BC-/AKL
// Output: ABC/-AK/L-*

// Example 2:
// Input: prefix = *+AB-CD
// Output: AB+CD-*

// Steps involved:
//  1. Scan the prefix expression from right to left.
//  2. If the scanned character is an operand, add it to the stack.
//  3. Else, if the scanned character is an operator, pop two operands from the stack, concatenate them with the operator as [operand1 operand2 operator ]and add it to the stack.
//  4. Repeat steps 2 and 3 until the prefix expression is ended.
//  5. Return the top of the stack as the result.

// Function to convert a prefix expression to a postfix expression
string preToPost(string s)
{

    stack<string> st; // Initialize a stack to hold operands and intermediate results

    for (int i = s.size() - 1; i > -1; i--)
    {
        char ch = s[i];

        // If the character is an operand (letter or digit), create a string from it
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ||
            ch >= '1' && ch <= '9')
        {
            string str;
            str += ch;
            st.push(str); // Push the operand onto the stack
        }
        // Else If the character is an operator, pop the top two operands from the stack,
        //  apply the operator, and push the result back onto the stack
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string rexp = op1 + op2 + ch; // Combine the two operands with the operator
            st.push(rexp);                // Push the result back onto the stack
        }
    }

    return st.top(); // The final result on the stack is the postfix expression
}
