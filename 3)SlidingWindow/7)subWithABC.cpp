// Count Substring With abc
// Problem statement:You are given a string s containing only lowercase English letters. Find the number of substrings which contains at least one occurrence of the characters 'a', 'b' and 'c'.

// Examples:
// Input: s = "abcabc"
// Output: 15
// Explanation: The substrings containing at least one occurrence of the characters 'a', 'b' and 'c' are "a", "ab", "abc", "abca", "abcab", "abcabc", "b", "bc", "bca", "bcab", "bcabc", "c", "ca", "cab" and "cabc".

int countSubstringWithABC(string s)
{
    int l = 0, r = 0;
    int ans = 0;
    int n = s.size();
    int countA = 0, countB = 0, countC = 0;
    while (r < n)
    {
        char currChar = s[r];
        if (currChar == 'a')
        {
            countA++;
        }
        else if (currChar == 'b')
        {
            countB++;
        }
        else if (currChar == 'c')
        {
            countC++;
        }
        while (countA > 0 && countB > 0 && countC > 0)
        {
            char leftChar = s[l];
            if (leftChar == 'a')
            {
                countA--;
            }
            else if (leftChar == 'b')
            {
                countB--;
            }
            else if (leftChar == 'c')
            {
                countC--;
            }
            l++;
        }
        ans += l;
        r++;
    }
    return ans;
}
