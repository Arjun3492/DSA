// Ninja’s Training
// Problem statement
// Ninja is planing this ‘N’ days-long training schedule. Each day,
// he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves).
// Each activity has some merit points on each day. As Ninja has to improve all his skills,
// he can’t do the same activity in two consecutive days. Can you help Ninja find out the
// maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and
// activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// Link : https://www.naukri.com/code360/problems/ninja-s-training_3621003

// APPROACH
// 1. We will assume the days as indexes from 0 to N.
// 2. We will try all possible ways while maintaining the activity of the previous day so that we don't repeat it on the current day.
// 3. As the problem statement asks to find the maximum number of merit points, we will return the maximum of all the choices in our recursive function.

// RECURRENCE SOLUTION

// Recursive function to calculate the maximum points for the ninja training
int f(int day, int last, vector<vector<int>> &points)
{

    // Base case: When we reach the first day (day == 0)
    if (day == 0)
    {
        int maxi = 0;
        // Calculate the maximum points for the first day by choosing an activity
        // different from the last one
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        // Store the result in dp array and return it
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    // Iterate through the activities for the current day
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            // Calculate the points for the current activity and add it to the
            // maximum points obtained so far (recursively calculated)
            int activity = points[day][i] + f(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }

    // Return the result
    return maxi;
}

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Start the recursive calculation from the last day with no previous activity
    return f(n - 1, 3, points);
}

// MEMOIZATION
#include <bits/stdc++.h>
// Recursive function to calculate the maximum points for the ninja training
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // If the result for this day and last activity is already calculated, return it
    if (dp[day][last] != -1)
        return dp[day][last];

    // Base case: When we reach the first day (day == 0)
    if (day == 0)
    {
        int maxi = 0;
        // Calculate the maximum points for the first day by choosing an activity
        // different from the last one
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        // Store the result in dp array and return it
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    // Iterate through the activities for the current day
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            // Calculate the points for the current activity and add it to the
            // maximum points obtained so far (recursively calculated)
            int activity = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

    // Store the result in dp array and return it
    return dp[day][last] = maxi;
}

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Create a memoization table (dp) to store intermediate results
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // Start the recursive calculation from the last day with no previous activity
    return f(n - 1, 3, points, dp);
}

// TABULATION

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Create a table to store the maximum points for each day and activity
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first row of the table with the points for the first day
    for (int i = 0; i <= 2; i++)
    {
        dp[0][i] = points[0][i];
    }

    // Iterate over the remaining days
    for (int i = 1; i < n; i++)
    {
        // Iterate over the activities for the current day
        for (int j = 0; j <= 2; j++)
        {
            // Initialize the maximum points for the current day and activity
            int maxi = 0;
            // Iterate over the activities for the previous day
            for (int k = 0; k <= 2; k++)
            {
                // Calculate the points for the current activity and add it to the
                // maximum points obtained so far (from the previous day)
                if (j != k)
                {
                    int activity = points[i][j] + dp[i - 1][k];
                    maxi = max(maxi, activity);
                }
            }
            // Store the maximum points for the current day and activity in the table
            dp[i][j] = maxi;
        }
    }

    // Find the maximum points for the last day
    int ans = 0;
    for (int i = 0; i <= 2; i++)
    {
        ans = max(ans, dp[n - 1][i]);
    }

    // Return the maximum points for the ninja training
    return ans;
}

// SPACE OPTIMIZED TABULATION

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Create two arrays to store the maximum points for the current and previous day
    vector<int> curr(3, 0);
    vector<int> prev(3, 0);

    // Initialize the first row of the arrays with the points for the first day
    for (int i = 0; i <= 2; i++)
    {
        curr[i] = points[0][i];
    }

    // Iterate over the remaining days
    for (int i = 1; i < n; i++)
    {
        // Iterate over the activities for the current day
        for (int j = 0; j <= 2; j++)
        {
            // Initialize the maximum points for the current day and activity
            int maxi = 0;
            // Iterate over the activities for the previous day
            for (int k = 0; k <= 2; k++)
            {
                // Calculate the points for the current activity and add it to the
                // maximum points obtained so far (from the previous day)
                if (j != k)
                {
                    int activity = points[i][j] + prev[k];
                    maxi = max(maxi, activity);
                }
            }
            // Store the maximum points for the current day and activity in the current array
            curr[j] = maxi;
        }
        // Update the previous array with the current array for the next iteration
        prev = curr;
    }

    // Find the maximum points for the last day
    int ans = 0;
    for (int i = 0; i <= 2; i++)
    {
        ans = max(ans, curr[i]);
    }

    // Return the maximum points for the ninja training
    return ans;
}
