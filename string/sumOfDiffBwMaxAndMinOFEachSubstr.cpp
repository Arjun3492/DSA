// Problem Statement
// Beauty Of String:Difference between frequency of maximum and minimum occurring characters in a string
// Find the sum of beauty of all substrings of a given string.

// Approach 1: Brute force
// We use a nested for loop to iterate over all the substrings of the string s.
// We use a frequency array/hashmap to store the count of every letter of the substring.
// We use a variable maxFreq to store the maximum frequency of any letter of the substring.
// We use a variable minFreq to store the minimum frequency of any letter of the substring.
// We iterate over the hashMap and update the maxFreq and minFreq.
// We add the difference between maxFreq and minFreq to the answer.
// Time complexity: O(n^3)
// Space complexity: O(n)
// where n is the length of the string s.
int sumOfBeauty(string s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> letterCount(26, 0);
        for (int j = i; j < n; j++)
        {
            letterCount[s[j] - 'a']++;
            int maxFreq = INT_MIN;
            int minFreq = INT_MAX;
            for (int k : letterCount)
            {
                maxFreq = max(maxFreq, k);

                if (k >= 1)
                {
                    minFreq = min(minFreq, k);
                }
            }
            sum += (maxFreq - minFreq);
        }
    }
    return sum;
}
