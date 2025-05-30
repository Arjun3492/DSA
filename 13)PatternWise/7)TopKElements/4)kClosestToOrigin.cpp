// K Closest Points to Origin
//  https://leetcode.com/problems/k-closest-points-to-origin

class Solution
{
private:
    /**
     * Optimal approach using Max Heap (Priority Queue)
     *
     * Intuition: we will use a max heap of pair<distance, point> and maintain its size to K.
     * When the heap exceeds K, we remove the farthest point. In the end, we will be left with
     * the K closest points to the origin.
     *
     * TC: O(n * log k) — for n insertions/removals in a heap of size k
     * SC: O(k) — to store the heap and final answer
     */
    vector<vector<int>> optimal(vector<vector<int>> &points, int k)
    {
        using Pair = pair<int, vector<int>>; // pair<distance, point>
        priority_queue<Pair> pq;             // max heap by distance

        for (auto &p : points)
        {
            int dist = p[0] * p[0] + p[1] * p[1]; // compute squared distance
            pq.push({dist, p});

            if (pq.size() > k)
                pq.pop(); // remove the farthest point to maintain size k
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    /**
     * Brute-force approach using full sorting
     *
     * Intuition: we will create an array of pair storing {distance, coordinates},
     * then sort the array, and return the points from the first K pairs in the sorted array
     *
     * TC: O(n) + O(n log n)
     * SC: O(n)
     */
    vector<vector<int>> brute(vector<vector<int>> &points, int k)
    {
        using Pair = pair<int, vector<int>>; // will store <distance, point>
        vector<Pair> temp;

        for (auto &p : points)
        {
            int dist = p[0] * p[0] + p[1] * p[1]; // x^2 + y^2
            temp.push_back({dist, p});
        }

        sort(temp.begin(), temp.end()); // sort in ascending order by distance

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(temp[i].second); // return the first K points
        }

        return ans;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        return optimal(points, k);
    }
};
