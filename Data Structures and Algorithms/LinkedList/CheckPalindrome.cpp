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

// Reversing LinkedList
node *ReverseLinkedList(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *curr = head;
    node *prev = NULL;
    node *nex = NULL;
    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
    return head;
}
// Length of LinkedList
int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }
    return count;
}

bool checkPal(node *head)
{
    bool m = true;
    int len = length(head);
    node *h = NULL;
    node *temp = head;
    if (len % 2 != 0)
    {
        int k = len / 2;
        int i = 0;
        while (i < k - 1)
        {
            temp = temp->next;
            i++;
        }
        h = temp->next->next;
    }

    else
    {
        int k = len / 2;
        int i = 0;
        while (i < k - 1)
        {
            temp = temp->next;
            i++;
        }
        h = temp->next;
    }
    temp->next = NULL;
    temp = head;
    h = ReverseLinkedList(h);
    while (temp != NULL || h != NULL)
    {
        if (temp->data != h->data)
        {
            m = false;
            break;
        }
        temp = temp->next;
        h = h->next;
    }
    return m;
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
    bool m = checkPal(head);
    // head = ReverseLinkedList(head);
    //print(head);
    if (m)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }
    return 0;
}