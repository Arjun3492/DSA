// Asteroid Collision problem
//  Problem Statement: Given an array of integers asteroids, for each asteroid, the absolute value represents its size,
//  and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same
//  speed. Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
//  If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
//
//  Example: arr = [5, 10, -5]
//  Output: [5, 10]
//  Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

// Approach: Stack
// We use a stack to keep the track of the asteroids.
// Starting from the left of the array, we check if the current asteroid is positive or negative.
//  If the current asteroid is positive, we push it to the stack.\
// If the current asteroid is negative, we check if the top element of the stack is positive or negative.
// If the top element of the stack is positive, we check if the absolute value of the top element is greater than the
// absolute value of the current element. If yes, we do nothing. If no, we pop the top element of the stack and repeat the
// process until the top element of the stack is negative or the absolute value of the top element is greater than the
// absolute value of the current element. If the top element of the stack is negative, we push the current element to the
// stack.
// After the above process, we are left with the elements in the stack which will not collide with any other element.

vector<int> collidingAsteroids(vector<int> &ast)
{
    stack<int> s;
    for (int i = 0; i < ast.size(); i++)
    // starting from the left of the array
    {
        if (ast[i] > 0 || s.empty())
        {
            // if the current asteroid is positive or the stack is empty, we simply push it to the stack.
            s.push(ast[i]);
        }
        else
        {
            // the current asteroid is negative, and will move to the left to collide with the previous asteroids(if any in the stack)
            while (!s.empty() && s.top() > 0 && s.top() < abs(ast[i]))
            // if the top element of the stack is positive and its absolute value is less than the absolute value of the current element
            // we pop the top element of the stack and repeat the process until the top element of the stack is negative or the absolute value of the top element is greater than the absolute value of the current element.

            {
                //(As a greater negative element will collide with the positive smaller element before it)
                s.pop();
            }
            if (!s.empty() && s.top() == abs(ast[i]))
            // if the top element of the stack is equal to the absolute value of the current element, we pop the top element of the stack.
            {
                s.pop();
            }
            else if (s.empty() || s.top() <= 0)
            // if the stack is empty or the top element of the stack is negative, we push the current element to the stack.
            {
                s.push(ast[i]);
            }
        }
    }

    int n = s.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = s.top();
        s.pop();
    }

    return ans;
}