// Isomorphic strings
// Problem:Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Link:https://www.codingninjas.com/studio/problems/isomorphic-strings-_1117636

// That is there must be one to one mapping between the characters of both the strings
// We can use a hashmap to store the mapping of the characters of str1 to str2
// If we encounter a character in str1 that has already been mapped to a different character in str2 then we return false
// Else we return true

// Approach using hashmaps
// we create two hashmaps mpp1 and mpp2
// In mpp1 we store the mapping of the characters of str1 to str2
// In mpp2 we store the mapping of the characters of str2 to str1
// We first find if the length of both the strings is same or not
// If not we return false
// else

// We check if the current character in str1 is already present in mpp1 or not
// If it is present then we check if the character mapped to it is same as the current character in str2
// If it is same then we continue
// Else we return false
// If the current character in str1 is not present in mpp1 then we add it to mpp1

// Similarly we check if the current character in str2 is already present in mpp2 or not
// If it is present then we check if the character mapped to it is same as the current character in str1
// If it is same then we continue
// Else we return false
// If the current character in str2 is not present in mpp2 then we add it to mpp2

// After the loop ends we return true

bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    map<char, char> mpp1;
    map<char, char> mpp2;
    int n = str1.size();
    int m = str2.size();
    if (n != m)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (mpp1.find(str1[i]) != mpp1.end())
        {
            if (mpp1[str1[i]] != str2[i])
            {
                return false;
            }
        }
        else
        {
            mpp1[str1[i]] = str2[i];
        }
        if (mpp2.find(str2[i]) != mpp2.end())
        {
            if (mpp2[str2[i]] != str1[i])
            {
                return false;
            }
        }
        else
        {
            mpp2[str2[i]] = str1[i];
        }
    }
    return true;
}

// Optimal approach
// We use two vectors of size 256 and initialize them to 0
// We iterate through the strings and check if the current character in str1 is mapped to the same character in str2
// using the index value of the current iteration
// If it is mapped to the same character then we continue

bool areIsomorphic(string &s, string &t)
{
    if (s.size() != t.size())
        return false;

    int mp1[256] = {0}, mp2[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {

        if (mp1[s[i]] != mp2[t[i]])
            return false;
        // mapping the characters of s to t using same index value,by inserting the index value of the current iteration
        // at the ascii value index of the character in the vector
        // this way if the character of s  is already mapped to an index we can check if the character of t is mapped to the same index
        // if not we return false,meaning previously either of these elements were mapped to a diff element
        mp1[s[i]] = mp2[t[i]] = i + 1;
    }
    return true;
}