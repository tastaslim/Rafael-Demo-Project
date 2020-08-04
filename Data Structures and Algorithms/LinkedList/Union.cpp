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
node *makeUnion(struct node *head1, struct node *head2)
{
    if (!head1 && !head2)
    {
        return NULL;
    }

    set<int> s;
    set<int>::iterator it;
    struct node *temp1 = head1, *temp2 = head2;
    while (temp1)
    {
        s.insert(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2)
    {
        s.insert(temp2->data);
        temp2 = temp2->next;
    }
    node *head = NULL, *tail = NULL;
    for (it = s.begin(); it != s.end(); it++)
    {
        node *newNode = new node(*it);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        // cout << *it << " ";
    }
    tail->next = NULL;
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
    node *head1 = TakeInput();
    node *head2 = TakeInput();
    node *head = makeUnion(head1, head2);
    print(head);
    return 0;
}