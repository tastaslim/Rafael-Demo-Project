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

node *Intersection(node *head1, node *head2)
{
    node *temp1 = head1, *temp2 = head2;
    node *ansH = NULL, *ansT = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }
        else if (temp2->data > temp1->data)
        {
            temp1 = temp1->next;
        }
        else
        {
            if (ansH == NULL)
            {
                ansH = temp1;
                ansT = temp1;
            }
            else
            {
                ansT->next = temp1;
                ansT = ansT->next;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    ansT->next = NULL;
    return ansH;
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
    node *ans = Intersection(head1, head2);
    print(ans);
    return 0;
}