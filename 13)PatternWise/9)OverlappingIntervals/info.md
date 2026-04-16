# Overlapping Intervals Pattern

## 🔍 1. When Should Overlapping Intervals Be Used?

### ✅ Use this pattern when:
- You’re given **intervals** (ranges defined by `[start, end]`) and asked to:
  - **Merge overlapping intervals**
  - **Insert and merge intervals**
  - **Find intersections**
  - **Determine the minimum number of rooms/resources required**
  - **Check for overlaps/conflicts**

### 🧠 Keywords to look for:
- “Intervals”
- “Merge overlapping intervals”
- “Insert interval”
- “Meeting rooms required”
- “Do intervals overlap?”
- “Find intersection of intervals”
- “Minimum number of platforms/rooms”

Theory :
1. Overlapping : 
   1. Condition for overlapping : max(start1,start2)< min(end1,end2)
   2. And overlap interval : [max(start1,start2),min(end1,end2)]


2. Merged interval : 
   1. If overlapping then combined merged interval is : [min(start1,start2),max(end1,end2)]
3. Gap (if exist): 
   1.[min(e1,e2),max(s1,s2)]

---

## 💣 2. Brute Force Approach

### Example: Merging intervals

#### Note: Overlap exists if <br/>max(start1,start2)<=min(end1,end2) <br/>and merged interval is <br/>[min(start,start2),max(end1,end2)]


```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Example input:
    // intervals = [[1,3], [2,6], [8,10], [15,18]]

    bool changed = true; 
    // This flag ensures we keep repeating until no more merges are possible

    while (changed) {
        changed = false;

        vector<bool> merged(intervals.size(), false);
        // merged = [false, false, false, false]

        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); i++) {

            // Skip if already merged into some previous interval
            if (merged[i]) continue;

            // Start with current interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // i = 0 → interval = [1,3]
            // start = 1, end = 3

            for (int j = i + 1; j < intervals.size(); j++) {

                // Skip if already consumed in this round
                if (merged[j]) continue;

                // Check overlap condition:
                // overlap exists if:
                // max(start1, start2) <= min(end1, end2)

                // j = 1 → interval = [2,6]
                // max(1,2) <= min(3,6) → 2 <= 3 → true (overlap)

                if (max(start, intervals[j][0]) <= min(end, intervals[j][1])) {

                    // Merge intervals
                    start = min(start, intervals[j][0]); // min(1,2) = 1
                    end = max(end, intervals[j][1]);     // max(3,6) = 6

                    // Now merged interval becomes [1,6]

                    merged[j] = true;
                    // merged = [false, true, false, false]

                    changed = true;
                    // Since a merge happened, we need another full pass
                    // to handle transitive overlaps like:
                    // [1,4], [2,3], [3,6]
                }

                // j = 2 → interval = [8,10]
                // max(1,8) <= min(6,10) → 8 <= 6 → false (no overlap)

                // j = 3 → interval = [15,18]
                // max(1,15) <= min(6,18) → 15 <= 6 → false (no overlap)
            }

            // Push merged interval for this pass
            result.push_back({start, end});
            // result = [[1,6]]
        }

        // After one full pass:
        // intervals may still have indirect overlaps remaining
        // Example:
        // [1,4], [2,3], [3,6]
        // First pass → [[1,4], [3,6]]
        // Second pass → [[1,6]]

        intervals = result;
        // Update intervals and repeat if 'changed == true'
    }

    // Final stable result (no more merges possible)
    return intervals;
}
```

### ⛔ Time: `O(n^2)`, Space: `O(n)`

---

## 🛠️ 3. How the Pattern Works + C++ Template

### 💡 Key Idea:
- **Sort intervals by starting time**.
- Then iterate and **merge if current interval overlaps with the previous one**.

---

### ✅ Template: Merge Overlapping Intervals

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Example input:
    // intervals = [[1,3], [8,10], [2,6], [15,18]]

    if (intervals.empty()) return {};

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    // After sorting:
    // intervals = [[1,3], [2,6], [8,10], [15,18]]

    vector<vector<int>> merged;

    // Step 2: Push first interval
    merged.push_back(intervals[0]);
    // merged = [[1,3]]

    for (int i = 1; i < intervals.size(); i++) {

        // Current interval
        // i = 1 → [2,6]

        // Compare with last merged interval
        // merged.back() = [1,3]

        if (intervals[i][0] <= merged.back()[1]) {
            // Overlap condition:
            // 2 <= 3 → true

            // Merge by updating end
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            // max(3,6) = 6

            // merged becomes [[1,6]]
        } else {
            // No overlap → push new interval
            merged.push_back(intervals[i]);
        }

        // i = 2 → [8,10]
        // Compare with merged.back() = [1,6]
        // 8 <= 6 → false → no overlap

        // merged = [[1,6], [8,10]]

        // i = 3 → [15,18]
        // Compare with merged.back() = [8,10]
        // 15 <= 10 → false → no overlap

        // merged = [[1,6], [8,10], [15,18]]
    }

    return merged;
}
```

---

### ✅ Template: Insert and Merge a New Interval

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // Example:
    // intervals = [[1,3], [6,9]]
    // newInterval = [2,5]

    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    //Ensure that the intervals are sorted by start time
    sort(intervals.begin(), intervals.end());

    // -----------------------------
    // STEP 1: Add all intervals BEFORE overlap
    // Condition: interval.end < newInterval.start
    // -----------------------------

    // i = 0 → [1,3]
    // 3 < 2 → false → stop

    //current interval end < new interval start
    //i.e. current interval ends before new interval starts
    // (Inital stage)
    /*
    intervals[i] :  [----]
    newInterval  :          [----]
    */
    while (i < n &&intervals[i][1] <newInterval[0]  ) {
        result.push_back(intervals[i++]);
    }

    // result = [] (nothing added yet)

    // -----------------------------
    // STEP 2: Merge overlapping intervals
    // Condition: interval.start <= newInterval.end
    // -----------------------------

    // i = 0 → [1,3]
    // 1 <= 5 → true → overlap

    //Current interval start <= New interval end 
    //I.e. all those intervals that are starting before new interval ends(Intermediate stage)
    /*
    intervals[i] :  [----]
    newInterval  :     [----]
    */
    while (i < n && intervals[i][0]<= newInterval[1]  )

    //OR, using the generic condition to check for overlap

     while (i < n && max(intervals[i][0], newInterval[0]) <= 
           min(intervals[i][1], newInterval[1]))
    
    {

        // Expand newInterval
        newInterval[0] = min(newInterval[0], intervals[i][0]); // min(2,1) = 1
        newInterval[1] = max(newInterval[1], intervals[i][1]); // max(5,3) = 5

        // newInterval becomes [1,5]

        i++;

        // i = 1 → [6,9]
        // 6 <= 5 → false → stop
    }

    // Push merged newInterval
    result.push_back(newInterval);
    // result = [[1,5]]

    // -----------------------------
    // STEP 3: Add remaining intervals AFTER overlap
    // (Final stage)
    // i.e. current interval start after the new interval has ended
    // -----------------------------

    // i = 1 → [6,9]
    // directly push

    while (i < n) result.push_back(intervals[i++]);

    // result = [[1,5], [6,9]]

    return result;
}
```

---

### ✅ Template: Minimum Number of Meeting Rooms

```cpp
// You are simulating this:
//1. If a meeting starts before the earliest one ends → need new room
//2. If it starts after or when one ends → reuse that room
int minMeetingRooms(vector<vector<int>>& intervals) {
    // Example:
    // intervals = [[0,30], [5,10], [15,20]]

    vector<int> startTimes, endTimes;

    // Step 1: Separate start and end times
    for (auto& interval : intervals) {
        startTimes.push_back(interval[0]);
        endTimes.push_back(interval[1]);
    }

    // startTimes = [0, 5, 15]
    // endTimes   = [30,10,20]

    // Step 2: Sort both arrays
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    // startTimes = [0, 5, 15]
    // endTimes   = [10, 20, 30]

    int usedRooms = 0, endPtr = 0;

    // Step 3: Traverse all meetings by start time
    for (int i = 0; i < startTimes.size(); i++) {

        // i = 0 → meeting starts at 0
        // compare with earliest ending meeting → endTimes[0] = 10

        if (startTimes[i] < endTimes[endPtr]) {
            // 0 < 10 → true → need a new room
            usedRooms++;
            // usedRooms = 1
        } else {
            // Not executed here
            endPtr++;
        }

        // i = 1 → start = 5
        // compare with endTimes[0] = 10

        // 5 < 10 → true → need new room
        // usedRooms = 2

        // i = 2 → start = 15
        // compare with endTimes[0] = 10

        // 15 < 10 → false → a meeting has ended
        // free one room → move endPtr
        // endPtr = 1

        // Now effectively reusing a room
        // (no increment in usedRooms)
    }

    // Final usedRooms = 2

    return usedRooms;
}
```

---

## 📚 4. Common Problems Based on Overlapping Intervals

### 🟢 Easy
- [Leetcode 252](https://leetcode.com/problems/meeting-rooms/) – Meeting Rooms (check for conflicts)

### 🟡 Medium
- [Leetcode 56](https://leetcode.com/problems/merge-intervals/) – Merge Intervals
- [Leetcode 57](https://leetcode.com/problems/insert-interval/) – Insert Interval
- [Leetcode 253](https://leetcode.com/problems/meeting-rooms-ii/) – Meeting Rooms II
- [Leetcode 986](https://leetcode.com/problems/interval-list-intersections/) – Interval List Intersections

### 🔴 Hard
- [Leetcode 759](https://leetcode.com/problems/employee-free-time/) – Employee Free Time
- [Leetcode 1235](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) – Max Profit in Job Scheduling (DP + Binary Search + intervals)

