#include <bits/stdc++.h>
int createAtoi(string s) {

  long long ans = 0;
  int n = s.size(), i = 0;
  bool isNeg = false;

    //skipping the leading spaces
  while (s[i] == ' ') {
    i++;
  }
  //if the first non-whitespace character is not a digit or a sign then return 0
  if ((s[i] != '+' && s[i] != '-' && (s[i] < '0' && s[i] > '9'))) {
    return 0;
  }
    //if the first non-whitespace character is a sign, then check if it is a negative sign
    //also increment the index ,to start the while loop from the next character
  if ((s[i] == '+' || s[i] == '-')) {
    if (s[i] == '-')
      isNeg = true;
    i++;
  }

  while (i < n) {
    //if the current character is a digit, then add it to the ans
    if ((s[i] >= '0' && s[i] <= '9')) {
      ans = ans * 10 + (int(s[i]) - '0');
      //checking for overflow
      if (ans > INT_MAX)
        return INT_MAX;
    } else {
    //breaking the loop if the current character is not a digit
      break;
    }
    i++;
  }
  if (isNeg) {
    ans *= -1;
    //checking for overflow
    if (ans < INT_MIN)
      return INT_MIN;
  }
  return ans;
}