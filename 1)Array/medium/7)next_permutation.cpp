// Problem Statement:
// Given an array Arr[] of integers, rearrange the numbers of the given array into the
// lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order
// (i.e., sorted in ascending order).

// USING STL library internal function
vector<int> nextGreaterPermutation(vector<int> &A)
{
    // Write your code here.
    next_permutation(A.begin(), A.end());
    return A;
}

// Optimal(internal implementation of next_permutation method from stl library)
// Consider the example 1,2,3,5,4
// The next greater permutation would be 1,2,4,3,5
// for this first find the pivot point..i.e. where the next element would be greater (starting from right side-since next most permutation will have longest same prefix )
// swap the element at pivot point with next largest element in the right subarray(right subarray is ascending so loop from i=n-1 to i>pivot)
// then simply reverse the subarray array to find the next possible sub array
// Tc:O(n)
// Sc:O(1)

vector<int> nextGreaterPermutation(vector<int> &A)
{
    // Write your code here.
    int pivot = -1;
    int n = A.size();

    // Step1:Find the break-point, i
    // Break-point means the first index i from the back of the given array
    // where arr[i] becomes smaller than arr[i+1].
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // If there is no break-point, then the given permutation is the last permutation.
    // i.e. all the digits are in descending order starting from rightside
    if (pivot == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step2:Find the number which is just greater than the number at break-point
    // since numbers on the right side of break-point are in ascending order
    // we will loop from the back and find the first number greater than the number at break-point
    // and swap the two numbers
    for (int i = n - 1; i > pivot; i--)
    {
        if (A[i] > A[pivot])
        {
            swap(A[i], A[pivot]);
            break;
        }
    }
    // Step3: Reverse the subarray to the right of the break-point
    reverse(A.begin() + pivot + 1, A.end());
    return A;
}
