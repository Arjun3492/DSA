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
// We will have two choices for each element in the array:
// 1. We can include the element in the subset.
// 2. We can exclude the element from the subset.
// When we include the element in the subset, we will make a recursive call with the next index and the updated subset.
// When we exclude the element from the subset, we will make a recursive call with the next index and the same subset.
// We will add the subset to the ans vector when we reach the end of the array.(base condition)

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