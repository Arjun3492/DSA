// Problem Statement: Given the heads of two non-empty linked lists representing
// two non-negative integers. The digits are stored in reverse order, and each
// of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Example:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]

// Approach:
// 1. Traverse both linked lists and add the digits at the same position.
// 2. If the sum is greater than 10, then carry is 1 and the sum is the remainder of sum/10.
// 3. Create a new node for the result digit and update pointers.
// 4. Continue processing until both linked lists and carry are fully processed.
// 5. Return the result after processing all digits.

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *head = nullptr;
    Node *curr = nullptr;
    int carry = 0;

    // Continue processing until both linked lists and carry are fully processed
    while (num1 != nullptr || num2 != nullptr || carry)
    {
        // Add the digits at the same position & carry to "sum"
        int sum = 0;
        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }
        sum += carry;

        // Create a new node for the result digit and update pointers
        if (head == nullptr)
        {
            head = new Node(sum % 10);
            curr = head;
        }
        else
        {
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }
        carry = sum / 10; // Update carry
    }

    return head; // Return the result after processing all digits
}
