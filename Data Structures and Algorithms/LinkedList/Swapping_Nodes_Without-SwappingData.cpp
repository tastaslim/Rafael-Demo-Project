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
node *swapNodes(node *head, int i, int j)
{
    if (i == j)
        return head;
    node *temp1 = head, *temp2 = head;
    int counti = 0, countj = 0;
    node *prev1 = NULL, *prev2 = NULL;

    //Common Code for Question

    while (temp1 != NULL && counti < i)
    {
        prev1 = temp1;
        temp1 = temp1->next;
        counti++;
    }

    while (temp2 != NULL && countj < j)
    {
        prev2 = temp2;
        temp2 = temp2->next;
        countj++;
    }
    if (temp1 == NULL || temp2 == NULL)
    {
        return head;
    }
    node *next1 = temp1->next;
    node *next2 = temp2->next;

    //Common Code ends Here.

    //i or j are not 0 and i-j==1 or j-i==1

    // Edge case Start
    if (i == 0)
    {
        if (j == 1)
        {
            temp2->next = temp1;
            temp1->next = next2;
            head = temp2;
            return head;
        }
        node *next2 = temp2->next;
        temp2->next = temp1->next;
        prev2->next = temp1;
        temp1->next = next2;
        head = temp2;
        return head;
    }
    if (j == 0)
    {
        if (i == 1)
        {
            temp1->next = temp2;
            temp2->next = next1;
            head = temp1;
            return head;
        }
        node *next1 = temp1->next;
        temp1->next = temp2->next;
        prev1->next = temp2;
        temp2->next = next1;
        head = temp1;
        return head;
    }

    if (i - j == 1 || j - i == 1)
    {
        if (i < j)
        {
            prev1->next = temp2;
            temp2->next = temp1;
            temp1->next = next2;
            return head;
        }
        else
        {
            prev2->next = temp1;
            temp1->next = temp2;
            temp2->next = next1;
            return head;
        }
    }

    // Edge cases End
    prev1->next = temp2;
    temp2->next = next1;
    prev2->next = temp1;
    temp1->next = next2;
    return head;
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
    int i, j;
    cin >> i >> j;
    head = swapNodes(head, i, j);
    print(head);
    return 0;
}