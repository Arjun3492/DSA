# BINARY SEARCH 

# BS is generally used to solve a problem when:
## 1. The input is sorted
## 2. The problem needs to find a certain element in the input
## 3. Optimize the solution to O(logn)

## The basic idea of BS is to divide the input into half by eliminating the other half based on the condition of the problem.

## For example, if the input is sorted in ascending order, and we need to find a certain element, we can compare the middle element of the input with the target element. If the middle element is greater than the target, we can eliminate the right half of the input, and vice versa. We can keep doing this until we find the target element or the input is empty.

## Steps to solve a problem using BS:
### 1. Sort the input if it is not sorted
### 2. Compare the middle element with the target element
### 3. Eliminate the half of the input based on the comparison


## General structure of BS:

``` cpp

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = right - (right - left) / 2;
        if (nums[mid] == target) return mid; //compare the middle element with the target
        else if (nums[mid] < target) left = mid + 1; // eliminate the left half
        else right = mid - 1; // eliminate the right half
    }
    return -1;
}

```