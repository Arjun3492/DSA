// Problem Statement: Given a sorted doubly Linked list and a number k, return all the pairs in the list which sum up to k

// Approach
//  1) Create a set to store the values seen in the linked list.
//  2) Create a vector to store pairs that sum to 'k'.
//  3) Traverse the linked list.
//  4) Check if the current node's data is less than or equal to 'k'.
//  5) Calculate the remaining value needed to reach 'k' from the current node.
//  6) Check if the remaining value is found in the set.
//  7) If found, add a pair to the result vector with values (remaining, current).
//  8) Insert the current node's data into the set for future reference.
//  9) Move to the next node in the linked list.
//  10) Return the vector containing pairs that sum to 'k'.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(n)

vector<pair<int, int>> findPairs(Node *head, int k)
{
    // Create a set to store the values seen in the linked list.
    set<int> hash;

    // Create a vector to store pairs that sum to 'k'.
    vector<pair<int, int>> ans;

    // Traverse the linked list.
    while (head)
    {
        // Check if the current node's data is less than or equal to 'k'.
        if (head->data <= k)
        {
            // Calculate the remaining value needed to reach 'k' from the current node.
            int rem = k - head->data;

            // Check if the remaining value is found in the set.
            if (hash.find(rem) != hash.end())
            {
                // If found, add a pair to the result vector with values (remaining, current).
                ans.push_back({rem, head->data});
                // or use utility function make_pair() to make a pair
                // ans.push_back(make_pair(rem, head->data));
            }

            // Insert the current node's data into the set for future reference.
            hash.insert(head->data);
        }

        // Move to the next node in the linked list.
        head = head->next;
    }

    // Return the vector containing pairs that sum to 'k'.
    return ans;
}

// Optimized Approach
// Two pointer approach
// Since the list is sorted, we can use two pointers to find the pairs that sum to 'k'.
// 1) Initialize two pointers, 'front' and 'end', to the beginning and end of the sorted linked list.
// 2) Move the 'end' pointer to the last node of the linked list.
// 3) Iterate while the 'front' data is less than the 'end' data.
// 4) Check if the sum of 'front' and 'end' data is equal to 'k'.
// 5) If equal, add a pair to the result vector with values (front data, end data).
// 6) Check if the next node of 'front' with the current 'end' data also sums to 'k'.
// 7) If yes, move 'front' forward.
// 8) If no, move 'end' backward.
// 9) If the sum of 'front' and 'end' data is less than 'k', move 'front' forward.
// 10) If the sum of 'front' and 'end' data is greater than 'k', move 'end' backward.
// 11) Return the vector containing pairs that sum to 'k'.

// Complexity: 1) Time Complexity O(n)
//             2) Space Complexity O(1)

vector<pair<int, int>> findPairs(Node *head, int k)
{
    // Create a vector to store pairs that sum to 'k'.
    vector<pair<int, int>> ans;

    // Initialize two pointers, 'front' and 'end', to the beginning and end of the sorted linked list.
    Node *front, *end;
    front = head;
    end = head;

    // Move the 'end' pointer to the last node of the linked list.
    while (end->next != NULL)
    {
        end = end->next;
    }

    // Iterate while the 'front' data is less than the 'end' data.
    while (front->data < end->data)
    {
        // Check if the sum of 'front' and 'end' data is equal to 'k'.
        if (front->data + end->data == k)
        {
            // If equal, add a pair to the result vector with values (front data, end data).
            ans.push_back(make_pair(front->data, end->data));

            // Check if the next node of 'front' with the current 'end' data also sums to 'k'.
            if (front->next->data + end->data == k)
            {
                front = front->next; // Move 'front' forward.
            }
            else
            {
                end = end->prev; // Move 'end' backward.
            }
        }
        else if (front->data + end->data < k)
        {
            front = front->next; // Move 'front' forward.
        }
        else
        {
            end = end->prev; // Move 'end' backward.
        }
    }

    // Return the vector containing pairs that sum to 'k'.
    return ans;
}