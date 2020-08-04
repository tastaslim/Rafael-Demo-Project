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
node *mid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void *arrange(node *head)
{
    node *temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    node *temp2 = ReverseLinkedList(temp1);
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    // node *ansH = temp1, *ansT = temp1;
    // temp1 = temp1->next;
    // bool m = true;
    // while (temp1 != temp2)
    // {
    //     if (m)
    //     {
    //         ansT->next = temp2;
    //         temp2 = temp2->next;
    //         m = false;
    //     }
    //     else
    //     {
    //         ansT->next = temp1;
    //         temp1 = temp1->next;
    //         m = true;
    //     }
    // }
    // ansT->next = temp1;
    // ansT = ansT->next;
    // ansT->next = NULL;
    // return ansH;
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
    arrange(head);
    // print(head);
    return 0;
}