void helper(int idx, vector<int> &arr, vector<int> &ds,
            vector<vector<int>> &ans)
{

    ans.push_back(ds);

    // each iteration will pick a unique element for the "idx" position
    // i.e. when idx=1, it will form subsets of size 1 will all possible unique
    // elements and so on
    for (int i = idx; i < arr.size(); i++)
    {

        // skipping duplicates for a given position
        if (i != idx && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        helper(i + 1, arr, ds, ans); // moving to fill next
        ds.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int> &arr)
{

    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end()); // only if array is unsorted
    helper(0, arr, ds, ans);
    return ans;
}