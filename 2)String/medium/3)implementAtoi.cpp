//  Implement Atoi Function

// Problem statement:
// You are given a string ‘s’ of length 'n'.
// Implement the atoi(string s) function, which converts a given string into a 32-bit signed integer,
// following similar principles as the atoi function in C/C++.

// Link:https://www.codingninjas.com/studio/problems/implement-atoi-function_981270

// Approach :
// We use a long long variable ans to store the result.
// We use a variable i to iterate over the string s.
// We skip the leading spaces.
// We check if the first non-whitespace character is a digit or a sign.
// If it is a sign, then we check if it is a negative sign and increment the index i.
// We iterate over the string and check if the current character is a digit.
// If it is a digit, then we add it to the ans.
// We check for overflow.
// If the sign is negative, we multiply the ans by -1 and check for overflow.
// We return the ans.
// Time complexity: O(n)
// Space complexity: O(1)

#include <bits/stdc++.h>
int createAtoi(string s)
{

  long long ans = 0;
  int n = s.size(), i = 0;
  bool isNeg = false;

  // skipping the leading spaces
  while (s[i] == ' ')
    i++;

  // if the first non-whitespace character is not a digit or a sign then return 0
  if ((s[i] != '+' && s[i] != '-' && (s[i] < '0' && s[i] > '9')))
    return 0;

  // If the first non-whitespace character is a sign, then check if it is a negative sign
  // also increment the index ,to start the while loop from the next character
  if ((s[i] == '+' || s[i] == '-'))
  {
    if (s[i] == '-')
      isNeg = true;
    i++;
  }

  while (i < n)
  {
    // if the current character is a digit, then add it to the ans
    if ((s[i] >= '0' && s[i] <= '9'))
    {
      ans = ans * 10 + (int(s[i]) - '0');
      i++;

      // checking for overflow
      if (ans > INT_MAX)
        return INT_MAX;
    }
    else
    {
      // breaking the loop if the current character is not a digit
      break;
    }
  }
  if (isNeg)
  {
    ans *= -1;
    // checking for overflow
    if (ans < INT_MIN)
      return INT_MIN;
  }
  return ans;
}