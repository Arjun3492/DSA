// Problem statement:Given a linked list of 0s, 1s and 2s, sort it.

// Approach 1: Brute Force
// We store the count of 0s, 1s and 2s in an array.
// We iterate over the linked list and set the data of the nodes to 0 ,1 and 2 according to the count of 0s, 1s and 2s.

Node *sortList(Node *head)
{
    // Write your code here.
    int countArr[3] = {0};
    Node *curr = head;
    while (curr)
    {
        switch (curr->data)
        {
        case 0:
            countArr[0]++;
            break;
        case 1:
            countArr[1]++;

            break;
        case 2:
            countArr[2]++;
            break;
        }
        curr = curr->next;
    }
    curr = head;

    curr = head;
    while (curr)
    {
        if (countArr[0]--)
        {
            curr->data = 0;
        }
        else if (countArr[1]--)
        {
            curr->data = 1;
        }
        else
        {
            curr->data = 2;
        }
        curr = curr->next;
    }
    return head;
}