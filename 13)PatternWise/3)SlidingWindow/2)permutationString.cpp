// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string

class Solution
{
private:
    bool slidingWindowApproach(string s1, string s2)
    {
        // Time: O(n), Space: O(1)
        // n = length of s2, since we scan it once with a fixed-size frequency array
        // Space is O(1) because we use only two arrays of size 26 (constant space)

        if (s1.size() > s2.size())
            return false;

        // Frequency maps for s1 and current window in s2
        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequencies of s1 and the first window of s2
        for (int i = 0; i < s1.size(); ++i)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Check if initial window is a match
        if (freq1 == freq2)
            return true;

        // Start sliding the window
        for (int i = s1.size(); i < s2.size(); ++i)
        {
            // Include the new char in window
            freq2[s2[i] - 'a']++;
            // Remove the char going out of window
            freq2[s2[i - s1.size()] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        return slidingWindowApproach(s1, s2);
    }
};
