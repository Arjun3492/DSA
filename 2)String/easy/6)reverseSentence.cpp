// Reverse Words In A String
// Problem statement
// Given a string sentence,you have to reverse the order of the words in the sentence and remove extra spaces if any

// Link :https://www.codingninjas.com/studio/problems/reverse-words-in-a-string_696444

// INTUITION:
// We use a string word to store the current word and a string ans to store the final answer
// Once we encounter a space we add the word to the ans and reset the word to ""(so that in case of extra spaces we don't add the word to the ans again)
// At the end we check if the word is not empty then we add it to the ans (since the last word might  not have a space after it)
// Return the ans

// Time complexity : O(n)
// Space complexity : O(n) //to store the ans

string reverseString(string &str)
{
  string word = "";
  string ans = "";

  for (char i : str)
  {
    if (i == ' ')
    {
      if (word.length() > 0)
      {
        ans = word + " " + ans;
        word = "";
      }
    }
    else
    {
      word += i;
    }
  }
  if (word.length() > 0)
    ans = word + " " + ans;
  return ans;
}