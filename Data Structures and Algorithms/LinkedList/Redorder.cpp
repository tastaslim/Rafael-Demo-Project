#include <iostream>
using namespace std;

//Take Input Code
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *TakeInput()
{
    int value;
    cin >> value;
    Node *head = NULL;
    Node *tail = NULL;
    while (value != -1)
    {
        Node *newNode = new Node(value);
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

Node *MidPoint(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *Reverse(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *curr = head, *prev = NULL, *nex = NULL;
    while (curr)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *reorderList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *ans = MidPoint(head);
    Node *h2 = ans->next;
    ans->next = NULL;
    h2 = Reverse(h2);
    // print(head);
    // cout << endl;
    // print(h2);
    // cout << endl;
    Node *ansH = NULL, *ansT = NULL;
    bool m = true;
    while (h2 && head)
    {
        if (m)
        {
            Node *newNode = new Node(head->data);
            if (!ansH)
            {
                ansH = head;
                ansT = head;
            }
            else
            {
                ansT->next = newNode;
                ansT = ansT->next;
            }
            head = head->next;
            m = false;
        }
        else
        {
            Node *newNode = new Node(h2->data);
            ansT->next = newNode;
            ansT = ansT->next;
            h2 = h2->next;
            m = true;
        }
    }

    if (head)
    {
        Node *newNode = new Node(head->data);
        ansT->next = newNode;
        ansT = ansT->next;
        head = head->next;
    }

    if (h2)
    {
        Node *newNode = new Node(h2->data);
        ansT->next = newNode;
        ansT = ansT->next;
        h2 = h2->next;
    }
    ansT->next = NULL;
    return ansH;
}

int main()
{
    Node *head = TakeInput();
    Node *ans = reorderList(head);
    print(head);
    return 0;
}