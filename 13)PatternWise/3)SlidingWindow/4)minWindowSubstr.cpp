class Solution
{
private:
    // 🔹 Brute-force approach: generate all substrings and check each one
    // Time: O(n^3), Space: O(n)
    string bruteForce(string s, string t)
    {
        int m = s.size();
        int minL = INT_MAX;
        string ans = "";

        // Try all possible substrings of s
        for (int i = 0; i < m; ++i)
        {
            string temp = "";
            for (int j = i; j < m; ++j)
            {
                temp += s[j]; // build substring from i to j

                // Only check if length is at least t.length()
                if (temp.size() >= t.size() && isIncluded(temp, t))
                {
                    int currLen = j - i + 1;
                    if (currLen < minL)
                    {
                        minL = currLen;
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }

    class Solution
    {
    private:
        // Checks if current window contains all required characters with required frequency
        bool containsAllChars(const vector<int> &windowFreq, const vector<int> &targetFreq)
        {
            for (int i = 0; i < 128; i++)
            {
                // if freq of any char in target is greater than in window
                // then window does not contain all chars
                if (targetFreq[i] > windowFreq[i])
                    return false;
            }
            return true;
        }

    public:
        string minWindow(string s, string t)
        {
            int sLen = s.size();
            int tLen = t.size();
            if (sLen < tLen)
                return "";

            // using frequency vectors to better track inclusion of characters
            vector<int> targetFreq(128, 0); // Frequency of characters in t
            vector<int> windowFreq(128, 0); // Frequency of characters in current window

            // Count frequency of characters in t
            for (char ch : t)
                targetFreq[ch]++;

            int left = 0;
            int minLen = INT_MAX;
            int startIdx = 0;

            // Expand window with right pointer
            for (int right = 0; right < sLen; right++)
            {
                // Add current character to the window & update its frequency
                char chRight = s[right];
                windowFreq[chRight]++;

                // if window valid,shrink window from left
                // also check for minimum length
                while (containsAllChars(windowFreq, targetFreq))
                {

                    // Update minimum length if current window is smaller
                    int windowLen = right - left + 1;
                    if (windowLen < minLen)
                    {
                        minLen = windowLen;
                        startIdx = left; // Save the start index of this window
                    }

                    // Shrink window by removing left character and reducing its frequency
                    char chLeft = s[left];
                    windowFreq[chLeft]--;
                    left++;
                }
            }

            return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
        }
    };

public:
    // Public interface
    string minWindow(string s, string t)
    {
        // return bruteForce(s, t);  // ← Use this for brute force all substrings
        return optimal(s, t); // ← Use this for improved brute with sliding window
    }
};
