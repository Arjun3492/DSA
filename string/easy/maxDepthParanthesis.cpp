//Problem Statement

//Return the maximum depth of the parenthesis in the given string.


//Optimal Approach
//We use a variable count to keep track of the opening and closing parenthesis
//We use a variable ans to store the maximum depth of the parenthesis
//We iterate through the string and whenever we encounter a '(' we increment count  and update ans to max(ans,count)
//And whenever we encounter a ')' we decrement count
int maxDepth(string s) {

  // Write your code here.

  int count = 0;

  int ans = INT_MIN;

  for (int i : s) {

    if (i == '(') {
      count++;
      ans = max(ans, count);
    }

    else if (i == ')')
      count--;
  }

  return ans;
}
