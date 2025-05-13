// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number

class Solution
{
private:
    // will use nested loops to find duplicate of each element in the array
    // TC:O(n^2)
    // SC:O(1)
    int brute(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i <= n - 2; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
        return -1;
    }

    // will use hashSet to check for duplicacy
    // TC:O(n)
    // SC:O(n)
    int better(vector<int> &nums)
    {
        set<int> st;
        for (int i : nums)
        {
            // if already seen before, it is duplicate num
            if (st.count(i) == 1)
                return i;
            st.insert(i);
        }
        return -1;
    }

    // Using the Linked List cycle detection approach (Floyd's Tortoise and Hare)
    // Intuition:
    // Since the array contains n + 1 numbers in the range[1, n], by the pigeonhole principle,
    // at least two indices must point to the same value — this guarantees a duplicate.
    //
    // If we treat the array like a linked list where:
    //   - Each index is a node
    //   - The value at each index points to the next node (i.e., nums[i] is the "next" pointer)
    //
    // This creates a structure similar to a linked list with a cycle.
    // The duplicate number corresponds to the entry point of the cycle.

    int optimal(vector<int> &nums)
    {
        int start = nums[0];
        int slow = nums[start];
        int fast = nums[nums[start]];
        while (slow != fast)
        {
            slow = nums[slow];       // moving one step
            fast = nums[nums[fast]]; // moving two step
        };

        // resetting slow to start and moving both slow and fast by one
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

public:
    int findDuplicate(vector<int> &nums)
    {
        return optimal(nums);
    }
};