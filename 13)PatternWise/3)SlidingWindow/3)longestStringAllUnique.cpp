class Solution
{
private:
    // BRUTE FORCE METHOD
    // Time: O(n^3), Space: O(n)
    // Try all substrings and check if they have unique characters
    int brute(string s)
    {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                unordered_set<char> seen;
                bool allUnique = true;

                for (int k = i; k <= j; ++k)
                {
                    if (seen.count(s[k]))
                    {
                        allUnique = false;
                        break;
                    }
                    seen.insert(s[k]);
                }

                if (allUnique)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }

    // OPTIMAL METHOD (Sliding Window)
    // Time: O(n), Space: O(min(n, charset)) ~ O(1) for ASCII
    // Use a sliding window and hash set to track characters in the window
    int optimal(string s)
    {
        unordered_set<char> seen;
        int left = 0, right = 0, maxLen = 0, n = s.size();

        while (right < n)
        {
            if (!seen.count(s[right]))
            {
                // Expand the window
                seen.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            else
            {
                // Shrink the window from the left
                seen.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }

public:
    // Use this to test either method
    int lengthOfLongestSubstring(string s)
    {
        // return brute(s);   // Uncomment to use brute force
        return optimal(s); // Default: optimal approach
    }
};
