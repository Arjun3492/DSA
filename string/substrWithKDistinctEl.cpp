// Problem statement:Find the number of substrings with exactly k distinct characters

// Approach 1: Brute force
// We iterate over all the substrings of the string s and check if the number of distinct characters in the substring is equal to k or not.
// Working:
// We use a nested for loop to iterate over all the substrings of the string s.
// We use a frequency array/hashmap to store the count of every letter of the substring.
// We use a variable distinct_elements to store the number of distinct characters in the substring.
// We iterate over the substring and check if the count of the letter is 0 or not. If it is 0, we increment distinct_elements by 1.
// We check if distinct_elements is equal to k or not. If it is equal to k, we increment ans by 1.

// Time complexity: O(n^2)
// Space complexity: O(n)
int countSubStrings(string str, int k)
{
    int n = str.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int distinct_elements = 0;
        // Initialize the frequency array/hashmap with 0 for each alphabet
        int letterHash[26] = {0};
        for (int j = i; j < n; j++)
        {
            //  if the count of the letter is 0(meaning a new distinct el is encountered),
            //  we increment distinct_elements by 1 and set the count of the letter to 1.

            if (letterHash[str[j] - 'a'] == 0)
            {
                letterHash[str[j] - 'a'] = 1;
                distinct_elements++;
            }

            if (distinct_elements == k)
            //  if distinct_elements is equal to k, we increment ans by 1.
            {
                ans++;
            }
            else if (distinct_elements > k)
            //  if distinct_elements is greater than k, we break out of the inner loop,
            // because the number of distinct elements in the bigger substrings  will always be greater than k.
            // eg: if k=2, and the substring is "abc", the number of distinct elements in the substring "abc" is 3,
            // so substrings like "abcde" will also have >2 distinct elements.
            {
                break;
            }
        }
    }
    return ans;
}