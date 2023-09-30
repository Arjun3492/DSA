// Find the Majority Element that occurs more than N/2 times
// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array.
// You may consider that such an element always exists in the array.


//BRUTE FORCE APPROACH
// run a nested loop ,so to count the occurence of each element in the array and check if its greater than n/2

//BETTER APPROACH
// Use unordered_map to store the freq of occurence of each element,
//then traverse the hashmap to find the element with freq > n/2

#include<unordered_map>

int majorityElement(vector<int> v) {
	// Write your code here
	int n=v.size();
	unordered_map<int,int> hashMap;
	for(int i:v){
		hashMap[i]++;
	} 

	for(auto i :hashMap){
		if(i.second>n/2){
			return i.first;
		}
	}
}


//OPTIMAL APPROACH
//Moore's voting algo
// Works on the intuition that the element whose occurence is greater than n/2 will not cancel out by other elements completely
//i.e. count will not be 0 for that element


int majorityElement(vector<int> v) {
	int n =v.size();
	int element=v[0],count=1;
	for(int i =1;i<n;i++){
		if(count==0){
			count=1;
			element=v[i];
		}else if(v[i]==element){
			count++;
		}else{
			count--;
		}
	}
	return element;
}