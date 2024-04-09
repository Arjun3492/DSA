// Job Sequencing Problem
// Problem statement
// You are given a 'Nx3' 2-D array 'Jobs' describing 'N' jobs where 'Jobs[i][0]' denotes the id of 'i-th' job, 'Jobs[i][1]' denotes the deadline of 'i-th' job, and 'Jobs[i][2]' denotes the profit associated with 'i-th job'.
// You will make a particular profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
// Return the number of jobs scheduled and the maximum profit that can be obtained.

// Example :
// Input : Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,3,15]]
// Output : [3,142]
// Explanation: We can schedule jobs 1, 3, and 5 to get a maximum profit of 142.

// Link : https://www.naukri.com/code360/problems/job-sequencing-problem_1169460

// Approach
// At first we will sort the jobs in decreasing order of profit.
// Since we want maximum profit, we will try to schedule as many jobs as possible with maximum profit.
// We can do by traversing the sorted jobs and then scheduling the job at the last possible time before the deadline.
// This way we will have free time slots for other jobs with less deadline, as we are scheduling a job at the last possible time.
// We will keep track of the maximum profit and the number of jobs scheduled.

// Time complexity: O(NlogN) + O(N^2) [sorting + traversing]
// Space complexity: O(N) [extra space is used to store the jobs]

// Sort the jobs in decreasing order of profit
bool comp(vector<int> jobA, vector<int> jobB)
{
    return jobA[2] > jobB[2]; // Sort by profit in descending order
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comp); // Sort jobs by profit in descending order

    int maxDeadline = 0; // At first we find the maximum deadline available
    for (auto job : jobs)
    {
        maxDeadline = max(maxDeadline, job[1]); // Find maximum deadline
    }

    vector<int> jobsSeq(maxDeadline + 1, -1); // Initialize array of size maxDeadline+1 with -1
    int jobsExecuted = 0;
    int maxProfit = 0;

    for (auto job : jobs) // Traverse the jobs
    {
        for (int i = job[1]; i > 0; i--) // Schedule the job at the last possible time before the deadline
        {
            if (jobsSeq[i] == -1) // If the slot is empty, schedule the job
            {
                jobsSeq[i] = 1;      // Mark the slot as filled
                maxProfit += job[2]; // Add the profit of the job
                jobsExecuted++;      // Increment the number of jobs executed
                break;               // Break the loop as the job is scheduled
            }
        }
    }

    return {jobsExecuted, maxProfit}; // Return the number of jobs executed and the maximum profit
}
