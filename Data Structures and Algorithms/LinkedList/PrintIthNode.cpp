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

// Printing Ith node of LinkedList
node *IthNode(node *head, int i)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL && count < i)
    {
        temp = temp->next;
        count = count + 1;
    }
    if (temp != NULL)
    {
        return temp;
    }
}
int main()
{
    node *input = TakeInput();
    int i;
    cin >> i;
    node *k = IthNode(input, i);
    cout << k->data;
    return 0;
}