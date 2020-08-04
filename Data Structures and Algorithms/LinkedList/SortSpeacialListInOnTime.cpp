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

void sortList(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp1 = head->next;
    node *ansH = head, *ansT = head;
    while (temp1)
    {
        if (abs(temp1->data) != temp1->data)
        {
            node *newNode = new node(temp1->data);
            newNode->next = ansH;
            ansH = newNode;
        }
        else
        {
            ansT->next = temp1;
            ansT = ansT->next;
        }

        temp1 = temp1->next;
    }
    ansT->next = NULL;
    while (ansH)
    {
        cout << ansH->data << " ";
        ansH = ansH->next;
    }
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
    sortList(head);
    //print(head);
    return 0;
}