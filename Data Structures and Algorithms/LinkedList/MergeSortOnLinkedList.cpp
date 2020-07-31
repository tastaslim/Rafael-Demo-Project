#include <iostream>
using namespace std;

//Take Input Code
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *TakeInput()
{
    int value;
    cin >> value;
    node *head = NULL;
    node *tail = NULL;
    while (value != -1)
    {
        node *newNode = new node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> value;
    }
    return head;
}

// Merging Two Sorted LinkedList
node *MergeTwoSortedLL(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *outputTail = NULL;
    node *outputHead = NULL;
    node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            if (outputHead == NULL)
            {
                outputHead = temp2;
                outputTail = temp2;
            }
            else
            {
                outputTail->next = temp2;
                outputTail = outputTail->next;
            }

            temp2 = temp2->next;
        }
        else
        {
            if (outputTail == NULL)
            {
                outputTail = temp1;
                outputHead = temp1;
            }
            else
            {
                outputTail->next = temp1;
                outputTail = outputTail->next;
            }
            temp1 = temp1->next;
        }
    }

    if (temp1 != NULL)
    {
        outputTail->next = temp1;
        temp1 = temp1->next;
        outputTail = outputTail->next;
    }
    if (temp2 != NULL)
    {
        outputTail->next = temp2;
        temp2 = temp2->next;
        outputTail = outputTail->next;
    }
    return outputHead;
}

//Finding Mid Point

node *MidPoint(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Merge Sort
node *MergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *mid = MidPoint(head);
    node *h1 = head;
    node *h2 = mid->next;
    mid->next = NULL;
    h1 = MergeSort(h1);
    h2 = MergeSort(h2);
    node *final = MergeTwoSortedLL(h1, h2);
    return final;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = TakeInput();
    node *head1 = MergeSort(head);
    print(head1);
    return 0;
}