// Single Element in a Sorted Array
// Problem statement
// You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.
// Return the number that appears once.

// Example:
// Input: 'arr' = [1,1,2,2,4,5,5]
// Output: 4 
// Explanation: 
// Number 4 only appears once the array.

// Note :
// Exactly one number in the array 'arr' appears once.

//Link : https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654

//APPROACH 1: Using XOR
//We know that A^A=0 and A^0=A
//So if we take the XOR of all the elements in the array, the elements which are present twice will cancel each other and the element which is present once will be left.
//Time complexity: O(n)
//Space complexity: O(1)

int singleNonDuplicate(vector<int> &arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans ^= arr[i];
    }
    return ans;
}

//APPROACH 2: Using Binary Search
//We can use binary search to find the element which is present once.
//On observing the array,we can see that elements on the left half of the single element are present form a pair at (even,odd) indices and elements on the right half of the single element are present form a pair at (odd,even) indices.
//So we can use this property to eliminate the halves of the array.
//Time complexity: O(logn)
//Space complexity: O(1)

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    //Checking for first and last element separately to avoid out edge cases within the loop.
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if (
            (mid % 2 == 1 && arr[mid] == arr[mid - 1])// if mid is odd and the element before mid is equal to mid then we are in the left half
            || 
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])// if mid is even and the element after mid is equal to mid then we are in the left half
            ) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
}
