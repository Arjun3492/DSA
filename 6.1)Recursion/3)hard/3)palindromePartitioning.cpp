// Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Link :https://leetcode.com/problems/palindrome-partitioning/

// Intuition : We can solve this problem using backtracking.
// For each possible position to split the string, we will check if the current substring is a palindrome or not.
// If it is a palindrome then we will add the current substring to the current partition and move to the next position.
// If we are able to partition the string into palindromes then we will add the current partition to the result.

// Solution

class Solution
{
public:
    void partitionHelper(int partPos, string s, vector<string> &ds,
                         vector<vector<string>> &ans)
    {
        if (partPos == s.size()) // if we have reached the end of the string
        {
            ans.push_back(ds);
            return;
        }
        for (int i = partPos; i < s.size(); ++i)
        {
            if (isPalindrome(s, partPos, i)) // if the current substring is a palindrome
            {
                ds.push_back(s.substr(partPos, i - partPos + 1)); // add the current substring to the current partition
                partitionHelper(i + 1, s, ds, ans);               // move to the next position
                ds.pop_back();                                    // backtracking
            }
        }
    }

    bool isPalindrome(string s, int start, int end) // checking if the current substring is a palindrome
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        partitionHelper(0, s, ds, ans);
        return ans;
    }
};
