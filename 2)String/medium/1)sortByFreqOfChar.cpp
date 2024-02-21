// Sorting Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

// Link: https://www.codingninjas.com/studio/problems/sorting-characters-by-frequency_1263699

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"

// Approach 1
// We use a frequency array/map to store the count of every letter of the string s
// We use a vector of pairs to store the letter and its count.
// We sort the vector of pairs in decreasing order of the count of every letter.
// We iterate over the vector of pairs and append the letter to the string ans count number of times.
// Time complexity: O(nlogn)
// Space complexity: O(n)

string sortByFrequency(int n, string &s)
{
  map<char, int> mpp;
  for (char ch : s)
  {
    mpp[ch]++;
  }
  vector<pair<char, int>> vec(mpp.begin(), mpp.end());

  sort(vec.begin(), vec.end(), greater<pair<char, int>>());
  s = "";
  for (auto i : vec)
  {
    while (i.second > 0)
    {
      s = s + i.first;
      i.second--;
    }
  }
  return s;
}

// Approach 2
// We use a frequency array to store the count of every letter of the string s.
// We use a priority queue to store the frequency of every letter of the string s.
// We iterate over the priority queue and append the letter to the string ans count number of times.
// Time complexity: O(nlogn)
// Space complexity: O(n)
string frequencySort(string s)
{
  vector<int> freq(256, 0);
  for (char ch : s)
  {
    freq[ch]++;
  }
  priority_queue<pair<int, char>> pq;
  for (int i = 0; i < 256; i++)
  {
    if (freq[i] == 0)
    {
      continue;
    }
    pq.push({freq[i], i});
  }
  string ans = "";
  while (!pq.empty())
  {
    int count = pq.top().first;
    char ch = pq.top().second;
    pq.pop();
    ans += string(count, ch);
  }
  return ans;
}
