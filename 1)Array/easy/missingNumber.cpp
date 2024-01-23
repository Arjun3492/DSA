//Ques: Given an array nums of size n  containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array which is replaced by 0 in array.

int zorApproach(vector<int>& nums){
    // we know that Xor of a number with itself is always 0 
    // and xor of number with 0 is number itself
    // so xor1= xor of numbers 1 to N
    // xor 2= xor of array elements
    // missing number =  xor of (xor1 and xor2)
    // all the existing numbers will make pairs and result in 0
    // missing number xor with 0 = missing number
    int n= nums.size();
    int XOR1=0;
    int XOR2=0;
        for(int i =1;i<=n;i++){
            XOR1^=i;
            XOR2^=nums[i-1];
        } 
        return XOR1^ XOR2;
}

int missingNumber(vector<int>& nums) {
        // sum of n elements approach
        // S1 = sum of first n natural numbers
        // S2= sums of array elements
        // S1-S2== missing number
        int n= nums.size();
        int S1= n*(n+1)/2;
        int S2= 0;
        for(int i :nums){
            S2+=i;
        }
        return S1-S2;
}