// Sort an array of 0s, 1s and 2s
// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
// Write a program to in-place sort the array without using inbuilt sort functions. 
// ( Expected: Single pass-O(N) and constant space)


//Count approach
//Count the number of 0's,1's & 2's
void sortArray(vector<int> &arr, int n) {
  int hashArr[3] = {0};
  for (int i = 0; i < n; i++) {
    hashArr[arr[i]]++;
  }
  for (int i = 0; i < hashArr[0]; i++) {
    arr[i] = 0;
  }
  for (int i = hashArr[0]; i < hashArr[0] + hashArr[1]; i++) {
    arr[i] = 1;
  }
  for (int i = hashArr[0] + hashArr[1]; i < n; i++) {
    arr[i] = 2;
  }
}


//OPTIMAL:DUTCH FLAH APPROACH
//This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:

// arr[0….low-1] contains 0. [Extreme left part]
// arr[low….mid-1] contains 1.
// arr[mid,high] contains the unsorted array
// arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
//Visualisation
//https://takeuforward.org/wp-content/uploads/2023/03/Screenshot-2023-03-18-171206.png

void sortArray(vector<int> &arr, int n) {
    //DUTCH FLAG APPROACH
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    
}