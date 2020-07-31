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
node *Sort012s(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    node *zero = NULL, *one = NULL, *two = NULL;
    node *zeroH = NULL, *oneH = NULL, *twoH = NULL;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            if (zero == NULL)
            {
                zero = temp;
                zeroH = temp;
            }
            else
            {
                zero->next = temp;
                zero = zero->next;
            }
        }
        else if (temp->data == 1)
        {
            if (one == NULL)
            {
                one = temp;
                oneH = temp;
            }
            else
            {
                one->next = temp;
                one = one->next;
            }
        }
        else
        {
            if (two == NULL)
            {
                two = temp;
                twoH = temp;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
        }
        temp = temp->next;
    }
    if (zero && one && two)
    {
        zero->next = oneH;
        one->next = twoH;
        two->next = NULL;
        head = zeroH;
    }
    else if (!zero && one && two)
    {
        one->next = twoH;
        two->next = NULL;
        head = oneH;
    }
    else if (!zero && !one && two)
    {
        head = twoH;
        two->next = NULL;
    }
    else if (!zero && one && !two)
    {
        one->next = NULL;
        head = oneH;
    }
    else if (zero && !one && !two)
    {
        zero->next = NULL;
        head = zeroH;
    }
    else if (zero && !one && two)
    {
        zero->next = twoH;
        two->next = NULL;
        head = zeroH;
    }
    else if (zero && one && !two)
    {
        zero->next = oneH;
        one->next = NULL;
        head = zeroH;
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
    head = Sort012s(head);
    print(head);
    return 0;
}