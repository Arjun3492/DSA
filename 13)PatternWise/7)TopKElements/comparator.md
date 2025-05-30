# Understanding Comparators in `priority_queue` vs `sort()`

---

In C++'s `priority_queue`, the **comparator defines what goes to the *bottom*** — because the top is always the **"greatest"** according to the comparator.

So the comparator answers the question:

> **"Is `a` less prioritized than `b`?"**

If the comparator returns `true`, then `a` is *considered greater*, so it will **sink down** in the heap, and `b` will be on top.

---

### 🔄 Comparator for `std::sort` vs `std::priority_queue`

| Context          | Comparator Returns `true` | Meaning                       |
| ---------------- | ------------------------- | ----------------------------- |
| `sort(a, b)`     | `a < b`                   | No swap; `a` comes before `b` |
| `priority_queue` | `a` has lower priority    | `a` is below `b` in the heap  |

---

### 🧠 Takeaway Rule

> In `priority_queue`, the comparator **inverts** your usual thinking:
> It returns `true` if the **first argument should sink** in the heap.

So define the comparator such that **`true` means lower priority**, and that element will end up **deeper** in the heap.

---
