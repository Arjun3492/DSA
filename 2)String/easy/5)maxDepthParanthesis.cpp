//  Maximum Nesting Depth Of The Parentheses

// Problem Statement
// Return the maximum depth of the parenthesis in the given string.

// LINK : https://www.codingninjas.com/studio/problems/maximum-nesting-depth-of-the-parentheses_8144741

// Optimal Approach
// We use a variable count to keep track of the opening and closing parenthesis
// We use a variable ans to store the maximum depth of the parenthesis
// We iterate through the string and whenever we encounter a '(' we increment count  and update ans to max(ans,count)
// And whenever we encounter a ')' we decrement count
// Time complexity : O(n)
// Space Complexity :O(1)

int maxDepth(string s)
{

  int count = 0;

  int ans = INT_MIN;

  for (char i : s)
  {

    if (i == '(')
    {
      count++;
      ans = max(ans, count);
    }

    else if (i == ')')
      count--;
  }

  return ans;
}
