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
//Iterative Approach

node *zigZag(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = head;
    while (temp->next && temp)
    {
        node *a = temp;
        node *b = temp->next;
        if (a->data > b->data)
        {
            swap(a->data, b->data);
        }
        if (b->next)
        {
            if (b->data < b->next->data)
            {
                swap(b->data, b->next->data);
            }
        }
        else
        {
            return head;
        }

        temp = temp->next->next;
    }
    return head;
}

// Recursive Approach
/*node *zigZag(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->data > head->next->data)
    {
        swap(head->data, head->next->data);
    }

    if (head->next->next != NULL)
    {
        if (head->next->next->data > head->next->data)
            swap(head->next->data, head->next->next->data);
    }

    head->next->next = zigZag(head->next->next);
    return head;
}*/

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
    head = zigZag(head);
    print(head);
    return 0;
}