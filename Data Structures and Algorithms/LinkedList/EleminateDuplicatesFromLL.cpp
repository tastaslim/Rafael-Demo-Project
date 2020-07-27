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
//Remove Consecutive Duplicates in Linked List.
node *removeDuplicates(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            node *h = temp->next;
            temp->next = h->next;
            delete h;
        }
        else
            temp = temp->next;
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
    head = removeDuplicates(head);
    print(head);
    return 0;
}