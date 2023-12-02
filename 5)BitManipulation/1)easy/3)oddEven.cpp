// Problem statement:check if the given number is odd or even using bitwise operations

// if num is odd then its LSB bit is 1 ,else 0
string oddEven(int N)
{
    if (N & 1)
    {
        return "odd";
    }
    else
    {
        return "even";
    }
}