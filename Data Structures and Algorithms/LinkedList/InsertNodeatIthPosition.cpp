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

// Inserting new node at Ith position of LinkedList
node *InsertAtIthNode(node *head, int i, int data)
{
    node *temp = head;
    node *newNode = new node(data);
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    int count = 0;
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count = count + 1;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
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
    int i, data;
    cin >> i >> data;
    head = InsertAtIthNode(head, i, data);
    print(head);
    return 0;
}