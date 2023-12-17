// Longest Repeating Character Replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// link:https://leetcode.com/problems/longest-repeating-character-replacement/

// Examples:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".

// Video:https://youtu.be/yYtaV0G3mWQ?si=l1pyrK5-LZNkOzsp&t=150

int longestRepeatingSubstring(string &str, int k)
{

    // Initialize left and right pointers, maximum count of a character in the window, and the answer
    int l = 0, r = 0;
    int maxCount = 0;
    int ans = 0;

    // Initialize a map to store the count of each character in the window
    unordered_map<char, int> mpp;

    // Iterate through the string using the right pointer
    while (r < str.size())
    {
        // Get the current character
        char currChar = str[r];

        // Increment the count of the current character
        mpp[currChar]++;

        // Update the maximum count of a character in the window
        maxCount = max(maxCount, mpp[currChar]);

        // While the number of characters to be replaced exceeds the allowed replacements (k), move the left pointer
        while (r - l + 1 - maxCount > k)
        {
            // Decrement the count of the left character
            mpp[str[l]]--;

            // Move the left pointer to the next position
            l++;
        }

        // Calculate the current length of the window and update the answer
        ans = max(ans, r - l + 1);

        // Move the right pointer to the next position
        r++;
    }
    return ans;
}