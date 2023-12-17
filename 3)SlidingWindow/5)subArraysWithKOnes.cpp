// Count Subarrays With K Ones
// Problem statement:You are given an array of 0's and 1's and an integer k. Find the number of subarrays with exactly k 1's.

// Link:https://www.codingninjas.com/studio/problems/count-distinct-subarrays-with-at-most-k-odd-elements_1069335

//: This function calculates the total number of subarrays with at most k ones.
int subStrWithAtmostKOnes(vector<int> &arr, int k)
{

    {
        int l = 0, r = 0;
        // l and r are the left and right pointers of the current subarray.
        int ans = 0;
        int count = 0;
        // count keeps track of the count of ones in the current subarray.
        int n = arr.size();

        while (r < n)
        // The loop iterates through the array, updating count and adjusting the window size accordingly.
        {
            int currEl = arr[r];
            if (currEl == 1)
            {
                count++;
            }

            while (count > k)
            {
                if (arr[l] == 1)
                {
                    count--;
                }
                l++;
            }

            ans += r - l + 1;
            // ans accumulates the count of subarrays with at most k ones.

            r++;
        }

        return ans;
    }
}

// subarrayWithSum function: This function calls solve twice, once with parameter k and once with k-1,
// and then calculates the difference to get the count of subarrays with exactly k ones.
int subarrayWithSum(vector<int> &arr, int k)
{

    return subStrWithAtmostKOnes(arr, k) - subStrWithAtmostKOnes(arr, k - 1);
}
