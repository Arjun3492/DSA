// Problem Statement: Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:
// Input: s = "cbbd"

// Approach 1: Brute force
// We use a nested for loop to iterate over all the substrings of the string s.
// We use a function isPalindrome to check if the substring is a palindrome or not.
// We use a variable ans to store the longest palindromic substring.
// We iterate over the string s and check if the substring is a palindrome or not.
// If the substring is a palindrome, we check if the length of the substring is greater than the length of the longest palindromic substring.
// If the length of the substring is greater than the length of the longest palindromic substring, we update the longest palindromic substring.
// Time complexity: O(n^3)
// Space complexity: O(1)
// where n is the length of the string s.
bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
string longestPalindrome(string s)
{
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            string sub = s.substr(i, j);
            if (isPalindrome(sub))
            {
                if (sub.length() > ans.length())
                {
                    ans = sub;
                }
            }
        }
    }
    return ans;
}

// Approach 2: Using expand around center
// We use a nested for loop to iterate over all the characters of the string s.
// We use a function expandAroundCenter to find the longest palindromic substring with the center at the current character.
// We use a variable ans to store the longest palindromic substring.
// We iterate over the string s and find the longest palindromic substring with the center at the current character.
// If the length of the substring is greater than the length of the longest palindromic substring, we update the longest palindromic substring.
// Time complexity: O(n^2)
// Space complexity: O(1)
// where n is the length of the string s.
string expandAroundCenter(string s, int left, int right)
{
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right])
    {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}
string longestPalindrome(string s)
{
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        // For odd length palindromes, we consider the center as the middle character.
        string odd = expandAroundCenter(s, i, i);
        // For even length palindromes, we consider the center as the space between the two middle characters.
        string even = expandAroundCenter(s, i, i + 1);

        if (odd.length() > ans.length())
        {
            ans = odd;
        }
        if (even.length() > ans.length())
        {
            ans = even;
        }
    }
    return ans;
}

// Same approach as above but with a different implementation
string longestPalindrome(string s)
{
    int n = s.length();
    int start = 0, end = 1;
    int low, hi;

    // Traverse the input string
    for (int i = 0; i < n; i++)
    {

        // Find longest palindromic substring of even size
        low = i - 1;
        hi = i;

        // Expand substring while it is palindrome
        // and in bounds
        while (low >= 0 && hi < n && s[low] == s[hi])
        {

            // Update maximum length and starting index
            if (hi - low + 1 > end)
            {
                start = low;
                end = hi - low + 1;
            }
            low--;
            hi++;
        }

        // Find longest palindromic substring of odd size
        low = i - 1;
        hi = i + 1;

        // Expand substring while it is palindrome
        // and in bounds
        while (low >= 0 && hi < n && s[low] == s[hi])
        {

            // Update maximum length and starting index
            if (hi - low + 1 > end)
            {
                start = low;
                end = hi - low + 1;
            }
            low--;
            hi++;
        }
    }
    return s.substr(start, end);
}

// Can also be done using DP
// Refer file: DP/longestPalindromicSubstr.cpp
