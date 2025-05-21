// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */

// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
private:
    // Using stack approach for reversal of LL
    // TC:O(n)
    // SC:O(n/k(recursive) + n(stack))
    ListNode *brute(ListNode *head, int k)
    {
        // Step 1: Check if we have at least k nodes to reverse
        ListNode *curr = head;
        int count = 0;
        while (curr && count < k)
        {
            curr = curr->next;
            count++;
        }

        if (count < k)
            return head; // Not enough nodes to reverse

        // Step 2: Use stack to store k nodes
        stack<ListNode *> st;
        curr = head;
        for (int i = 0; i < k; ++i)
        {
            st.push(curr);
            curr = curr->next;
        }

        // Step 3: Pop from stack to reverse the k nodes
        ListNode *newHead = st.top();
        st.pop();
        ListNode *temp = newHead;

        while (!st.empty())
        {
            temp->next = st.top();
            temp = temp->next;
            st.pop();
        }

        // Step 4: Recursively reverse the rest and attach
        temp->next = brute(curr, k);

        return newHead;
    }

    // Using In Place reversal Technique approach for reversal
    // TC:O(n)
    // SC:O(n/k) recursive stack space
    ListNode *optimal(ListNode *head, int k)
    {
        // BASE CONDITION:Check if there are enough nodes to be reversed
        int count = 0;
        ListNode *curr = head;
        while (curr && count < k)
        {
            curr = curr->next;
            count++;
        }

        if (count < k)
            // Not enough nodes, directly return the head
            return head;

        // REVERSAL STARTS HERE

        ListNode *prev = nullptr; // maintaining the prev and curr pointers
        curr = head;
        // Reversing the first k nodes
        for (int i = 0; i < k; i++)
        {
            ListNode *next = curr->next; // storing the next node
            curr->next = prev;           // reversing curr node to point to prev node
            prev = curr;                 // moving prev and curr
            curr = next;
        }

        // pointing the end (now head) to rest of LL
        // curr is the head of the rest of the LL
        head->next = optimal(curr, k);
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return optimal(head, k);
    }
};