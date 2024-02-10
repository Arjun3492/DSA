// Merge two Sorted Arrays Without Extra Space
// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in
// non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the
// first N elements and modify arr2 so that it contains the last M elements.

// Example:
// Input:
// arr1[] = {1, 3, 5, 7}
// arr2[] = {0, 2, 6, 8, 9}
// Output:
// arr1[] = {0, 1, 2, 3}
// arr2[] = {5, 6, 7, 8, 9}
// Explanation: After merging the two arrays, we get the first N elements in arr1 and the last M elements in arr2.

// BRUTE FORCE APPROACH(Using extra space)
//  We will create a new array and merge the two arrays in sorted order
//  for this we will use two pointers to iterate over the two arrays and keep comparing the elements
//  and store the smaller element in the new array
//  Finally we will copy the elements from the new array to the original arrays
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,
                                           vector<long long> &b)
{
    int n = a.size(), m = b.size();
    vector<long long> c(n + m);
    int i = 0, j = 0, k = 0;
    // merge the two arrays, a and b into c using two pointers
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < n)
    {
        c[k++] = a[i++];
    }
    while (j < m)
    {
        c[k++] = b[j++];
    }

    // copy the elements from c to a and b
    for (int i = 0; i < n; i++)
    {
        a[i] = c[i];
    }
    for (int i = 0; i < m; i++)
    {
        b[i] = c[n + i];
    }
}

// OPTIMAL APPROACH 1:
//   We will use the concept of gap method to merge the two arrays in sorted order
//   We will start with the initial gap as the sum of the lengths of the two arrays
//   Then we will keep reducing the gap by half and keep comparing the elements
//   and store the smaller element in the first array and the larger element in the second array
//   Time complexity: O((n+m)*log(n+m))
//   Space complexity: O(1)

void swapFn(vector<long long> &a, vector<long long> &b, int id1, int id2)
{
    if (a[id1] > b[id2])
        swap(a[id1], b[id2]);
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,
                                           vector<long long> &b)
{
    int n = a.size(), m = b.size();

    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // case 1: left in a[]
            // and right in b[]:
            if (left < n && right >= n)
            {
                swapFn(a, b, left, right - n);
            }
            // case 2: both pointers in b[]:
            else if (left >= n)
            {
                swapFn(b, b, left - n, right - n);
            }
            // case 3: both pointers in a[]:
            else
            {
                swapFn(a, a, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1)
            break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

// OPTIMAL APPROACH 2:
// We will use two pointers left and right,
// left will traverse first array from left to right
// right will traverse second array from right to left
// If the element at left is greater than the element at right, then we will swap the elements
// else we will break the loop(As the elements are already in sorted order,we do not need to check for further elements)
// Finally we will sort the two arrays

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,
                                           vector<long long> &b)
{
    int n = a.size(), m = b.size();
    int left = n - 1, right = 0;
    while (left > 0 && right < m)
    {
        if (a[left] > b[right])
        // If the element at left is greater than the element at right, then we will swap the elements
        {
            swap(a[left], b[right]);
        }
        else
            // else we will break the loop(As the elements are already in
            // sorted order,we do not need to check for further elements)
            break;
        // update the pointers
        left--;
        right++;
    }
    // finally we will sort the two arrays

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}