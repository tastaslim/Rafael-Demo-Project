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
node *DeleteAtIthNode(node *head, int i)
{
    node *temp = head;
    if (i == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    // We are doing it according to index starting from 0
    // i=2 ---> Third Element (0->1->2)
    while (temp->next != NULL && count < i - 1)
    {
        temp = temp->next;
        count = count + 1;
    }
    if (temp->next != NULL)
    {
        node *newNode = temp->next;
        temp->next = newNode->next;
        delete newNode;
    }
    else
    {
        cout << "Error: You are trying to Delete position out of Bound of Linked List.Hence,No changes are made in List " << endl;
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