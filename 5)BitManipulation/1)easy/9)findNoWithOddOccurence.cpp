// Problem statement:Odd Occurence
// Given a non-empty array of integers nums, every element appears even number of times except for one. Find that single one.

// using xor operator
int oddOccurence(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    { // all the elements occuring even number of times will cancel out
        // as on performing xor operation on same numbers it gives 0,so the even numbers will form pairs and cancel,while for the odd one, it will be left with one unpair self,which when xor with 0 will return itself

        ans ^= nums[i];
    }
    return ans;
}