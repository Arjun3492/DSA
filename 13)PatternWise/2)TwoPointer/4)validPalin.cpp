// 125. Valid Palindrome

// https://leetcode.com/problems/valid-palindrome

class Solution
{

private:
    // We find do both the straight and reverse of the string
    //  and compare them
    bool brute(string s)
    {
        string straight = "", reverse = "";
        for (char ch : s)
        {
            ch = tolower(ch);
            if (isalnum(ch)) // utility method to check if character is alphanumeric
            {
                straight = straight + ch;
                reverse = ch + reverse;
            }
        }
        return straight == reverse;
    }

    bool optimal(const std::string &s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            // Move left to next alphanumeric
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            // Move right to previous alphanumeric
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }

            // Compare characters case-insensitively
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }

public:
    bool isPalindrome(string s)
    {
        return optimal(s);
    }
};