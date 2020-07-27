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

// Length OF LinkedList
int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count = count + 1;
    }
    return count;
}

// Append last N nodes to first in LinkedList
node *AppendLastnNodesToFirst(node *head, int len)
{
    if (head == NULL)
        return NULL;
    if (len == 0)
        return head;
    int k1 = length(head);
    if (len > k1)
    {
        len = len % k1;
    }

    int k2 = k1 - len;
    int count = 0;
    node *temp = head;
    while (temp != NULL && count < k2 - 1)
    {
        temp = temp->next;
        count++;
    }
    node *h2 = temp->next;
    node *temph = h2;
    temp->next = NULL;
    while (temph->next != NULL)
    {
        temph = temph->next;
    }
    temph->next = head;
    head = h2;

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
    int len;
    cin >> len;
    head = AppendLastnNodesToFirst(head, len);
    print(head);
    return 0;
}