// We will understand the memoization and tabulation approach to solve problems based on DP PARTITION.

// STEPS TO WRITE RECURRENCE FUNCTION FOR DP PARTITION
// 1. Start with the entire block/array and mark it with i,j. We need to find the value of f(i,j).
// 2. Run a loop to try all partitions. (Place partition between i and j)
// 3. Run the best possible answer of the two partitions ( answer that comes after dividing the problem into two subproblems and solving them recursively).

// STEPS TO WRITE MEMOIZATION FUNCTION FOR DP PARTITION
// 1. Create a 2D array to store the results of the subproblems.
// 2. Check if the subproblem is already solved, return the answer if it is solved.
// 3. If not solved, solve the subproblem and store the result in the array.
// 4. Return the result.

// STEPS TO WRITE TABULATION FUNCTION FOR DP PARTITION
// 1. Create a 2D array to store the results of the subproblems.
// 2. Fill the base cases of the array.
// 3. Run a loop to fill the array in a bottom-up manner.
// 4. Return the result.
