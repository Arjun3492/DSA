// Palindrome Linked List
// [https://leetcode.com/problems/palindrome-linked-list]

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
    // We will use stack to push all elements into the stack and then
    // traverse the LL from head while poping elements
    // from the stack(reverse direction) and comparing both one by one
    // TC:O(n)
    // SC:O(n)
    bool brute(ListNode *head)
    {

        stack<int> st;
        ListNode *curr = head;
        // Pushing all the elements into the stack
        while (curr)
        {
            st.push(curr->val);
            curr = curr->next;
        }
        curr = head;

        // Traversing LL and comparing with stack's top element
        while (curr)
        {
            // If not equal, not a Palindrome
            if (st.top() != curr->val)
                return false;
            st.pop();
            curr = curr->next;
        }
        return true;
    }

    // Utility method to get the middle of LL using the slow and fats pointer approach
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Utility method to get the reverse of given LL
    ListNode *getReverse(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head, *next = head->next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Traverse till the middle of LL
    //  Reverse the second half of LL and compare both the halves for equality
    bool optimal(ListNode *head)
    {

        ListNode *mid = getMiddle(head);

        ListNode *revHead = getReverse(mid);

        while (revHead)
        {
            if (revHead->val != head->val)
                return false;
            revHead = revHead->next;
            head = head->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        return optimal(head);
    }
};