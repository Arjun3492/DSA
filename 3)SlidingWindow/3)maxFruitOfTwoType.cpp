// Fruits in basket
// Problem :https://www.codingninjas.com/studio/problems/fruits-and-baskets_985356

int findMaxFruits(vector<int> &arr, int n)
{
    map<int, int> mpp;
    int l = 0, r = 0;
    int ans = 0;
    while (r < n)
    {
        int currFruit = arr[r];
        mpp[currFruit]++;

        while (mpp.size() > 2)
        {
            // moving left pointer until  fruit of one kind gets exhausted
            if (mpp[arr[l]] == 1)
            {
                mpp.erase(arr[l]);
            }
            else
            {
                mpp[arr[l]]--;
            }
            l++;
        }
        int currLen = r - l + 1;

        ans = max(ans, currLen);
        r++;
    }
    return ans;
}