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

---

## 💣 2. Brute Force Approach

### Example: Merging intervals

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<bool> merged(intervals.size(), false);
    vector<vector<int>> result;

    for (int i = 0; i < intervals.size(); i++) {
        if (merged[i]) continue;
        int start = intervals[i][0];
        int end = intervals[i][1];

        for (int j = i + 1; j < intervals.size(); j++) {
            if (max(start, intervals[j][0]) <= min(end, intervals[j][1])) {
                start = min(start, intervals[j][0]);
                end = max(end, intervals[j][1]);
                merged[j] = true;
            }
        }
        result.push_back({start, end});
    }

    return result;
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
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end()); // sort by start time
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            // Overlapping — merge
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            // No overlap — push new interval
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}
```

---

### ✅ Template: Insert and Merge a New Interval

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // Add all intervals ending before newInterval starts
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i++]);
    }

    // Merge overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    // Add the rest
    while (i < n) result.push_back(intervals[i++]);

    return result;
}
```

---

### ✅ Template: Minimum Number of Meeting Rooms

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> startTimes, endTimes;
    for (auto& interval : intervals) {
        startTimes.push_back(interval[0]);
        endTimes.push_back(interval[1]);
    }

    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int usedRooms = 0, endPtr = 0;

    for (int i = 0; i < startTimes.size(); i++) {
        if (startTimes[i] < endTimes[endPtr]) {
            usedRooms++;
        } else {
            endPtr++;
        }
    }

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

