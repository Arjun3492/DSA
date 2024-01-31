// Longest Consecutive Sequence in an Array
// Problem Statement: You are given an array of ‘N’ integers.
// You need to find the length of the longest sequence which contains the consecutive elements.

// Example:
// Input: [1, 9, 3, 10, 4, 20, 2]
// Output: 4
// Explanation: The longest consecutive sequence is [1, 2, 3, 4] which is present in the array.

// BRUTE FORCE SOLUTION
// Variables ::
// count: to store the length of current subsequence
// maxCount:to store the max length of consecutive sequence
// STEPS INVOLVED
// STEP1:We will iterate through each array element "i"
// STEP2:For each array element "i" we will check if "i+1" exists in the array
// STEP2.1:If "i+1" exists in the array then we will increment the counter "count"
// We will repeat step 2.1 for all the consecutive elements i+2,i+3 and so on
// STEP3:We will update maxCount=max(maxCount,count)
// STEP4:If "i+1" does not exist in the array then we will update i to the next element and reset count to 1

bool linearSearch(vector<int> &a, int el)
{
    for (int i : a)
    {
        if (i == el)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int> &a)
{
    int maxCount = 1;
    for (int i : a)
    {
        int count = 1;
        int el = i;
        while (linearSearch(a, el + 1))
        {
            el++;
            count++;
        }
        maxCount = max(maxCount, count);
    }
}

// BETTER SOLUTION
// STEP1: Sort the array
// STEP2: Initialise lastEl=INT_MIN count=1,and maxCount=1
// STEP3: Iterate through the array
// STEP4: IF current element ==lastEl+1 ,update count=count+1
// STEP5: ELSE IF current ==lastEl ,do nothing
// STEP6: ELSE reset count=1
// STEP7: update lastEl=i
// STEP8: update maxCount=max(maxCount,count)

int longestSuccessiveElements(vector<int> &a)
{
    sort(a.begin(), a.end());
    int lastEl = INT_MIN, count = 1, maxCount = 1;
    for (int i : a)
    {
        if (i == lastEl + 1)
        {
            count++;
        }
        else if (i != lastEl)
        {
            count = 1;
        }
        lastEl = i;
        maxCount = max(maxCount, count);
    }
}

// OPTIMAL APPROACH
// STEP1: Initialise a set
// STEP2: Insert all the array elements in the set
// STEP3: Initialise maxCount=1
// STEP4: Iterate through the array
// STEP5: IF current element-1 does not exist in the set
// STEP5.1: Initialise count=1
// STEP5.2: Initialise el=i
// STEP5.3: WHILE el+1 exists in the set
// STEP5.3.1: el=el+1
// STEP5.3.2: count=count+1
// STEP5.4: update maxCount=max(maxCount,count)
// STEP6: return maxCount

int longestSuccessiveElements(vector<int> &a)
{
    unordered_set<int> s;
    for (int i : a)
    {
        s.insert(i);
    }
    int maxCount = 1;
    for (int i : a)
    {

        if (s.find(i - 1) == s.end())
        // meaning i is first element of a sequence,so we will check for consecutive elements for this
        {
            int count = 1;
            int el = i;
            while (s.find(el + 1) != s.end())
            {
                el++;
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}
