// Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements

class Solution
{
private:
    /**
     Optimal approach using a Max Heap (Priority Queue)
     Intuition: will use a max heap of pair<abs_diff,element>, and will maintain the size of K
     when priority queue exceeds size k we will pop out elements, this will pop out
     (n-k) larger (farther), leaving us with the k closest elements
     * Time Complexity: O(n * log k) — each insertion/removal in the heap takes O(log k), done n times.
     * Space Complexity: O(k) — for storing the heap and result array.
     */
    vector<int> optimal(vector<int> &arr, int k, int x)
    {
        using Pair = pair<int, int>; // pair<abs_diff, element>
        priority_queue<Pair> pq;     // Max heap

        for (int num : arr)
        {
            // Push (absolute difference from x, number itself)
            pq.push({abs(num - x), num});

            // If heap size exceeds k, remove the farthest element
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        // Extract K closest elements from the heap
        while (!pq.empty())
        {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }

        // Sort result to return in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }

    /**
     * Brute-force approach using full sort
     *
     * Intuition:
     * - Compute the absolute difference of each element from X.
     * - Store it as a pair: {abs_diff, value}.
     * - Sort all elements based on the abs_diff.
     * - Take the first K elements after sorting.
     * - Finally, sort the result in ascending order (as required by the problem).
     *
     * Time Complexity: O(n * log n) — due to full sort.
     * Space Complexity: O(n) — for storing the list of pairs.
     */
    vector<int> brute(vector<int> &arr, int k, int x)
    {
        using Pair = pair<int, int>; // pair<abs_diff, element>
        vector<Pair> list;

        // Build the list of (abs_diff, value)
        for (int num : arr)
        {
            list.push_back({abs(num - x), num});
        }

        // Sort by abs_diff, then by value
        sort(list.begin(), list.end());

        vector<int> ans;

        // Take first k elements
        for (int i = 0; i < k; i++)
        {
            ans.push_back(list[i].second);
        }

        // Sort result in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }

public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        return optimal(arr, k, x);
        // return brute(arr, k, x);
    }
};
