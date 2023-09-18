//Check If One String Is A Rotation Of Another String
//https://leetcode.com/problems/rotate-string/
//Description: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
//A shift on s consists of moving the leftmost character of s to the rightmost position.
//Example 1:
//Input: s = "abcde", goal = "cdeab"
//Output: true
//Example 2:
//Input: s = "test", goal = "estt"
//Output: false

//Approach 1: Brute Force
//We use the substr method to generate all possible rotations of the string s. For each rotation, we check if it is equal to the string goal.
//Time complexity: O(n^2) (complexity of substr method is O(n) and we are calling it n times)

int isCyclicRotation(string &p, string &q) {
  int n = p.size();
  bool isPossible = false;
  for (int i = n - 1; i >= 0; i--) {
    string tmp = p.substr(i) + p.substr(0, i);
    if (tmp == q) {
      isPossible = true;
      break;
    }
  }
  if(isPossible)return 1;
  else return 0;
}


//Optimized Approach
//Time complexity: O(n)
//Space complexity: O(n)
//We concatenate the string s with itself and check if the string goal is a substring of the concatenated string.
//If it is a substring, then it is a rotation of the string s.
//Example: s = "abcde", goal = "cdeab"
//Concatenated string: s1 = "abcdeabcde"
//Substring: "cdeab" is present in s1
//Hence, "cdeab" is a rotation of "abcde"


int isCyclicRotation(string &p, string &q) {
  return (p.size()==q.size()) && 
  ((p+p).find(q)!=std::string::npos);
  //find returns the position of the first occurrence of substring q in the string p+p
  //if the substring is not found, it returns string::npos
    //npos is a static member constant value with the greatest possible value for an element of type size_t.
 
}


