// Subsequences of String(Power Set)
// Problem statement:Given a string, print all subsequences of the given string.

// eg:abc
// output: a,ab,abc,ac,b,bc,c

// Approch :Using bit manipulation

// intution: for a string of length n , there are 2^n possible combinations
//  eg:abc
//  000: ""
//  001: "a"
//  010: "b"
//  011: "ab"
//  100: "c"
// and so on till 111: "abc"
// for a particular combination, we will check if the bit is set or not, if set then we will add the corresponding char to the string

vector<string> subsequences(string str)
{
    vector<string> power_set;
    int n = str.size();
    // generating all possible combinations,using binary representation of numbers from 0 to 2^n-1(2^n-1 is the number of possible combinations)
    for (int i = 0; i < pow(2, n); i++)
    {

        string subsequenceStr = ""; // to store the current combination

        int c = n - 1; // to keep track of the current char in the string corresponding to the bit position
        int x = i;
        while (x)
        {
            if (x & 1)
            {
                // if the bit is set,then add the corresponding char to the string
                subsequenceStr = str[c] + subsequenceStr;
            }

            x >>= 1; // right shift by 1 to check for the next bit
            c--;     // decrement the char index
        }
        if (subsequenceStr != "")
            power_set.push_back(subsequenceStr); // if the subsequence formed is not empty
    }

    return power_set;
}