// intuition : we keep dividing array until single elements, and
//  during backtracking we merge the sub arrays into sorted larger subarray
//  using two pointer technique

// TC : O(nlogn)
// SC : O(n)

// merges the two halves
//  1. low to mid
//  2. mid+1 to high
//  into a sorted array using two pointer approach
void merge(vector<int> &arr, int low, int mid, int high)
{
    // temp vector
    vector<int> temp;
    int i = low;     // first pointer @ start of first half
    int j = mid + 1; // second pointer @ start of second half
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            // pushing smaller into temp and updating pointer
            temp.emplace_back(arr[i]);
            i++;
        }
        else
        {
            temp.emplace_back(arr[j++]);
        }
    }

    // handling extra elements if any
    while (i <= mid)
    {
        temp.emplace_back(arr[i++]);
    }

    while (j <= high)
    {
        temp.emplace_back(arr[j++]);
    }
    int n = temp.size();

    // storing temp elements in original array
    for (int i = 0; i < n; i++)
    {
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    // find mid
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
