# Fast & Slow Pointers

## 🔍 1. When Should Fast & Slow Pointers Be Used?

### ✅ Use this pattern when:
- You're working with **linked lists or arrays**, and:
  - You need to **detect cycles**
  - You need to **find the start of a cycle**
  - You want to **find the middle** of a linked list
  - You want to **check for palindrome** in a linked list

### 🧠 Keywords to watch for:
- “Cycle in a linked list”
- “Find the middle”
- “Detect loop”
- “Has a cycle / start of cycle”
- “Palindrome linked list”
- “Happy number” (for number transformations with cycles)

---

## 💣 2. Brute Force Approach

### Example: Detect cycle in a linked list

```cpp
bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    while (head) {
        if (visited.count(head)) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}
```

### ⛔ Time Complexity: `O(n)`  
### ⛔ Space Complexity: `O(n)` (uses extra hash set)

---

## 🛠️ 3. How Fast & Slow Pointers Work (With C++ Template)

### 💡 Idea:
You use two pointers:
- `slow` moves one step at a time.
- `fast` moves two steps at a time.

If there’s a **cycle**, fast and slow will **meet** at some point.

---

### ✅ C++ Template – Detect Cycle in Linked List

```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;         // 1 step
        fast = fast->next->next;   // 2 steps

        if (slow == fast) return true;
    }

    return false;
}
```

---

### ✅ C++ Template – Find Start of Cycle

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;  // Start of the cycle
        }
    }

    return nullptr;
}
```

---

### ✅ C++ Template – Find Middle of Linked List

```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // Middle node
}
```

---

## 📚 4. Common Problems Based on Fast & Slow Pointers

### 🟢 Easy
- [Leetcode 141](https://leetcode.com/problems/linked-list-cycle/) – Linked List Cycle
- [Leetcode 876](https://leetcode.com/problems/middle-of-the-linked-list/) – Middle of the Linked List

### 🟡 Medium
- [Leetcode 142](https://leetcode.com/problems/linked-list-cycle-ii/) – Linked List Cycle II (Find start of cycle)
- [Leetcode 202](https://leetcode.com/problems/happy-number/) – Happy Number
- [Leetcode 234](https://leetcode.com/problems/palindrome-linked-list/) – Palindrome Linked List

### 🔴 Hard
- [Leetcode 287](https://leetcode.com/problems/find-the-duplicate-number/) – Find the Duplicate Number (Cycle in array)
- [Leetcode 457](https://leetcode.com/problems/circular-array-loop/) – Circular Array Loop