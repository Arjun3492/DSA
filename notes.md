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

##### QUESTIONS: 
* ⬜ **Range Sum Query - Immutable**
  🔗 [https://leetcode.com/problems/range-sum-query-immutable/description/](https://leetcode.com/problems/range-sum-query-immutable/description/)
  🧠 Insight: We precompute the prefixSum array and then use it to return subArray sum between two indices

### 1.2 Prefix Sum with HashMap (Target Strategy)
Used to find count  of subarrays satisfying a given condition (e.g., count of subarray with sum = k or with k odd elements or sum divisible by K).
OR
To find the length of subarray satisfying a given condition(eg. max length of subarray having eq 0 and 1)

```cpp
int countSubarraysWithSumK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    int count = 0, prefixSum = 0;

    prefixCount[0] = 1; 
    // This allows counting subarrays 
    // whose sum equals k starting from the beginning
    // (when prefixSum itself becomes k)

    for (int num : nums) {
        prefixSum += num;

        int target = prefixSum-k;
        if (prefixCount.find(target) != prefixCount.end()) {
            count += prefixCount[target];
        }

        prefixCount[prefixSum]++;
    }

    return count;
}
```
##### QUESTIONS: 
* ⬜ **Subarray Sum Equals K**
  🔗 [Link](https://leetcode.com/problems/subarray-sum-equals-k)
  🧠 Insight: We store the prefixSum state as the key in map, then use it to find target prefixSum in subarray
* ⬜ **Subarray Sums Divisible by K**
  🔗 [Link](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)
  🧠 Insight: We store the remainder of the prefix sum modulo k as the key in a map and track how many times each remainder has appeared. If the same remainder occurs at two different indices, then the sum of the subarray between those indices is divisible by k. This is because equal remainders imply that the difference between the two prefix sums is a multiple of k.
* ⬜ **Count Number of Nice Subarrays/ Count of subarrays with k odd elements**
  🔗 [Link](https://leetcode.com/problems/count-number-of-nice-subarrays/description/)
  🧠 Insight: We store the count of odd elements so far , then use it to compute num of subarrays with odd numbers equal to target
* ⬜ **Contiguous Array with equal 0 and 1**
  🔗 [Link](https://leetcode.com/problems/contiguous-array/description/)
  🧠 Insight: For this we add -1 to prefix sum if we encounter 0 else 1, and store the first index of a computed sum in the map, so if the same sum is encountered ahead, we know the subarray in between contains equal number of 0 and 1's and is the longest since we only stored the index of first occurence against each sum in the map


#### Important observation in the map we store the key and frequency where key is what we need to store in order to solve the question , for example :
1. If the problem asks for subarrays with sum = k, we store the prefix sum as the key.
2. If the problem asks for subarrays with sum divisible by k, we store prefixSum % k (remainder) as the key.
3. If the problem asks for subarrays with exactly k odd numbers, we store the count of odd numbers encountered so far as the key.
4. If the problem asks for max length of subarray with a given sum , we store the first index of the prefix sum so far , so that if the required target is needed ahead we get the longest subarray in between

Note: In this prefixSum hashmap pattern we maintain three variable constrains:
1.  preFix hashMap //used to store the key and its occuring freq
2.  preFix Key// the key against which element need to be stored in hashmap, for example it could be preFixSum so far,preFixCountOfKOddElements so far, preFixReminder
3.  ans var to store the total count needed to be returned
4.  Generic Template is as follows:
```cpp
int fn(vector<int>&nums,k){
    unordered_map<int,int> mpp;//prefixHashMap
    mpp[0]=1 //account for subarrays starting from index 0
    int preFixSum=0;//prefixKey
    int ans=0;//ans needed to be returned
    for(int num:nums){
        preFixSum+=num;
        int target = preFixSum-k;
        if(mpp.find(target)!=mpp.end()){
            ans+=mpp[target];
        }
        mpp[preFixSum]++;
    }
    return ans;
}
```

---
---
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
##### QUESTIONS: 
* ⬜ **Merge Sorted Array**
  🔗 [Link](https://leetcode.com/problems/merge-sorted-array/description/)
  🧠 Insight: Since both the arrays too be merged are sorted, we use two pointer to traverse both the arrays , picking up the smaller of the two current elements and moving forward
* ⬜ **Two Sum**
  🔗 [Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)
  🧠 Insight: Since the array is sorted, we place two pointer one at starting and one at end respectively and try to find the pair by moving both the pointer inwards until the sum becomes equal to target
* ⬜ **Three Sum**
  🔗 [Link](https://leetcode.com/problems/3sum/submissions/1902994940/)
  🧠 Insight: We run a loop to fix an elements , then in each iteration we apply the two sum pair technique in the remaining array to find the triplet formed using the fixed element and the pair such that their sum equals target
   nums[i]+ nums[left] + nums[right]==target

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

//since we are moving inwards(reducing width), we move the pointer pointing to a smaller height hoping to find a larger limiting height
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}
```
* ⬜ **Container With Most Water**
  🔗 [Link](https://leetcode.com/problems/container-with-most-water/description/)
  🧠 Insight: We start with the widest container using two pointers at both ends.
    The area is always limited by the shorter height, so keeping it while reducing width cannot give a better result.
    To potentially increase the area, we move the pointer pointing to the smaller height, hoping to find a taller line.
    This way, we explore all promising containers in linear time.

* ⬜ **Trapping Rain Water**
  🔗 [Link](https://leetcode.com/problems/trapping-rain-water/description/)
  🧠 Insight:  
  Water trapped at any Block is given by
  min(leftMax,rightMax) - height of current block 
  i.e. Water trapped above any block is determined by the minimum of the maximum heights on its left and right, minus the block’s height.
\
  In brute force we can precompute the leftMax and rightMax for each index and use it using an auxillary extra vector  
\
  But in optimal approach to prevent extra space
   Using two pointers starting from both ends, we maintain leftMax and rightMax as the tallest boundaries seen so far. At each step, the side with the smaller maximum height becomes the limiting boundary, so the water trapped there is fixed and independent of the other side. If leftMax < rightMax, we compute water at the left pointer and move it inward; otherwise, we compute water at the right pointer and move it inward.


---
---
## 3. Sliding Window Approach

### 3.1 Fixed Size Window
Used to find the sum/avg/max/min of a fixed size window 
or
To check for fixed size windows satisfying a given condition(eg. checks for anagrams of string s1 and s2)

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

Note : Fixed window pattern can be written similar to dynamic pattern window like this

```cpp
int maxSumDynamic(vector<int>& nums, int k) {
    int left = 0, windowSum = 0, maxSum = 0;

    for (int right = 0; right < nums.size(); right++) {
        windowSum += nums[right];

        // apply dynamic window shrink condition on window length
        // shrink if size exceeds k
        while  (right - left + 1 > k) {
            windowSum -= nums[left];
            left++;
        }


        // updating ans only when window size == k
        if (right - left + 1 == k) {
            maxSum = max(maxSum, windowSum);
        }
    }

    return maxSum;
}

```
* ⬜ **Maximum Average Subarray I**
  🔗 [Link](https://leetcode.com/problems/maximum-average-subarray-i/description/)
  🧠 Insight: We prepare the solution to initial window of size k, then we add the new element to the right and remove the leftmost element of window keeping the size fixed as k, and we compute and compare the solution in the process
* ⬜ **Find All Anagrams in a String**
  🔗 [Link](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)
🧠 Insight: The basic idea to check if two strings are Anagrams of each other is too check if the len and count each characters in both the strings are equal, for this we can prepare two maps to store count of each char in the two strings and check for equality of both the maps, if they are equal they are anagrams
In this we can smartly use the fixed window size approach to modify the second map removing the count of leftMost char and adding the count of rightmost char and then comparing with the map of target string
Instead of maps we can use frequency vectors too to store count of each char using ascii index
```cpp
 vector<int> freq1(26, 0), freq2(26, 0);
 //if ch is lowercase
 freq1[ch-'a']++;
```

* ⬜ **Permutation in String**
  🔗 [Link](https://leetcode.com/problems/permutation-in-string/description/)
🧠 Insight: Same approach as above, we just check for count of chars in target string and the fixed window of string that is traversed 
  


### 3.2 Dynamic Size Window
Used to find the max/min length of window satisfying a given condition, where the condition is monotonic that is the condition can be restored by reducing the window size.

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

* ⬜ **Longest Substring Without Repeating Characters**
  🔗 [Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
  🧠 Insight: The main idea is to use a dynamic sliding window approach with a set or map to track characters in the current window. When a duplicate character is found, shrink the window from the left until no duplicates exist and keep updating the max length

* ⬜ **Minimum Size Subarray Sum**
  🔗 [Link](https://leetcode.com/problems/minimum-size-subarray-sum/description/)
  🧠 Insight: while moving the right pointer, we keep track of the current sum. If the sum is greater than or equal to target, we try to shrink the window from the left while maintaining the condition. “while (windowSum  >=k )“

* ⬜ **Max Consecutive Ones III**
  🔗 [Link](https://leetcode.com/problems/max-consecutive-ones-iii/description/)
  🧠 Insight: We frame the question in a way to find the max len of subarray with at most k 0(zeros), since we can flip at most k 0 so the longest subarray with atmost k 0 is our ans

---
---
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
    ListNode* slow = head, *fast = head;
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

---
---
## 5. Linked List In-Place Reversal~

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

---
---
## 6. Monotonic Stack

Used to find the:
1. Next Greater/Smaller Element 
2. Previous Greater/Smaller Element
3. Problems involving Height(Histogram), temperature(Cooler Day) or Price (Stock Span)


### 6.1 Next Greater/Smaller Element

```cpp
//NEXT GREATER ELEMENT
// In this approach we process the elements that are being popped
vector<int> nge(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        // if the stack is not empty && current element > top of stack
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            int topIndex = st.top();
            // current element is NGE of the top index element
            ans[topIndex] = nums[i];
            st.pop();

        }
        st.push(i); // push the current index to stack
    }
}

//PREVIOUS GREATER ELEMENT
vector<int> pge(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n-1; i >=0; i--)
    {
        // if the stack is not empty && current element > top of stack
        whiles (!st.empty() && nums[i] > nums[st.top()])
        {
            int topIndex = st.top();
            // current element is PGE of the top index element
            ans[topIndex] = nums[i];
            st.pop();
        }
        st.push(i); // push the current index to stack
    }
}
```
Similarly for NSE and PSE , the comparison operator with the current element will switch to <
-  if (!st.empty() && nums[i] < nums[st.top()])

Note: 
| Problem                        | Traversal    | Condition in while loop     | Stack type |
| ------------------------------ | ------------ | --------------------------- | ---------- |
| Next Greater Element (NGE)     | Left → Right | `nums[i] > nums[st.top()]`  | Decreasing |
| Next Smaller Element (NSE)     | Left → Right | `nums[i] < nums[st.top()]`  | Increasing |
| Previous Greater Element (PGE) | Right → Left | `nums[i] > nums[st.top()]` | Decreasing |
| Previous Smaller Element (PSE) | Right → Left | `nums[i] < nums[st.top()]` | Increasing |

Greater problems → Decreasing stack
Smaller problems → Increasing stack

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

* ⬜ **Next Greater Element I**
  🔗 [Link](https://leetcode.com/problems/next-greater-element-i/description/)
  🧠 Insight: Stack stores unresolved indices. When a better element arrives, resolve all smaller/greater elements on the stack.

    1️⃣ Pop phase
    - While the stack is not empty and the current element satisfies the problem condition
    (e.g., >, <, >=, <=),
    the current element becomes the answer for the stack top → pop it.

    2️⃣ Push phase
    - Push the current index because its answer will be found later.
    <br>
* ⬜ **Daily Temperatures**
  🔗 [Link](https://leetcode.com/problems/daily-temperatures/description/)
  🧠 Insight: Treat it as a Next Greater Element problem. Use a stack to store indices of days whose warmer day hasn't been found. When a warmer temperature appears, pop the index and compute the wait as:
    - days = currentIndex − poppedIndex.
    <br>
* ⬜ **Largest Rectangle in Histogram**
  🔗 [Link](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)
  🧠 Insight: Area formed by a given rectangle at index i , is given as height[i] * (nextSmallerElementIdx - previousSmallerElementIdx - 1), so we combine both nse and pse approach to solve this problem.
  And in optimal approach When an element is popped from the increasing stack, the current index i becomes its NSE, and the new stack top becomes its PSE, allowing us to compute the rectangle width and area immediately. 
    <br>



---
---
## 7. Top K elements (Priority Queue)

Used when we need to find the top k elements based on a given metric

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

* ⬜ **Kth Largest Element in a Stream**
  🔗 [Link](https://leetcode.com/problems/kth-largest-element-in-a-stream)
  🧠 Insight: As we process the stream, each element is inserted into a **min-heap**. If the heap size exceeds **k**, we remove the top element (the smallest). This ensures the heap always keeps the **k largest elements**, since the smaller **n − k** elements are discarded during traversal. <br>

* ⬜ **Top K Frequent Elements**
  🔗 [Link]([Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements))
  🧠 Insight: First, we use a **map** to compute the frequency of each element. Then we traverse the map and push **(frequency, element)** pairs into a **min-heap**. Whenever the heap size exceeds **k**, we remove the top pair (the least frequent at that moment). After processing all pairs, the heap contains the **k most frequent elements**. <br>

* ⬜ **K Closest Points to Origin**
  🔗 [Link](https://leetcode.com/problems/k-closest-points-to-origin)
  🧠 Insight: We iterate through all points and push **(distance, point)** pairs into a **max-heap**. If the heap size exceeds **k**, we remove the top element (the farthest point). This way, the heap always maintains the **k closest points to the origin** based on their distance. <br>

---
---
## 8. Binary Search Technique

Used whenever the search space is ordered/monotonic and we can eliminate half the possibilities at each step.

When to Use Binary Search
1. **Sorted Array Problems**: Find target or its First/Last occurrence sorted search space
2. **Boundary Problems**: Find Boundary elements (Floor/Ceil/Peak) in mountain arrays(i.e. having directional property (increasing/decreasing))
3. **Optimization Problems**: Minimum/maximum solution to a problem within given constraints
4. **Partition Problems**: Minimize max value or maximize min value of partitions


####  Binary Search Rule of Thumb

#### 1️⃣ When searching for an **exact element**

Use:

```cpp
while (left <= right)
```

* The search space is a **closed interval `[left, right]`**.
* In every iteration, **`mid` is discarded from the search space**:

  * `left = mid + 1`
  * `right = mid - 1`
* This guarantees the search space **strictly shrinks**, so `left` and `right` will eventually **cross each other (`left > right`)**.

Since the final answer might be lost while shrinking the search space, we usually **store a candidate answer in a separate variable (`ans`)** and return it.

---

#### 2️⃣ When searching for a **boundary (first/last occurrence)**

Use:

```cpp
while (left < right)
```

* The search space **shrinks toward the boundary**.
* Here, **`mid` may remain in the search space** because it might still be the correct answer.

Two common cases:

**First Occurrence / Minimum / First True**

```cpp
while(left < right){
    mid = left + (right-left)/2;   // LEFT-biased mid to prevent infinite loop when left and right are adjacent

    if(isFeasible(mid))
        right = mid;
    else
        left = mid + 1;
}
```

* `mid` might be the **first valid position**, so we **keep it** in the search space.

---

**Last Occurrence / Maximum / Last True**

```cpp
while(left < right){
    // RIGHT-biased mid to prevent infinite loop when left and right are adjacent
    mid = left + (right-left+1)/2;   

    if(isFeasible(mid))
        left = mid;
    else
        right = mid - 1;
}
```

* `mid` might be the **last valid position**, so we **keep it** in the search space.

---

At the end of the loop:

```cpp
left == right
```

So we can directly return:

```cpp
return left;  // or right (both are same)
```

---

✅ **Short Memory Trick**

* **Exact search →** `left <= right` → discard `mid`
* **Boundary search →** `left < right` → keep `mid` when it might be the answer
* **End condition:** boundary search always converges to `left == right`

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
        int mid = left + (right - left) / 2;//overflow safe

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
    
    while (left < right) {
        int mid = left + (right - left) / 2; // LEFT-biased mid to prevent infinite loop when left and right are adjacent
        
        if (target<= nums[mid]) {
            right = mid ;     
        } 
        else {
            left = mid + 1;
        }
    }
    
    return left;
}

int findLastOccurrence(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left+1) / 2; // RIGHT-biased mid to prevent infinite loop when left and right are adjacent
        if (target>= nums[mid]) {
            left = mid;
        } 
        else {
            right = mid - 1;        
        }
    }
    
    return left;
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
### Below are problems involving BS application on the answer search space
Template for the same:

```cpp
//Utility method to retrieve the answer search space
pair<int,int> getSearchSpace(const vector<int>& arr) {
    int low  = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    return {low, high};
}

//Utility method to check if current solution is feasible
bool isFeasible(const vector<int>& arr, int limit, int maxGroups) {
    int groupsUsed = 1;
    int currentGroupSum = 0;

    for (int value : arr) {
        if (currentGroupSum + value > limit) {
            groupsUsed++;
            currentGroupSum = value;

            if (groupsUsed > maxGroups)
                return false;
        } else {
            currentGroupSum += value;
        }
    }

    return true;
}

int solve(vector<int> &nums, int k) {

    // Step 1: Define answer search space
    auto [left, right] = getSearchBounds(nums);

    while (left < right) {

        int mid = left + (right - left) / 2;

        // Step 2: Check if this answer is feasible
        bool isFeasible = isFeasible(nums, mid, k);

        if (isFeasible) {
            // mid could be a possible answer, but we look for better smaller value
            right = mid;
        } 
        else {
            // mid too small / invalid → increase answer
            left = mid + 1;
            //mid cannot be the answer so we discard it from search space
        }
    }

    // Step 3: Final answer
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

// Step 1: Get search space bounds
pair<int,int> getSearchSpace(const vector<int>& arr) {
    int low  = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    return {low, high};
}

// Step 2: Feasibility check (checkFeasibility)
bool isFeasible(const vector<int>& arr, int limit, int maxGroups) {

    // limit      -> ship capacity
    // maxGroups  -> allowed days
    // groupsUsed -> days used
    // currentGroupSum -> current shipped weight in a day

    int currentGroupSum = 0;
    int groupsUsed = 1;

    for (int value : arr) {

        // If adding current package exceeds capacity, ship on next day
        if (currentGroupSum + value > limit) {

            groupsUsed++;
            currentGroupSum = value;  // Start new day with current package

            // If we exceed allowed days, this capacity is insufficient
            if (groupsUsed > maxGroups) {
                return false;
            }

        } else {
            currentGroupSum += value;
        }
    }

    return true;
}

int shipWithinDays(vector<int> &weights, int days) {

    // Step 1: Define search bounds (getSearchBounds)
    auto [left,right] = getSearchSpace(weights);

    while (left < right) {

        int mid = left + (right - left) / 2;

        // Step 2: Check feasibility of current answer
        bool feasible = isFeasible(weights, mid, days);

        // Step 3: Adjust search space
        if (feasible) {
            right = mid;       // mid works → try smaller capacity
        } else {
            left = mid + 1;    // mid insufficient → increase capacity
        }
    }

    // Step 4: Return optimal answer
    return left;   // Minimum sufficient capacity
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

// Step 1: Define search space (getSearchBounds)
pair<int,int> getSearchSpace(const vector<int>& arr) {

    // Lower bound: Maximum single element
    // (Each subarray must contain at least one element)
    int low = *max_element(arr.begin(), arr.end());

    // Upper bound: Sum of all elements  
    // (Entire array as single subarray)
    int high = accumulate(arr.begin(), arr.end(), 0);

    return {low, high};
}

// Step 2: Feasibility helper (checkFeasibility)
bool isFeasible(const vector<int>& arr, int limit, int maxGroups) {

    // limit      -> allowed maximum subarray sum
    // maxGroups  -> maximum partitions allowed (k)
    // groupsUsed -> partitions formed
    // currentGroupSum -> current partition sum

    int currentGroupSum = 0;
    int groupsUsed = 1;

    for (int value : arr) {

        // Try to add current number to current partition
        if (currentGroupSum + value > limit) {

            // Current number doesn't fit, start new partition
            groupsUsed++;
            currentGroupSum = value;

            // If partitions exceed k, this limit is not feasible
            if (groupsUsed > maxGroups) {
                return false;
            }

        } else {
            currentGroupSum += value;
        }
    }

    return true;
}

int splitArrayMinimizeMax(vector<int> &nums, int k) {

    // Step 1: Getting the bounds for answer space
    auto [left, right] = getSearchSpace(nums);

    while (left < right) {

        int mid = left + (right - left) / 2;

        // Step 2: Evaluate feasibility of candidate answer
        bool feasible = isFeasible(nums, mid, k);

        // Step 3: Adjust search space
        if (feasible) {

            // We can split with this max sum using ≤ k partitions
            // Try to minimize further
            right = mid;

        } else {

            // Need more than k partitions with this max sum
            // Increase the allowed maximum sum
            left = mid + 1;
        }
    }

    // Step 4: Return optimal answer
    return left;  // Minimum possible maximum subarray sum
}
```

---
---
## 9 Overlapping Intervals

### Overlapping interval Pattern Summary

| Pattern         | Key Idea            |
| --------------- | ------------------- |
| Merge Intervals | Sort + Greedy merge |
| Insert Interval | 3-phase processing  |
| Line Sweep      | Convert to events   |


#### Universal Overlap Condition (VERY IMPORTANT)

Use this in almost every interval problem:

```cpp
// Two intervals [a, b] and [c, d] overlap if:
if (max(a,c) <= min(b,d))
```

Or simplified (when sorted):

```cpp
if (curr_start <= prev_end)
```

---

### 9.1 Merge Overlapping Intervals / Select non overlapping Intervals
#### Used when:

* Given **random intervals → merge overlapping ones**
* Need **non-overlapping result**
* Problems asking for:

  * “merge intervals”
  * “combine overlapping ranges”
* Core idea: **Sort + Greedy merge**

#### Template:

```cpp
// 🔹 INTUITION:
// 1. Sort intervals by start time
// 2. Keep a result array
// 3. Compare current interval with last merged interval
//    - If overlap → merge
//    - Else → push new interval

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Step 1: Sort by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    // Step 2: Add first interval
    ans.push_back(intervals[0]);

    // Step 3: Traverse remaining intervals
    for (int i = 1; i < intervals.size(); i++) {

        vector<int>& last = ans.back();     // last merged interval
        vector<int>& curr = intervals[i];   // current interval

        // Step 4: Check overlap:
        // Current is starting on or before previous ending
        if (curr[0] <= last[1]) {
            // Merge by updating end
            last[1] = max(last[1], curr[1]);
        } else {
            // No overlap → add new interval
            ans.push_back(curr);
        }
    }

    return ans;
}
```


#### Questions
* ⬜ **Merge Intervals**
  🔗 [Link](https://leetcode.com/problems/merge-intervals/)
  🧠 Insight: We first sort the intervals by start time and then while traversing the intervals we check if its starts before the previous one ends(overlap) then we merge the interval and add the merged interval to the final list else add the non overlapping interval to the list as it is

* ⬜ **Minimum Number of Arrows to Burst Balloons**
  🔗 [Link](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
  🧠 Insight: Minimum number of arrows to burst balloons = "Maximum overlapping intervals" 
  To find max non overlapping intervals we sort by end and then check if current interval is not overlapping with the last end, if not we increment count and update the last end

  **Note**: We sort by end so we free up space as early as possible, maximizing room for future intervals.
```cpp
int maxNonOverlapping(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // 1. Sort by end time (greedy choice)
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });

    int count = 1;                         // first interval is always taken
    int prevEnd = intervals[0][1];         // end of last chosen interval

    // 2. Traverse intervals
    for (int i = 1; i < intervals.size(); i++) {

        // if non-overlapping → take it
        if (intervals[i][0] >= prevEnd) {  // use >= for inclusive intervals
            count++;
            prevEnd = intervals[i][1];     // update last end
        }
        // else → overlap → skip
    }

    return count;
}
```

* ⬜ **Non-overlapping Intervals(Num of min overlapping intervals)**
  🔗 [Link](https://leetcode.com/problems/non-overlapping-intervals/)
  🧠 Insight: Minimum number of overlapping interval(needed to remove) = Total intervals - number of non-overlapping intervals (same as above)
---

### 9.2 Insert and Merge Interval

#### Used when:

* Given:

  * **sorted non-overlapping intervals**
  * * **1 new interval**
* Need to:

  * Insert at correct position
  * Merge overlaps
* Pattern: **3 phases**

  1. Add non-overlapping left
  2. Merge overlapping
  3. Add remaining right


#### Template:

```cpp
// 🔹 INTUITION:
// Divide into 3 parts:
// 1. Add all intervals before overlap
// 2. Merge overlapping intervals
// 3. Add remaining intervals

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();

    // Step 1: Add all intervals completely before newInterval
    //i.e. Current interval ends before new interval starts
    // (Initial stage)
    /*
    intervals[i] :  [----]
    newInterval  :          [----]
    */
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge all overlapping intervals
    //I.e. all those intervals that are starting before new interval ends[Overlapping condition:current starting before previous end]
    //(Intermediate stage)
    /*
    intervals[i] :  [----]
    newInterval  :     [----]
    */
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    // Step 3: Add remaining intervals
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}
```

---

#### Questions

* ⬜ **Insert Interval**
  🔗 [https://leetcode.com/problems/insert-interval/](https://leetcode.com/problems/insert-interval/)
  🧠 Insight: 3-phase merging

* ⬜ **Interval List Intersections**
  🔗 [https://leetcode.com/problems/interval-list-intersections/](https://leetcode.com/problems/interval-list-intersections/)
  🧠 Insight: Two pointer overlap logic


### 9.3 Line Sweep Algo

#### Used when:

* When you need:

  * **Max overlapping intervals**
  * **Min resources required**
  * **Concurrent events**
* Problems like:

  * Meeting rooms
  * Max guests in party
* Core idea:
  👉 Convert intervals → **events (start +1, end -1)**
  👉 Sort events → sweep line

---

#### Template:

```cpp
// 🔹 INTUITION:
// Convert intervals into events:
// start → +1 (resource needed)
// end   → -1 (resource freed)
// Sort events → process in order → track max overlap

int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;

    // Step 1: Create events
    for (auto& interval : intervals) {
        events.push_back({interval[0], +1}); // start
        events.push_back({interval[1], -1}); // end
    }

    // Step 2: Sort events
    // If same time → end (-1) should come before start (+1)
    sort(events.begin(), events.end(), [](auto& a, auto& b) {
        if (a.first == b.first)
            return a.second < b.second; // -1 before +1
        return a.first < b.first;
    });

    int curr = 0, maxRooms = 0;

    // Step 3: Sweep line
    for (auto& event : events) {
        curr += event.second;            // update active intervals
        maxRooms = max(maxRooms, curr);  // track max overlap
    }

    return maxRooms;
}
```

---

#### Questions


* ⬜ **Meeting Rooms II**
  🔗 [https://leetcode.com/problems/meeting-rooms-ii/](https://leetcode.com/problems/meeting-rooms-ii/)
  🧠 Insight: Min rooms = max overlap

---
---
## 10. Binary Tree Traversal
### 10.1 PreOrder DFS (Root → Left → Right)
#### Used when:
* You need to **create/copy a tree**
* Useful in **serialization/deserialization**
* When **root must be processed before children**
* Problems involving **top-down propagation (path, prefix building)**

#### Template:
```cpp
// 1. Recursive Approach
// Intuition:
// Process current node first, then recursively go left and right.
// This mimics "Root → Left → Right"

void preOrder(Node* root, vector<Node*>& ans) {
    if (!root) return;

    ans.push_back(root);        // Step 1: Process current node
    preOrder(root->left, ans);  // Step 2: Traverse left subtree
    preOrder(root->right, ans); // Step 3: Traverse right subtree
}

// 2. Iterative Approach
// Intuition:
// Use stack (LIFO). Push right first so left is processed first.

vector<Node*> preOrder(Node* root) {
    if (!root) return {};

    stack<Node*> st;
    vector<Node*> ans;

    st.push(root); // Start with root

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        ans.push_back(node); // Process node

        // Push right first (so left is processed first)
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }

    return ans;
}
```
#### Questions for PreOrder:

* ⬜ **Binary Tree Preorder Traversal**
  🔗 [https://leetcode.com/problems/binary-tree-preorder-traversal/](https://leetcode.com/problems/binary-tree-preorder-traversal/)
  🧠 Insight: Direct traversal template application

* ⬜ **Same Tree**
  🔗 [https://leetcode.com/problems/same-tree/](https://leetcode.com/problems/same-tree/)
  🧠 Insight: Compare structure + values using DFS

* ⬜ **Path Sum**
  🔗 [https://leetcode.com/problems/path-sum/](https://leetcode.com/problems/path-sum/)
  🧠 Insight: Top-down propagation of remaining sum

* ⬜ **Construct Binary Tree from Preorder and Inorder Traversal**
  🔗 [https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
  🧠 Insight: Preorder gives root, inorder splits left/right

---

### 10.2 InOrder DFS (Left → Root → Right)
#### Used when:
* For **BST → gives sorted order**
* When you need **increasing/decreasing sequence**
* Problems involving **kth smallest/largest**
* Validate **BST property**
#### Template

```cpp
// 1. Recursive Approach
// Intuition:
// First go left (small values), then process node, then right.

void inOrder(Node* root, vector<Node*>& ans) {
    if (!root) return;

    inOrder(root->left, ans);  // Step 1: Traverse left subtree
    ans.push_back(root);       // Step 2: Process node
    inOrder(root->right, ans); // Step 3: Traverse right subtree
}

// 2. Iterative Approach
// Intuition:
// Go as left as possible, then process node, then go right.

vector<Node*> inOrder(Node* root) {
    vector<Node*> ans;
    stack<Node*> st;
    Node* curr = root;

    while (curr || !st.empty()) {

        // Step 1: Go to extreme left
        if (curr) {
            st.push(curr);
            curr = curr->left;
        }else{
            // Step 2: Process node
            curr = st.top();
            st.pop();
            ans.push_back(curr);
    
            // Step 3: Move to right subtree
            curr = curr->right;
        }

    }

    return ans;
}
```
#### Questions for InOrder:

* ⬜ **Binary Tree Inorder Traversal**
  🔗 [https://leetcode.com/problems/binary-tree-inorder-traversal/](https://leetcode.com/problems/binary-tree-inorder-traversal/)
  🧠 Insight: Direct template

* ⬜ **Validate Binary Search Tree**
  🔗 [https://leetcode.com/problems/validate-binary-search-tree/](https://leetcode.com/problems/validate-binary-search-tree/)
  🧠 Insight: Inorder must be strictly increasing

* ⬜ **Kth Smallest Element in a BST**
  🔗 [https://leetcode.com/problems/kth-smallest-element-in-a-bst/](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
  🧠 Insight: Inorder traversal index

* ⬜ **Recover Binary Search Tree**
  🔗 [https://leetcode.com/problems/recover-binary-search-tree/](https://leetcode.com/problems/recover-binary-search-tree/)
  🧠 Insight: Detect swapped nodes via inorder anomaly

---

### 10.3 PostOrder DFS (Left → Right → Root)

#### Used when:
* When **children must be processed before parent**
* Useful in **deletion of tree**
* Problems like **diameter, height, DP on trees**
* Bottom-up computations

#### Template

```cpp
// 1. Recursive Approach
// Intuition:
// First solve left and right subtrees, then process root.

void postOrder(Node* root, vector<Node*>& ans) {
    if (!root) return;

    postOrder(root->left, ans);   // Step 1: Left subtree
    postOrder(root->right, ans);  // Step 2: Right subtree
    ans.push_back(root);          // Step 3: Process node
}


// 2. Iterative (2 Stacks)
// Intuition:
// Reverse of preorder (Root → Right → Left)
// Then reverse result to get Left → Right → Root

vector<Node*> postOrder(Node* root) {
    if (!root) return {};

    stack<Node*> st1, st2;
    vector<Node*> ans;

    st1.push(root);

    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();

        st2.push(node);

        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        ans.push_back(st2.top());
        st2.pop();
    }

    return ans;
}

// 3. Iterative (1 Stack)
// Intuition:
// Track last visited node to know if right subtree is processed.

vector<Node*> postOrder(Node* root) {
    if (!root) return {};

    vector<Node*> ans;
    stack<Node*> st;
    Node* curr = root;
    Node* lastVisited = nullptr;

    while (curr || !st.empty()) {

        if (curr) {
            //go extreme left
            st.push(curr);
            curr = curr->left;
        } else {
            Node* node = st.top();

            // If right exists and not processed , go right
            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                //process node and update lastVisited
                ans.push_back(node);
                st.pop();
                lastVisited = node;
            }
        }
    }

    return ans;
}
```
#### Questions for PostOrder:

* ⬜ **Binary Tree Postorder Traversal**
  🔗 [https://leetcode.com/problems/binary-tree-postorder-traversal/](https://leetcode.com/problems/binary-tree-postorder-traversal/)
  🧠 Insight: Template

* ⬜ **Diameter of Binary Tree**
  🔗 [https://leetcode.com/problems/diameter-of-binary-tree/](https://leetcode.com/problems/diameter-of-binary-tree/)
  🧠 Insight: Bottom-up height calculation

* ⬜ **Binary Tree Maximum Path Sum**
  🔗 [https://leetcode.com/problems/binary-tree-maximum-path-sum/](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
  🧠 Insight: Postorder DP

---

### 10.4 BFS – Level Order Traversal

#### Used when:

* When traversal is **level by level**
* Shortest path in **unweighted tree/graph**
* Problems involving:

  * **Level grouping**
  * **Zigzag traversal**
  * **Minimum depth**

---

#### Template :

```cpp
// Intuition:
// Use queue (FIFO). Process nodes level by level.

vector<int> bfs(Node* root) {
    if (!root) return {};

    queue<Node*> q;
    vector<int> ans;

    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        ans.push_back(node->val); // Process node

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return ans;
}
```

#### Questions for Level Order:

* ⬜ **Binary Tree Level Order Traversal**
  🔗 [https://leetcode.com/problems/binary-tree-level-order-traversal/](https://leetcode.com/problems/binary-tree-level-order-traversal/)
  🧠 Insight: Classic BFS

* ⬜ **Binary Tree Zigzag Level Order Traversal**
  🔗 [https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
  🧠 Insight: Alternate direction per level

* ⬜ **Minimum Depth of Binary Tree**
  🔗 [https://leetcode.com/problems/minimum-depth-of-binary-tree/](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
  🧠 Insight: First leaf encountered in BFS

* ⬜ **Serialize and Deserialize Binary Tree**
  🔗 [https://leetcode.com/problems/serialize-and-deserialize-binary-tree/](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
  🧠 Insight: Level order encoding

---
---