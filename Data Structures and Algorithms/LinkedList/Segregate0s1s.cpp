#include <iostream>
using namespace std;
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

Node *SegregatezeroOne(Node *head)
{
    Node *evenH = NULL, *evenT = NULL, *oddH = NULL, *oddT = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = temp;
                evenT = temp;
            }
            else
            {
                evenT->next = temp;
                evenT = evenT->next;
            }
        }
        else
        {
            if (oddH == NULL)
            {
                oddH = temp;
                oddT = temp;
            }
            else
            {
                oddT->next = temp;
                oddT = oddT->next;
            }
        }
        temp = temp->next;
    }
    evenT->next = oddH;
    oddT->next = NULL;
    head = evenH;
    return head;
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
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int l1;
        cin >> l1;
        int first1;
        cin >> first1;
        Node *head1 = new Node(first1);
        Node *tail1 = head1;
        while (l1 != 1)
        {
            int inp;
            cin >> inp;
            tail1->next = new Node(inp);
            tail1 = tail1->next;
            l1--;
        }
        head1 = SegregatezeroOne(head1);
        print(head1);
        cout << endl;
    }
}