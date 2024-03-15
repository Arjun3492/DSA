// Allocate Books
// Problem statement
/// There are ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
// If the allocation of books is not possible, return -1.

// Example:
// Input: ‘n’ = 4 ‘m’ = 2
// ‘arr’ = [12, 34, 67, 90]
// Output: 113
// Explanation: All possible ways to allocate the ‘4’ books to '2' students are:
// 12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.
// 12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.
// 12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.
// We are getting the minimum in the last case.
// Hence answer is ‘113’.

// Link : https://www.codingninjas.com/studio/problems/allocate-books_1090540

// Intuition
// We are given an array of books and we have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
// so we know that the minimum number of pages assigned to a student will be the maximum number of pages in the array and the maximum number of pages assigned to a student will be the sum of all the pages in the array.
// So for each possible value within the minimum and maximum number of pages, we will check if it is possible to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is the current value.
// If it is possible then we will try to minimize the maximum number of pages and if it is not possible then we will try to the move to the next value.

// Utility function to check if it is possible to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is the current value.

bool isPossible(vector<int> &arr, int students, int mid)
{
    int pagesAssigned = 0;
    int studentsRequired = 1;
    for (int i : arr)
    {
        if (pagesAssigned + i <= mid)
        {
            pagesAssigned += i;
        }
        else
        {
            studentsRequired++;
            if (studentsRequired > students) // Check if the required students exceed the given limit
                return false;
            pagesAssigned = i;
        }
    }
    return true;
}

// BRUTE FORCE
// We will iterate over the possible values of the maximum number of pages and for each value, we will check if it is possible to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is the current value.
// If possible we will return the current value and if not then we will keep on checking the same.
// Time complexity: O(n^2)
// Space complexity: O(1)

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n) // if number of students > number of books
        return -1;
    int low = *max_element(arr.begin(), arr.end());

    // max pages any student will hold is eq to total number of pages
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    for (int i = low; i <= high; i++)
    {
        if (isPossible(arr, m, i))
        {
            return i; // since we need the minimum pages , we will return the first possible value
        }
    }
}

// OPTIMAL APPROACH
// We will leverage binary search to find the answer.
// We will apply binary search on the possible values of the maximum number of pages assigned to a student.
// For each value, we will check if it is possible to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is the current value.
// If it is possible then we will try to minimize the maximum number of pages and if it is not possible then we will try to maximize the maximum number of pages.
// Time complexity: O(nlog(n))
// Space complexity: O(1)

int findPages(vector<int> &arr, int n, int m)
{

    if (m > n) // if number of students > number of books
        return -1;
    // in order for any student to hold any possible book , he should be able
    // to hold the number of pages in a the largest book
    int low = *max_element(arr.begin(), arr.end());

    // max pages any student will hold is eq to total number of pages
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = high - (high - low) / 2;
        if (isPossible(arr, m, mid))
        {
            ans = mid;
            high = mid - 1; // check for a lower possible value
        }
        else
        {
            low = mid + 1; // trim the lefyt search space
        }
    }

    return ans;
}