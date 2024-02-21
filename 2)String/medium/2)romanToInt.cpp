// Roman Numeral To Integer

// Given a string A representing a roman numeral.
// Convert A into integer.

// Link:https://www.codingninjas.com/studio/problems/roman-numeral-to-integer_981308

// Approach
// We use a map to store the value of every roman numeral.
// We iterate over the string and check if the current roman numeral is less than the next roman numeral.
// If it is less, then we subtract the value of the current roman numeral from the ans.
// If it is not less, then we add the value of the current roman numeral to the ans.
// Time complexity: O(n)
// Space complexity: O(n)

int romanToInt(string s)
{
    int ans = 0;
    int n = s.size();
    map<char, int> mpp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1 && mpp[s[i]] < mpp[s[i + 1]]) // since in roman numeral if the current roman numeral is less than the next roman numeral then we subtract the value of the current roman numeral from the ans.
            ans -= mpp[s[i]];                        // eg IV = 4 = 5-1
        else
            ans += mpp[s[i]];
    }
    return ans;
}
