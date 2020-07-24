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
    if (head == NULL)
    {
        node *temp = new node(data);
        if (i == 0)
        {
            temp->next = head;
            head = temp;
        }
        return head;
    }
    if (i == 0)
    {

        node *temp = new node(data);
        temp->next = head;
        head = temp;
        return head;
    }
    head->next = InsertAtIthNode(head->next, i - 1, data);
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