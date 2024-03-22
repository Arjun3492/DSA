// Get Subsequences
//  Problem statement
//  Given a string 'S' of length 'N', return all the subsequences of the given string.
//  A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.
//  Note :
//  You may return the subsequences in any order but they will be printed in lexicographically ascending order.
//  If a string from the returned array has a length of zero, it will be represented as 'Empty String' in the output.

// For Example:
// S = "abc"
// The subsequences of the given string are: ["", "a", "ab", "abc", "ac", "b", "bc", "c"]
// The subsequences are printed in lexicographically ascending order.

// Link : https://www.codingninjas.com/studio/problems/print-subsequences_8416366

// Intuition
// We will have two choices for each character in the string
// 1. we can include it in the subsequence.
// 2. we can exclude it from the subsequence.
// We will make a recursive call for both the choices and keep track of the current subsequence.
// We will keep adding the current subsequence to the answer whenever we reach the end of the string.

// Approach
// 1. Create a vector of strings to store the answer.
// 2. Create a helper function that will take the current index, the input string, and the current subsequence as arguments.
// 3. If the current index is equal to the length of the input string, add the current subsequence to the answer.
// 4. Otherwise, make two recursive calls:
//    a. Include the current character in the subsequence and make a recursive call with the next index.
//    b. Exclude the current character from the subsequence and make a recursive call with the next index.
// 5. Return the answer.

// Time complexity: O(2^n)
// Space complexity: O(2^n) [stack space]

void generateSubsequencesHelper(int index, string s, string subSeq,
                                vector<string> &ans)
{
    // Base condition
    if (index >= s.size())
    {
        ans.push_back(subSeq); // pushing the generated subsequence to ans vector
        return;
    }
    getSubsequencesRec(index + 1, s, subSeq + s[index], ans); // taking s[index]

    getSubsequencesRec(index + 1, s, subSeq, ans); // removing s[index]
}

vector<string> generateSubsequences(string s)
{
    vector<string> ans;
    generateSubsequencesHelper(0, s, "", ans);
    return ans;
}