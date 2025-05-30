// Kth Largest Element in an Array

// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution
{

private:
    // Use decreasing sort and grab the kth largest element
    // TC:O(N*logN)
    int brute(vector<int> &nums, int k)
    {

        // Sort the array in descending order, using the greater<int>() comparator
        sort(nums.begin(), nums.end(), greater<int>());

        // 0 based indexing
        return nums[k - 1];
    }

    // Intuition: The kth largest is the one that is bigger than (n - k) elements,
    // so we will use a min heap and  pop out all the n-k smaller elements,
    // then the top of the heap will be the kth largest element.
    // TC:O(n*logK)
    // SC:O(k), at any moment of time we are only storing k elements in heap

    int optimal(vector<int> &nums, int k)
    {
        // min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k) ]
                // will run n-k times, and will pop out the n-k smaller elements,
                // so at the end we will have the kth largest el at the top of the heap
                {

                    minHeap.pop(); // Remove the smallest to keep heap size = k
                }
        }

        return minHeap.top(); // Top is the kth largest
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return optimal(nums, k);
    }
};