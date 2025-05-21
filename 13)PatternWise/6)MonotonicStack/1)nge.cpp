// 496. Next Greater Element I
//  https://leetcode.com/problems/next-greater-element-i
class Solution
{
private:
    // For each elements in num1 we will first find its index in num2, and then look for the
    // NGE traversing forward
    // TC:O(n*m)
    // SC:O(1)
    vector<int> brute(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1); // initialling all by -1

        for (int i = 0; i < n; i++)
        {
            int j = 0;
            int currEl = nums1[i];

            // finding the index of current_element in nums2
            while (nums2[j] != currEl)
            {
                j++;
            }

            // looking for NGE afterwards
            while (j < m)
            {
                if (nums2[j] > currEl)
                {
                    // if found, update in ans list and break
                    ans[i] = nums2[j];
                    break;
                }
                j++;
            }
        }

        return ans;
    }

    // TC:O(n)
    // SC:O(n) //stack
    vector<int> optimal(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1); // initialling all by -1
        stack<int> st;
        map<int, int> mpp;

        // using monotonic stack approach
        for (int i = m - 1; i >= 0; i--)
        {
            // pop elements from top till currEl>st.top()
            while (!st.empty() && nums2[i] > st.top())
            {
                st.pop();
            }

            // NGE of currEl = st.top() ,if any (since we popped all elements < currEl)
            if (!st.empty())
                mpp[nums2[i]] = st.top();

            // pushing curr element onto stack
            st.push(nums2[i]);
        }

        // getting the nge of required elements in nums1 using the nge of all elements stored in map previously
        for (int i = 0; i < n; i++)
        {

            if (mpp.find(nums1[i]) != mpp.end())
            {
                int nge = mpp[nums1[i]];
                ans[i] = nge;
            }
        }

        return ans;
    }

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        return optimal(nums1, nums2);
    }
};