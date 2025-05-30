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
/*
Intuition: The kth largest is the one that is bigger than (n - k) elements, so we will pop out all the n-k smaller elements, then the top of the heap will be the kth largest element.
-----------
Uses a **min-heap** (priority queue with smallest element on top) of size `k` to keep track of the largest `k` elements seen so far.

- For each number in `nums`, we insert it into the min-heap.
- If the heap size exceeds `k`, we remove the smallest element.
- This way, the heap always contains the top `k` largest elements.
- After processing all numbers, we extract the elements from the heap to a result vector.

Time Complexity: O(n * log k)
Space Complexity: O(k)
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> findKLargest(vector<int>& nums, int k) {
    // Min-heap to store the k largest elements seen so far
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through all elements in the input array
    for (int num : nums) {
        minHeap.push(num);           // Add current element to the heap
        if (minHeap.size() > k) {
            minHeap.pop();           // Remove the smallest if heap size exceeds k
        }
    }

    // Extract the k largest elements from the heap into a result vector
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());  // Add smallest of k largest to result
        minHeap.pop();
    }

    // Optional: reverse to return in descending order
    reverse(result.begin(), result.end());
    
    return result;
}

```

---

### ✅ Template: K Most Frequent Elements

```cpp
/*
Intuition:
-----------
This function returns the **k most frequent elements** from a given array `nums`.

Approach:
1. Count the frequency of each number using a hash map (`unordered_map`).
2. Use a **min-heap (priority queue)** of size `k` to keep track of the top k elements by frequency.
   - Each heap element is a pair: {frequency, number}.
   - The min-heap ensures that the element with the **lowest frequency** among the top k is at the top.
3. For each entry in the frequency map:
   - Push it into the heap.
   - If the heap grows beyond size `k`, remove the least frequent element.
4. Finally, extract the elements from the heap to get the result.

Time Complexity: 
- O(n log k), where n is the number of unique elements.

Space Complexity:
- O(n) for the frequency map and heap.
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;  // Map to store frequency of each number

    // Count frequency of each number in the array
    for (int num : nums) {
        freq[num]++;
    }

    using Pair = pair<int, int>;  // Define a pair type: {frequency, number}
    priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap; // Min-heap based on frequency

    // Keep only top k elements in the min-heap
    for (auto& [num, count] : freq) {
        minHeap.push({count, num});         // Push current number and its frequency
        if (minHeap.size() > k) {
            minHeap.pop();                  // Remove the least frequent element
        }
    }

    vector<int> result;
    // Extract the top k frequent elements from the heap
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second); // Get the number (second element of pair)
        minHeap.pop();
    }

    return result;
}

```

---

### ✅ Template: K Closest Numbers to X

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    //Lambda function to compare two elements based on their distance to x
    // Syntax : [capture](parameters) -> return_type { body }
    auto comp = [&](int a, int b) -> bool {
        if (abs(a - x) == abs(b - x)) return a > b;
        return abs(a - x) > abs(b - x);
    };

    //decltype is used to define the type of the comparator fn at compile time
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

//OR simpler version without custom comparator
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // Max-heap to store the k closest elements based on distance from x
    priority_queue<pair<int, int>> maxHeap;

    for (int num : arr) {
        // Push pair: {distance from x, element value}
        maxHeap.push({abs(num - x), num});
        if (maxHeap.size() > k) {
            maxHeap.pop();  // Remove the farthest element
        }
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    sort(result.begin(), result.end());  // Return in ascending order
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

