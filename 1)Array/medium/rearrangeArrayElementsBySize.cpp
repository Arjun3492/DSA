// Variety-1
// Problem Statement:

// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
// Without altering the relative order of positive and negative elements, you must return
// an array of alternately positive and negative values.


//Brute force approach
//Create separate empty arrays for positives and negatives
//loop through the original array and push the +ve elements to positive array and -ve to negative array
// run a second loop from i =0 to n2 then place elements from pos and neg array to ans array alternatively
//Complexity O(n+n/2)

vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;
    int n=a.size();
    for(int i:a){
        if(i<0) neg.push_back(i);
        else pos.push_back(i);
    }

    for(int i=0;i<n/2;i++){
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }
    return ans;
}


//OPTIMAL APPROACH
//Create two pointers one for +ve and one for -ve index 
//Set positive index to 0 and negative to 1 (as final array must start with positive number)
//Traverse through the original array 
//If positive number is encountered insert the number to positive index pointer and increase it by 2
//If -ve number is encountered insert the number to -ve index pointer and increase it by 2

vector<int> alternateNumbers(vector<int>&a) {
    int n=a.size();
    vector<int> arr(n,0);
    int pI=0,nI=1;
    for(int i :a){
        if(i<0){
            arr[nI]=i;
            nI+=2;
        }else{
             arr[pI]=i;
            pI+=2;
        }
    }
    return arr;

}





