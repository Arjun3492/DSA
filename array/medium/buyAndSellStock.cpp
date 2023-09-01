// Stock Buy And Sell
// Problem Statement: You are given an array of prices where prices[i]
// is the price of a given stock on an ith day.

// You want to maximize your profit by choosing a single day to buy
// one stock and choosing a different day in the future to sell that stock. 
// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0.

//BRUTE FORCE
//Find the difference for each element with  velements after it using a nested loop
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n =prices.size();
    int profit=0;
    for(int i =0;i<n;i++){
        for(int j=i;j<n;j++){
            int diff=prices[j]-prices[i];
            if(diff>profit){
                profit=diff;
            }
        }
    }
    return profit;
}


//OPTIMAL APPROACH
//INTIUITION:update the minimum element as we traverse the array then find the diff with each following element 
//if diff> maxi ,then update maxi
//return maxi at end of loop


int maximumProfit(vector<int> &prices) {
        int n =prices.size();

 int maxi=INT_MIN;
 int buy=prices[0];
 for(int i:prices){
     if(i<buy){
         buy=i;
     }
     else{
         maxi=max(maxi,i-buy);
     }
 }
 return maxi;
}

// here minimum is buy