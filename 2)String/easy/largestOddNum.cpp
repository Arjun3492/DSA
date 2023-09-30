// You are given a string num, representing a large integer. 
// Return the largest-valued odd integer (as a string) that is 
// a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.
// Example:
// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.


//BRUTE FORCE APPROACH
//use a nested loop to find out all the substrings and check if they are odd or not
//if odd update maximum odd number found so far
//return the maximum odd number at the end
string largestOddNumber(string num) {
        int n=num.length();
        int maxi=0;
        for(int i =0;i<n;i++){
            string sub="";
            for(int j=i;j<n;j++){
                sub=sub+num[j];
                if(stoi(sub)%2==1){
                    maxi=max(stoi(sub),maxi);
                }
            }
        }
        return maxi==0?"":to_string(maxi);
}


//OPTIMAL APPROACH
//start from the end of the string and check if the current digit is odd or not
//if odd return the substring from 0 to i
//else return "" at the end of loop
 string largestOddNumber(string num) {
        int n =num.size();
       for(int i =n-1;i>=0;i--){
           int t=num[i];
           if(t%2!=0){
               return num.substr(0,i+1);
           }
       }
       return "";
}
