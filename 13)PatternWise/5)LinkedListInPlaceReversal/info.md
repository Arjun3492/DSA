# Linked List In-Place Reversal

## 🔍 1. When Should Linked List In-Place Reversal Be Used?

### ✅ Use this pattern when:
- You need to **reverse all or part of a linked list**.
- You are asked to **reverse nodes in groups**, or **rotate** the list.
- You want to **modify the list structure directly** without extra memory (O(1) space).

### 🧠 Keywords to look for:
- “Reverse linked list”
- “In-place”
- “Reverse between positions left and right”
- “Reverse in groups of k”
- “Rotate the list”
- “Do not use extra space”

---

## 💣 2. Brute Force Approach (Without In-Place Reversal)

### Example: Reverse Linked List using stack (extra space)

```cpp
ListNode* reverseList(ListNode* head) {
    stack<ListNode*> s;
    ListNode* curr = head;
    while (curr) {
        s.push(curr);
        curr = curr->next;
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!s.empty()) {
        tail->next = s.top();
        s.pop();
        tail = tail->next;
    }
    tail->next = nullptr;

    return dummy.next;
}
```

### ⛔ Time: O(n), Space: O(n)

---

## 🛠️ 3. How In-Place Reversal Works (With C++ Templates)

### 💡 Core Idea:
Reverse the pointers of the list while traversing it using **three pointers**: `prev`, `curr`, and `next`.

---

### ✅ Template 1: Reverse Entire Linked List (In-place)

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next; // save next node
        curr->next = prev;           // reverse the link
        prev = curr;                 // move prev forward
        curr = next;                 // move curr forward
    }

    return prev;
}
```

---

### ✅ Template 2: Reverse a Sublist Between Positions `left` and `right`

```cpp
// Function to reverse the sublist using Template 1
ListNode* reverseBetween1(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    // Create a dummy node to handle edge cases where left == 1
    // Dummy node will handle edge case where reversal starts from 1(i.e. head), so dummy node will preserve pointing to the new head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Step 1: Reach the node before 'left'
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }

    // Step 2: Start reversing the sublist
    ListNode* curr = prev->next;
    ListNode* next = nullptr;
    ListNode* prevSub = nullptr;

    for (int i = 0; i <= right - left; ++i) {
        next = curr->next;
        curr->next = prevSub;
        prevSub = curr;
        curr = next;
    }

    // Step 3: Reconnect the reversed sublist back to the main list
    prev->next->next = curr;   // tail of reversed sublist points to remaining list
    prev->next = prevSub;      // node before 'left' points to new head of reversed sublist

    return dummy->next;
}

// In this in each iteration we move curr one place right and bring the "next" to the front
ListNode* reverseBetween2(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    //Making a dummy node to handle edge case where reversal starts from 1(i.e. head), so dummy node will preserve pointing to the new head
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        ListNode* next = curr->next;
        // moving curr one place to right
        curr->next = next->next; 
        // pointing next to the front
        next->next = prev->next;
        // marking the new front 
        prev->next = next;
    }

    return dummy.next;
}
```

---

### ✅ Template 3: Reverse in Groups of K

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    
    // Check if there are at least k nodes
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) return head;

    // Reverse first k nodes
    ListNode* prev = nullptr;
    curr = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the tail of the reversed group
    head->next = reverseKGroup(curr, k);
    return prev;
}
```

---

## 📚 4. Common Problems Based on This Pattern

### 🟢 Easy
- [Leetcode 206](https://leetcode.com/problems/reverse-linked-list/) – Reverse Linked List

### 🟡 Medium
- [Leetcode 92](https://leetcode.com/problems/reverse-linked-list-ii/) – Reverse Linked List II
- [Leetcode 61](https://leetcode.com/problems/rotate-list/) – Rotate List
- [Leetcode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/) – Reverse Nodes in k-Group

### 🔴 Hard
- [Leetcode 1721](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) – Swapping Nodes in a Linked List (uses reversal concepts)
- [Leetcode 430](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) – Flatten Multilevel Doubly Linked List
