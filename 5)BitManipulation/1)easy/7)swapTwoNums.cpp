// Problem Statement: Given two numbers a and b, swap them using bitwise operations

void swapNumber(int &a, int &b)
{
    a = a ^ b; // step1
    b = a ^ b; // step 2
    a = a ^ b; // step 3
}

// EG: a=5,b=7

// step 1: a= 5^7 =  2
// step 2: b= 2^7 =  5
// step 3: a= 2^5 =  7

// Misc:
// We can also do it using arithmatic operations

void swapNumber(int &a, int &b)
{
    a = a + b; // step1
    b = a - b; // step2
    a = a - b; // step3
}
// eg:a=7,b=5

// step1:a=12;
// step2:b=12-5=7
// step3:a=12-7=5
