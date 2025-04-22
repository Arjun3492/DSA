# Top ‘K’ Elements Pattern

## 🔍 1. When Should Top ‘K’ Elements Pattern Be Used?

### ✅ Use this pattern when the problem asks for:
- Top **K largest/smallest** elements
- Top **K frequent** elements
- Kth **largest/smallest** element
- Elements **closest to a target**
- Elements **with specific ranking or frequency**

### 🧠 Keywords to look for:
- “Top K”
- “K most frequent”
- “K closest”
- “Kth largest/smallest”
- “Return K elements”
- “Keep only K best/worst”

---

## 💣 2. Brute Force Approach

### Example: Find K largest elements
```cpp
vector<int> findKLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return vector<int>(nums.begin(), nums.begin() + k);
}
```

### ⛔ Time: `O(n log n)` — sorting the entire array

But often, we can do better using a **heap** (priority queue) and avoid sorting the whole array!

---

## 🛠️ 3. How the Pattern Works + C++ Template

### 💡 Core Idea:
Use a **min-heap (for K largest)** or a **max-heap (for K smallest)** to maintain the **top K elements** in `O(n log k)` time.

---

### ✅ Template: Find K Largest Elements Using Min-Heap

```cpp
vector<int> findKLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // remove the smallest
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(result.begin(), result.end()); // optional, to return descending order
    return result;
}
```

---

### ✅ Template: K Most Frequent Elements

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    using Pair = pair<int, int>;  // {frequency, number}
    priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}
```

---

### ✅ Template: K Closest Numbers to X

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto comp = [&](int a, int b) {
        if (abs(a - x) == abs(b - x)) return a > b;
        return abs(a - x) > abs(b - x);
    };

    priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);

    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) maxHeap.pop();
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }

    sort(result.begin(), result.end());  // usually required
    return result;
}
```

---

## 📚 4. Problems That Use the Top ‘K’ Elements Pattern

### 🟢 Easy
- [Leetcode 703](https://leetcode.com/problems/kth-largest-element-in-a-stream/) – Kth Largest Element in a Stream

### 🟡 Medium
- [Leetcode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) – Kth Largest Element in an Array
- [Leetcode 347](https://leetcode.com/problems/top-k-frequent-elements/) – Top K Frequent Elements
- [Leetcode 658](https://leetcode.com/problems/find-k-closest-elements/) – Find K Closest Elements

### 🔴 Hard
- [Leetcode 973](https://leetcode.com/problems/k-closest-points-to-origin/) – K Closest Points to Origin
- [Leetcode 295](https://leetcode.com/problems/find-median-from-data-stream/) – Median from Data Stream
- [Leetcode 692](https://leetcode.com/problems/top-k-frequent-words/) – Top K Frequent Words

