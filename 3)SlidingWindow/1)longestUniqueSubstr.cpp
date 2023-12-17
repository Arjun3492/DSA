// Length of Longest Substring without any Repeating Character
// Problem Statement: Given a string, find the length of the longest substring without repeating characters.

// Video:https://youtu.be/qtVh-XEpsJo?si=87fcgv9VZnnO0n7x&t=848

// Examples:
// Input : "abcabcbb"
// Output : 3
// Explanation : The answer is "abc", with the length of 3.

// Input : "bbbbb"
// Output : 1
// Explanation : The answer is "b", with the length of 1.

// Approach :Sliding window with set
//  Time complexity:O(n)
//  Space complexity:O(n)

int uniqueSubstrings(std::string input)
{
    // Create a set to store the characters of the current window
    std::set<char> st;

    // Get the size of the input string
    int n = input.size();

    // Initialize left and right pointers and the answer variable
    int left = 0, right = 0;
    int ans = 0;

    // Iterate through the string using the right pointer
    while (right < n)
    {
        // Get the current character
        char ch = input[right];

        // Check if the current element already exists in the set
        if (st.find(ch) != st.end())
        {
            // If yes, remove the elements from the set until the current character is removed
            while (st.find(ch) != st.end())
            {
                st.erase(input[left]);
                left++;
            }
        }

        // Add the current character to the set
        st.insert(ch);

        // Calculate the current length of the substring
        int currLen = right - left + 1;

        // Update the answer if the current length is greater than the previous maximum
        ans = std::max(ans, currLen);

        // Move the right pointer to the next position
        right++;
    }

    // Return the final answer
    return ans;
}

// Better Approach: Sliding Window with map
int uniqueSubstrings(std::string input)
{
    // Create a map to store the last seen index of each character
    std::map<char, int> mpp;

    // Get the size of the input string
    int n = input.size();

    // Initialize left and right pointers and the answer variable
    int left = 0, right = 0;
    int ans = 0;

    // Iterate through the string using the right pointer
    while (right < n)
    {
        // Get the current character
        char ch = input[right];

        // Check if the current element already exists in the map
        if (mpp.find(ch) != mpp.end())
        {
            // If yes, update the left pointer to the next position after the last occurrence of the current character
            left = std::max(mpp[ch] + 1, left);
        }

        // Update the last seen index of the current character in the map
        mpp[ch] = right;

        // Calculate the current length of the substring
        int currLen = right - left + 1;

        // Update the answer if the current length is greater than the previous maximum
        ans = std::max(ans, currLen);

        // Move the right pointer to the next position
        right++;
    }

    // Return the final answer
    return ans;
}