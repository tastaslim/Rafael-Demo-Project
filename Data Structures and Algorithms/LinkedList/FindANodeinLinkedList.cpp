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

// Find a node in LinkedList
int FindNode(node *head, int start, int data)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == data)
    {
        return start;
    }
    int k = FindNode(head->next, start + 1, data);
    return k;
}

int main()
{
    node *head = TakeInput();
    int i;
    cin >> i;
    int k = FindNode(head, 0, i);
    cout << k;
    return 0;
}