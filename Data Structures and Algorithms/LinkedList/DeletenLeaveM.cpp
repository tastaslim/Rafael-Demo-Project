#include <iostream>
using namespace std;
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

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

node *skipMdeleteN(node *head, int m, int n)
{
    if (m == 0)
        return NULL;
    if (n == 0)
        return head;

    node *temp = head;
    while (temp != NULL)
    {
        node *temp1 = temp;
        int count = 0;
        while (temp1 != NULL && count < m - 1)
        {
            count++;
            temp1 = temp1->next;
        }
        node *temp2 = NULL;
        if (temp1 != NULL)
            temp2 = temp1->next;
        else
            return head;

        count = 0;
        while (temp2 != NULL && count < n)
        {
            node *h = temp2;
            count++;
            temp2 = temp2->next;
            delete h;
        }
        temp1->next = temp2;
        temp = temp2;
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
    cout << endl;
}
int main()
{
    node *head = takeinput();
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;
}
