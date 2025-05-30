// Top K Frequent Elements

// https://leetcode.com/problems/top-k-frequent-elements

class Solution
{

private:
    // Will create a freq map of the elements
    //  then create a list of pair<freq,num > and sort it
    //  then return the kth element
    // TC:O(n*logn)
    vector<int> brute(vector<int> &nums, int k)
    {

        unordered_map<int, int> mpp;
        for (int num : nums)
        {
            mpp[num]++;
        }

        vector<pair<int, int>> list; // will store pair of<freq,element>

        for (auto [freq, element] : mpp)
        {

            // store are pair of<freq,element>
            list.push_back({freq,
                            element});
        }

        sort(list.begin(), list.end(), greater<pair<int, int>>());

        // fetch only the result part of k
        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(list[i].second);
        }

        return result;
    }

    // Intuition: we will find the freq map firstly then use the
    //  min_heap<pair<freq,element>> to eliminate the (n-k) least
    //  frequent elements,by maintaing the heap size of k

    // TC:O(n*logk)
    // SC:O(k), at any moment of time we are only storing k elements in heap
    vector<int> optimal(vector<int> &nums, int k)
    {

        unordered_map<int, int> mpp;
        for (int num : nums)
        {
            mpp[num]++;
        }

        // min_heap storing pair of <freq,element>
        using Pair = pair<int, int>;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        for (auto [freq, element] : mpp)
        {

            pq.push({freq, element});

            if (pq.size() > k)
                pq.pop(); // removing the (n-k) least freq elements
        }

        vector<int> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        return optimal(nums, k);
    }
};