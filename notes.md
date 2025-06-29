# DSA Patterns Cheatsheet

## 1. Prefix Sum Pattern

### 1.1 Basic Prefix Sum
Used to find range queries in constant time.

```cpp
vector<int> prefixSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    return prefix;
}

// Example: get sum from l to r
int rangeSum(const vector<int>& prefix, int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}
```

### 1.2 Prefix Sum with HashMap (Target Strategy)
Used to find count of subarrays satisfying a given condition (e.g., count of subarray with sum = k or with k odd elements).

```cpp
int countSubarraysWithSumK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    int count = 0, prefixSum = 0;

    prefixCount[0] = 1; // base case for subarray starting at index 0

    for (int num : nums) {
        prefixSum += num;

        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }

        prefixCount[prefixSum]++;
    }

    return count;
}
```

## 2. Two Pointer (Left - Right) Approach

### 2.1 Find Pair with Target Sum in Sorted Array
Examples: Two sum, Three sum

```cpp
bool hasPairWithSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }

    return false;
}
```

### 2.2 Find Areas with Boundary Constraints
Examples: Trapping rain water, Max area of container

```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int width = right - left;
        maxWater = max(maxWater, h * width);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}
```

## 3. Sliding Window Approach

### 3.1 Fixed Size Window
Used to find the sum/avg/max/min of a fixed size window.

**Example:** Find max sum of subarray of size K

**Working:**
1. Prepare initial window of size K and find the initial answer
2. Remove the leftmost element and add the rightmost element
3. Update the answer until the end of array

```cpp
int maxSum(vector<int>& nums, int k) {
    int n = nums.size(), maxSum = 0, windowSum = 0;
    int i = 0;
    
    // Prepare the initial window
    while (i < k) {
        windowSum += nums[i];
        i++;
    }
    
    // Initial answer
    maxSum = windowSum;

    // Adding rightmost and removing leftmost one by one until end
    while (i < n) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
        i++;
    }

    return maxSum;
}
```

### 3.2 Dynamic Size Window
Used to find the max/min length of window satisfying a given condition.

**Example:** Find the max length of subarray whose sum is ≤ K

**Working:**
1. Take left and right pointer
2. Traverse the right pointer and calculate the sum
3. If sum ≤ K, update using `currLen = right - left + 1`
4. While traversing, reduce the window size from left until condition is satisfied

```cpp
int maxSubarrayLength(vector<int>& nums, int K) {
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        while (sum > K) { // shrink window until valid
            sum -= nums[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

## 4. Fast and Slow Pointer Approach

### 4.1 Find Middle of Linked List
Move slow one step and fast two steps. When fast reaches the end, slow will be at the middle.

```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // slow is at middle
}
```

### 4.2 Detect Cycle in Linked List
If there's a cycle, fast will eventually meet slow inside the loop (like two runners on a circular track).

```cpp
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true; // cycle detected
    }

    return false;
}
```

### 4.3 Find Start of Cycle
After detecting a cycle (they meet), reset slow to head. Now move both slow and fast one step at a time. They'll meet at the start of the cycle.

```cpp
ListNode* detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    // First detect if cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle found, reset slow to head
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // start of cycle
        }
    }

    return nullptr; // no cycle
}
```

### 4.4 Check if Linked List is Palindrome
**Steps:**
1. Find middle using slow and fast pointers
2. Reverse second half using the prev, curr, and next pointer technique
3. Compare both halves for equality

```cpp
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Step 3: Compare both halves
    ListNode* left = head;
    ListNode* right = prev; // head of reversed second half

    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}
```

### 4.5 Find Duplicate Number in Array
For finding duplicate element in a (n+1) size array with elements between [1,n].

**Logic:** There will be at least two indices with the same number. If we treat the array as a linked list where index is a node and the element at the index is the next node, there are two indices pointing to the same node, hence a cycle will form.

```cpp
int duplicateNum(vector<int>& arr) {
    // Initializing the slow and fast pointers
    int slow = arr[0];
    int fast = arr[slow];

    // Finding the intersection point
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

    // Finding the start of cycle (i.e., the duplicate element)
    slow = 0;
    // Resetting slow to 0 and moving both by one
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}
```

## 5. Linked List In-Place Reversal

Used to reverse a given linked list, reverse a part of linked list, or rotate linked list in groups of K.

**Brute Force Approach:** Use a stack, push elements into the stack, then while popping out elements, prepare the reverse linked list.

### 5.1 Reverse a Complete Linked List

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

### 5.2 Reverse Linked List Between Left and Right Positions

#### Approach 1: Direct Reversal

```cpp
ListNode* reverseBetween1(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    // Create a dummy node to handle edge cases where left == 1
    // Dummy node helps preserve a pointer to the new head when reversal starts from the head
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
    prev->next->next = curr;   // next node to prev (now at tail of reverse part) points to remaining LL
    prev->next = prevSub;      // updating the next node of prev to head of reversed LL

    return dummy->next;
}
```

#### Approach 2: Iterative Movement
In each iteration, move curr one place right and bring the "next" to the front.

```cpp
ListNode* reverseBetween2(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    // Making a dummy node to handle edge case where reversal starts from 1 (i.e., head)
    // So dummy node will preserve pointing to the new head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Traverse to before the start of reversal
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        ListNode* next = curr->next;
        // Moving curr one place to right
        curr->next = next->next; 
        // Pointing next to the front
        next->next = prev->next;
        // Marking the new front 
        prev->next = next;
    }

    return dummy->next;
}
```

### 5.3 Reverse Linked List in Groups of K

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

## 6. Monotonic Stack

Used to find the:
1. Next Greater/Smaller Element 
2. Previous Greater/Smaller Element
3. Problems involving Height(Histogram), temperature(Cooler Day) or Price (Stock Span)

### 6.1 Next Greater/Smaller Element

```cpp
//NEXT GREATER ELEMENT
// In this approach we process the elements that are being processed
vector<int> nge(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        // if the stack is not empty && current element > top of stack
        if (!st.empty() && nums[i] > nums[st.top()])
        {
            int topIndex = st.top();
            // current element is NGE of the top index element
            ans[topIndex] = nums[i];
        }
        st.push(i); // push the current index to stack
    }
}

//PREVIOUS GREATER ELEMENT
vector<int> nge(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n-1; i >=0; i--)
    {
        // if the stack is not empty && current element > top of stack
        if (!st.empty() && nums[i] > nums[st.top()])
        {
            int topIndex = st.top();
            // current element is PGE of the top index element
            ans[topIndex] = nums[i];
        }
        st.push(i); // push the current index to stack
    }
}
```
Similarly for NSE and PSE , the comparison operator with the current element will switch to <
-  if (!st.empty() && nums[i] < nums[st.top()])
-  

### 6.2 Area of Histogram


```cpp
/*
We use a monotonic increasing stack to find the largest rectangle in a histogram.

- For each bar, if it's shorter than the top of the stack:
   - The current bar is the "next smaller" for the bar at the top.
   - The new top (after popping) becomes its "previous smaller".
   - We calculate area with height = popped bar, width = distance between next and previous smaller.

- We add a sentinel '0' at the end to ensure all bars are processed.
*/
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); // sentinel to flush stack
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int nextSmaller = i;
            int prevSmaller = st.empty() ? -1 : st.top();
            int width = nextSmaller - prevSmaller - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
}
```

## 7. Top K elements (Priority Queue)

Used when we need to find the top k elements that satisfy a given condition from a range or stream of elements.

Example:
1. Find Kth largest/smallest elements
2. Top K Largest/smallest elements
3. K most/least Frequent elements
4. K closest/farthest elements  (to origin or a given point)

Tip :
Use min-heap when we want to find top K largest elements
Use max-heap when we want to find top K smallest elements

Brute approach: Sort data list and return first K elements

### 7.1 Top K largest elements

```cpp
/*
Intuition: The kth largest is the one that is bigger than (n - k) elements, so we will pop out all the n-k smaller elements, then the top of the heap will be the kth largest element.
-----------
Uses a **min-heap** (priority queue with smallest element on top) of size `k` to keep track of the largest `k` elements seen so far.

- For each number in `nums`, we insert it into the min-heap.
- If the heap size exceeds `k`, we remove the smallest element.
- This way, we have popped the smallest n-k elements from the heap towards the end

Time Complexity: O(n * log k)
Space Complexity: O(k)
*/

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

### 7.2 Top K frequent element
```cpp
/*
Intuition: We will first prepare the map of frequencies of each element, then use a min-heap of pair where each pair will have <frequency_of_element,element>

This way following the Top K approach we will be left with the top K most frequent elements by pair inside the priority_queue

Time: O(n log k)

Space: O(n) for the map and heap
*/



vector<int> findKMostFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequencies
    unordered_map<int, int> mpp;
    for (int num : nums) {
        mpp[num]++;
    }

    // Step 2: Use min-heap of pairs (freq, element)
    using Pair = pair<int, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

    for (auto p : mpp) {
        int element = p.first;
        int freq = p.second;
        minHeap.push({freq, element});
        if (minHeap.size() > k) {
            // Remove least frequent
            minHeap.pop();  
        }
    }

    // Step 3: Extract elements from heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    reverse(result.begin(), result.end());  // Optional
    return result;
}


```

### 7.3 Top K Closest Points to Origin / Closest to a number with absolute difference


```cpp
/*
Intuition: We calculate the distance of each point from the origin (0,0) using the formula x² + y² (no need to take sqrt for comparison).
We then use a **max-heap** to store K closest points, pushing pairs as <distance, point>.

Whenever heap size exceeds K, we pop the farthest point (i.e., with largest distance).
This leaves us with the K closest points.

Time: O(n log k) — n points inserted into a heap of size k  
Space: O(k)
*/

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Max-heap to keep track of k closest points
    using Pair = pair<int, vector<int>>; // <distance, point>
    priority_queue<Pair> maxHeap;

    for (auto& point : points) {
        int x = point[0], y = point[1];
        int dist = x * x + y * y; // distance squared
        maxHeap.push({dist, point});
        if (maxHeap.size() > k) {
            maxHeap.pop(); // remove farthest point
        }
    }

    // Extract the k closest points
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

```
## 8. Binary Search Technique

When to Use Binary Search
1. **Sorted Array Problems**: Find element in rotated sorted array
2. **Boundary Problems**: First/Last occurrence of target in sorted search space
3. **Peak Finding**: Boundary elements (Floor/Ceil/Peak) in mountain arrays
4. **Optimization Problems**: Minimum/maximum solution to a problem
5. **Partition Problems**: Minimize max value or maximize min value of partitions


### 8.1: Element in Rotated Sorted Array

```cpp
/*
### Problem
Find a target element in a rotated sorted array (e.g., `[4,5,6,7,0,1,2]`).

### Intuition
Even though the array is rotated, at least one half of the array around the mid point will always be sorted. We can determine which half is sorted and check if our target lies in that sorted half.

### Key Insight
- If `nums[left] <= nums[mid]`: Left half is sorted
- Otherwise: Right half is sorted
- Check if target lies in the sorted half, then adjust search bounds accordingly


**Time Complexity**: O(log n)  
**Space Complexity**: O(1)
*/
int searchInRotatedArray(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Found the target
        if (nums[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        // Example: [2, 3, 4, 5, 6, 7, 0, 1] where mid points to 5
        if (nums[left] <= nums[mid]) {
            // Target is in the sorted left half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // Search left half
            } else {
                left = mid + 1;   // Search right half
            }
        }
        // Right half is sorted
        // Example: [6, 7, 0, 1, 2, 3, 4, 5] where mid points to 2
        else {
            // Target is in the sorted right half
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;   // Search right half
            } else {
                right = mid - 1;  // Search left half
            }
        }
    }
    
    return -1;  // Target not found
}
```



---

### 8.2: First/Last Occurrence of Target


```cpp

/*
### Problem
Find the first or last occurrence of a target element in a sorted array with duplicates.

### Intuition
When we find the target, we don't stop immediately. Instead, we continue searching in the direction we want (left for first occurrence, right for last occurrence) to find the boundary.

### Key Insight
- For **first occurrence**: When target is found, continue searching left (`right = mid - 1`)
- For **last occurrence**: When target is found, continue searching right (`left = mid + 1`)


**Time Complexity**: O(log n)  
**Space Complexity**: O(1)
*/
int findFirstOccurrence(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;           // Potential answer
            right = mid - 1;        // Continue searching left for first occurrence
        } 
        else if (target < nums[mid]) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    
    return result;
}

int findLastOccurrence(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;           // Potential answer
            left = mid + 1;         // Continue searching right for last occurrence
        } 
        else if (target < nums[mid]) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    
    return result;
}
```

---

### 8.3: Find Peak Element

```cpp
/*

### Problem
Find a peak element in an array where `nums[i] > nums[i-1]` and `nums[i] > nums[i+1]`.

### Intuition
Think of the array as a mountain landscape. If we're at a point where the next element is smaller, we're on a descending slope, so a peak must exist to our left. If the next element is larger, we're on an ascending slope, so a peak must exist to our right.

### Key Insight
- If `nums[mid] > nums[mid + 1]`: We're on descending slope → peak is in left half (including mid)
- If `nums[mid] < nums[mid + 1]`: We're on ascending slope → peak is in right half (excluding mid)

**Time Complexity**: O(log n)  
**Space Complexity**: O(1)

*/
int findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Compare mid with next element to determine slope direction
        if (nums[mid] > nums[mid + 1]) {
            // Descending slope: peak is to the left (including mid)
            right = mid;
        } else {
            // Ascending slope: peak is to the right (excluding mid)
            left = mid + 1;
        }
    }

    // When left == right, we've found the peak
    return left;
}
```

### 8.4: Minimum/Maximum Solution (Capacity Problems)


```cpp
/*
### Problem
Find the minimum capacity needed to complete a task within given constraints.

### Example: Ship Packages Within D Days
Find minimum weight capacity of ship to ship all packages within D days.

### Intuition
We can binary search on the answer space (capacity). The minimum possible capacity is the weight of the heaviest package (can't split packages). The maximum possible capacity is the sum of all weights (ship everything in one day).

### Key Insight
- **Lower bound**: Maximum single package weight
- **Upper bound**: Sum of all package weights  
- For each mid capacity, check if it's possible to ship within D days
- If possible, try smaller capacity; otherwise, increase capacity


**Time Complexity**: O(n * log(sum of weights))  
**Space Complexity**: O(1)
*/
// Helper function: Check if we can ship all packages within D days with given capacity
bool canShipWithCapacity(vector<int> &weights, int capacity, int days) {
    int currentWeight = 0;
    int daysNeeded = 1;
    
    for (int weight : weights) {
        // If adding current package exceeds capacity, ship on next day
        if (currentWeight + weight > capacity) {
            daysNeeded++;
            currentWeight = weight;  // Start new day with current package
            
            // If we exceed allowed days, this capacity is insufficient
            if (daysNeeded > days) {
                return false;
            }
        } else {
            currentWeight += weight;
        }
    }
    
    return true;
}

int shipWithinDays(vector<int> &weights, int days) {
    // Set search bounds
    int left = *max_element(weights.begin(), weights.end());    // Min capacity
    int right = accumulate(weights.begin(), weights.end(), 0);  // Max capacity

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canShipWithCapacity(weights, mid, days)) {
            right = mid;        // This capacity works, try smaller
        } else {
            left = mid + 1;     // This capacity insufficient, need larger
        }
    }
    
    return left;  // Minimum sufficient capacity
}
```


---

### 8.5: Minimize Max or Maximize Min (Binary search on answer space)

```cpp
/*


### Problem
Split array into K subarrays to minimize the maximum sum among all subarrays.

### Examples
- Split Array Largest Sum
- Painter Partition Problem  
- Book Allocation Problem

### Intuition
We binary search on the answer (maximum subarray sum). For each potential maximum sum, we check if it's possible to split the array into at most K subarrays where each subarray sum ≤ maximum sum.

### Key Insight
- **Lower bound**: Maximum single element (each element must be in some subarray)
- **Upper bound**: Sum of all elements (entire array as one subarray)
- **Monotonic property**: If we can split with max sum X, we can also split with max sum > X
- As maximum allowed sum decreases, number of required partitions increases


**Time Complexity**: O(n * log(sum of array))  
**Space Complexity**: O(1)
*/
// Helper: Count minimum partitions needed for given maximum subarray sum
int getMinPartitions(vector<int> &nums, int maxSum) {
    int currentSum = 0;
    int partitions = 1;
    
    for (int num : nums) {
        // Try to add current number to current partition
        if (currentSum + num <= maxSum) {
            currentSum += num;
        } else {
            // Current number doesn't fit, start new partition
            partitions++;
            currentSum = num;
        }
    }
    
    return partitions;
}

// Get the valid range for binary search
pair<int, int> getSearchBounds(vector<int> &nums) {
    // Lower bound: Maximum single element
    // (Each subarray must contain at least one element)
    int lowerBound = *max_element(nums.begin(), nums.end());
    
    // Upper bound: Sum of all elements  
    // (Entire array as single subarray)
    int upperBound = accumulate(nums.begin(), nums.end(), 0);
    
    return {lowerBound, upperBound};
}

int splitArrayMinimizeMax(vector<int> &nums, int k) {
    //Getting the bounds for answer space
    auto [left, right] = getSearchBounds(nums);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int partitionsNeeded = getMinPartitions(nums, mid);
        
        if (partitionsNeeded <= k) {
            // We can split with this max sum using ≤ k partitions
            // Try to minimize further
            right = mid;
        } else {
            // Need more than k partitions with this max sum
            // Increase the allowed maximum sum
            left = mid + 1;
        }
    }
    
    return left;  // Minimum possible maximum subarray sum
}
```
