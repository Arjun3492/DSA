// Intuition : In quick sort ,we take an element as pivot in the current
//  subarray and place it at its correct position such that
//  elements to left <= pivot el < elements to left
//  then we repeat this for each subarray left and right to the pivot,
//  which recursively sorts our array

// TC: O(nlogn)
// SC : O(n) Fn Stack space

// we take last index as the pivot index ,
// and then use a pointer index to place all elements less
// than it towards left , then place the pivot index element
// at the current position of pointer index, making all the elements
// the right larger than it
int getPivotIndex(vector<int> &arr, int start, int end)
{
    int pivotEl = arr[end];

    int pointerIndex = start;
    for (int i = start; i < end; i++)
    {
        int currEl = arr[i];
        if (arr[i] < pivotEl)
        {
            swap(arr[i], arr[pointerIndex]);
            pointerIndex++;
        }
    }
    swap(arr[end], arr[pointerIndex]);
    return pointerIndex;
}

// in quick sort we use the intuition that while getting the pivot array, we place the element at the pivot index at its correct position then move to do the same for left and right subarrays , recursively sorting all
void quickSort(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end)
        return;
    int partIndex = getPivotIndex(arr, start, end);
    quickSort(arr, start, partIndex - 1); // calling method left of pivot
    quickSort(arr, partIndex + 1, end);   //  calling method right of pivot
}