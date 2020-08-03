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

// Reversing K LinkedList
node *kReverse(node *head, int k)
{
    node *temp = head;
    int count = 0;
    node *ne = NULL;
    node *prev = NULL;
    while (temp != NULL && count < k)
    {
        ne = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ne;
        count++;
    }
    if (ne != NULL)
    {
        head->next = kReverse(ne, k);
    }
    head = prev;
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
    int k;
    cin >> k;
    node *head1 = kReverse(head, k);
    print(head1);
    return 0;
}