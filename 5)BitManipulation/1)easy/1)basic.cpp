// Problem Statement
// Link:https://www.codingninjas.com/studio/problems/bit-manipulation_8142533

int getBit(int n, int pos)
{

    // we right shift the num by (pos-1) times
    // the bit at 'pos' position will become LSB
    // then by doing & with 1 , we can know if that bit was 1 or 0.
    n = n >> (pos - 1);
    return n & 1;
}

int setBit(int n, int pos)
{
    // we create a mask by left shifting 1 by (pos-1) times
    // for example 1 is 0001 then by creating a mask for manipulation at 2nd place from right ,we will left shift 1 by (pos-1)[2-1 here]
    // now mask is 0010,now if we perform OR bit operation of mask with num , the bit at target pos will become 1 as mask has 1 at that position
    int mask = 1 << (pos - 1);
    n |= mask;
    return n;
}

int clearBit(int n, int pos)
{
    // similar to above we first create a mask from 1 for manipulating the target position
    // then we perform bitwise NOT operation on mask ,so that all bits of mask flip, giving 0 at target position and 1 elsewhere
    // now if we perform bitwise AND with inverted mask and num , we will set the target bit to 0 ,as mask has 0 at this position
    int mask = 1 << (pos - 1);
    n = (n & (~mask));
    return n;
}

vector<int> bitManipulation(int num, int i)
{
    vector<int> ans;

    // Get bit at ith pos
    ans.push_back(getBit(num, i));

    // Set bit at ith pos
    ans.push_back(setBit(num, i));

    // Clear bit at ith pos
    ans.push_back(clearBit(num, i));
    return ans;
}

int main()
{
    int num = 13; // Example number in binary: 1101

    int i = 3; // Example position

    vector<int> result = bitManipulation(num, i);

    // Output the results
    cout << "Original Number: " << num << endl;
    cout << "Bit at position " << i << ": " << result[0] << endl;
    cout << "Number after setting bit at position " << i << ": " << result[1] << endl;
    cout << "Number after clearing bit at position " << i << ": " << result[2] << endl;

    return 0;
}
