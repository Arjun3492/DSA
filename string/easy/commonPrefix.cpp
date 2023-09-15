//Problem:Find the common prefix in the given array of strings
//Example:
//Input: arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"}
//Output: "gee"
//Explanation: Longest common prefix of all the strings is "gee".
//


//Optimal Approach
//We sort the array of strings(lexicographically sorted array of strings will have the common prefix at the first and last string,if any)
//We take the first and last string and compare them character by character
//If the characters are same we add them to the ans string
//If the characters are not same we return the ans string
//If we reach the end of the loop we return the ans string

string commonPrefix(vector<string> &arr, int n) {
  // Write your code here
  string ans = "";
  sort(arr.begin(), arr.end());
  string first = arr[0];
  string last = arr[n - 1];

  int a = min(first.size(), last.size());

  for (int i = 0; i < a; i++)
  {
    if (first[i] != last[i])
    {
      if (ans == "")

        return "-1";

      return ans;
    }

    ans += first[i];
  }

  return ans;
}
