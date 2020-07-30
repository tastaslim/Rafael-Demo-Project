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

// Deleting new node at Ith position of LinkedList
node *DeleteAtIthNode(node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {

        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        head->next = DeleteAtIthNode(head->next, i - 1);
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
    int i;
    cin >> i;
    head = DeleteAtIthNode(head, i);
    print(head);
    return 0;
}