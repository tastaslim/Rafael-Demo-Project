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
// Reverse LinkedList
node *ReverseLinkedList(node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    node *temp = ReverseLinkedList(head->next);
    node *temp1 = head->next;
    temp1->next = head;
    head->next = NULL;
    head = temp;
    return head;
}

int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Only Considers l1 > l2
node *subLinkedList(node *l1, node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }

    while (l1->next != NULL)
    {
        if (l1->data != 0)
            break;
        else
        {
            node *h = l1;
            l1 = l1->next;
            delete h;
        }
    }
    while (l2->next != NULL)
    {
        if (l2->data != 0)
            break;
        else
        {
            node *h = l2;
            l2 = l2->next;
            delete h;
        }
    }

    int a = length(l1);
    int b = length(l2);

    cout << a << " " << b << endl;

    int ans = abs(a - b);
    bool m;
    if (ans != 0)
    {
        int check = a - b;
        check > 0 ? m = true : m = false;
        while (ans != 0)
        {
            node *newNode = new node(0);
            if (m)
            {
                newNode->next = l2;
                l2 = newNode;
            }
            else
            {
                newNode->next = l1;
                l1 = newNode;
            }
            ans = ans - 1;
        }
    }
    else
    {
        node *k1 = l1, *k2 = l2;
        while (k1->data == k2->data && k1->next != NULL)
        {
            k1 = k1->next;
            k2 = k2->next;
        }
        if (k1 == NULL)
        {
            node *newNode = new node(0);
            return newNode;
        }

        int hg = k1->data - k2->data;
        if (hg > 0)
        {
            m = true;
        }
        else
        {
            m = false;
        }
    }
    l1 = ReverseLinkedList(l1);
    l2 = ReverseLinkedList(l2);
    node *temp1 = NULL;
    node *temp2 = NULL;
    if (m)
    {
        temp1 = l1;
        temp2 = l2;
    }
    else
    {
        temp1 = l2;
        temp2 = l1;
    }

    node *ansH = NULL;
    int carry = 0;
    while (temp1 != NULL)
    {
        int sum = temp1->data - temp2->data + carry;
        if (sum < 0)
        {
            sum = (sum + 10) % 10;
            carry = -1;
        }
        else
        {
            carry = 0;
        }

        node *newNode = new node(sum);
        if (ansH == NULL)
        {
            ansH = newNode;
            ansH->next = NULL;
        }
        else
        {
            newNode->next = ansH;
            ansH = newNode;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    node *temp3 = ansH;
    while (temp3->next != NULL)
    {
        if (temp3->data != 0)
            break;
        else
        {
            node *h = temp3;
            temp3 = temp3->next;
            ansH = temp3;
            delete h;
        }
    }
    return ansH;
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
    node *head1 = TakeInput();
    node *head2 = TakeInput();
    node *head = subLinkedList(head1, head2);
    print(head);
    return 0;
}