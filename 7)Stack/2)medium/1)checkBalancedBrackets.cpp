// Problem Statement: Check Balanced Parentheses.
// Given string str containing just the characters ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘ and ‘]’,
// check if the input string is valid and return true if the string is balanced otherwise return false.

// Example 1:
// Input: str = “( )[ { } ( ) ]”
// Output: true
// Explanation: The string is balanced as all the parentheses are closed in the correct order.

// Link : https://www.naukri.com/code360/problems/balanced-parentheses_8162202

// Solution:
// When we encounter an opening parenthesis, we push it onto the stack.
// When we encounter a closing parenthesis, we check if it matches the corresponding top of the stack(Opening bracket).
// If it doesn’t match, we return false.
// If it matches, we pop the top of the stack and continue processing the string.
// If the stack is empty after processing all characters, it means all parentheses are balanced and we return true.
// If the stack is not empty, it means there’s an opening parenthesis without a matching closing parenthesis and we return false.

// Time complexity: O(n)
// Space complexity: O(n)
bool isValidParenthesis(string s)
{
    // Initialize a stack to keep track of open parentheses
    stack<char> check;

    // If the string is empty, it's considered balanced
    if (s == "")
        return true;

    // Iterate through each character in the input string
    for (char ch : s)
    {
        // If the character is an open parenthesis, push it onto the stack
        if (ch == '[' || ch == '(' || ch == '{')
        {
            check.push(ch);
        }
        else
        {
            // If the character is a closing parenthesis, we need to check if it matches the top of the stack
            // If the stack is empty, it means there's no matching open parenthesis, so return false
            if (check.empty())
                return false;

            // Check for matching pairs of parentheses and pop the open parenthesis from the stack
            if (ch == ']')
            {
                bool isPresent = check.top() == '[';
                if (!isPresent)
                    return false;
                check.pop();
            }
            else if (ch == ')')
            {
                bool isPresent = check.top() == '(';
                if (!isPresent)
                    return false;
                check.pop();
            }
            else
            {
                bool isPresent = check.top() == '{';
                if (!isPresent)
                    return false;
                check.pop();
            }
        }
    }

    // If the stack is empty after processing all characters, it means all parentheses are balanced
    return check.empty();
}
