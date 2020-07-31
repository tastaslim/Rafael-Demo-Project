#include <bits/stdc++.h>
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

node *pairWiseSwap(node *head)
{
    node *temp = head;
    node *h = head->next;
    while (temp->next != NULL)
    {
        swap(temp->data, h->data);
        if (temp->next == NULL || h->next == NULL)
            break;
        temp = h->next;
        h = temp->next;
    }
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
    head = pairWiseSwap(head);
    print(head);
    return 0;
}