// 316. Remove Duplicate Letters

// https://leetcode.com/problems/remove-duplicate-letters

class Solution
{
private:
    /*
         Intuition:
        - We want the smallest lexicographical string that contains each character exactly once.
        - First, we record the **last occurrence** of each character in the string.
        - Then we iterate through the string and use a **monotonic increasing stack** to build the result.
        - If the current character is **smaller** than the character on top of the stack,
          and that top character will appear again later (based on last occurrence),
          then we can safely **pop** it from the stack and use the current character instead for a better lexicographical result.
        - We also use a **set** (`seen`) to make sure we include each character **only once** in the result.

        TC: O(n)
    */

    string optimal(string s)
    {
        int n = s.size();
        vector<int> lastOccurence(26, -1);

        // Step 1: Record last occurrence index of each character
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            lastOccurence[ch - 'a'] = i;
        }

        stack<char> st; // Stack to build the result string (maintaining lexicographic order)
        set<char> seen; // Set to track which characters are already in the stack

        // Step 2: Traverse through the string
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            // Skip the character if it's already been added to the stack
            if (seen.count(ch) > 0)
                continue;

            /*
                We pop characters from the stack if:
                - The current character is smaller than the stack's top (for lexicographic improvement)
                - The top character appears later again in the string (so it's safe to remove it now)
            */
            while (!st.empty() && ch < st.top() && lastOccurence[st.top() - 'a'] > i)
            {
                seen.erase(st.top()); // Mark that the popped character can be added again later
                st.pop();             // Remove the top for a better lexicographical choice
            }

            st.push(ch);     // Push current character to the stack
            seen.insert(ch); // Mark it as seen
        }

        // Step 3: Construct final string from characters in stack
        string ans = "";
        while (!st.empty())
        {
            char ch = st.top();
            ans = ch + ans; // Prepend to maintain correct order
            st.pop();
        }

        return ans;
    }

public:
    string removeDuplicateLetters(string s)
    {
        return optimal(s);
    }
};
