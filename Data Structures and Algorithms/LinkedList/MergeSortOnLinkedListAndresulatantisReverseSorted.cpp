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
    node *outputHead = NULL;
    node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            if (outputHead == NULL)
            {
                outputHead = temp2;
                outputHead->next = NULL;
            }
            else
            {
                temp2->next = outputHead;
                outputHead = temp2;
            }

            temp2 = temp2->next;
        }

        else
        {
            if (outputHead == NULL)
            {
                outputHead = temp1;
                outputHead->next = NULL;
            }
            else
            {
                temp1->next = outputHead;
                outputHead = temp1;
            }
            temp1 = temp1->next;
        }
    }

    while (temp1 != NULL)
    {
        node *outputTail = temp1;
        outputTail->next = outputHead;
        outputHead = outputTail;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        node *outputTail = temp2;
        outputTail->next = outputHead;
        outputHead = outputTail;
        temp2 = temp2->next;
    }
    return outputHead;
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
    node *head1 = TakeInput();
    node *head2 = TakeInput();
    node *head = MergeTwoSortedLL(head1, head2);
    print(head);
    return 0;
}