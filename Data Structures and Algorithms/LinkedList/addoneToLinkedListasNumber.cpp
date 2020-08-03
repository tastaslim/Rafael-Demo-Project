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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *ans = reverse(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return ans;
}
Node *addOne(Node *head)
{
    if (head == NULL)
    {
        Node *ans = new Node(1);
        head = ans;
        return head;
    }
    Node *ans = reverse(head);
    Node *temp = ans;
    int carry = 0;
    Node *prev = NULL;
    int sum = temp->data + 1;
    if (sum > 9)
    {
        temp->data = sum % 10;
        sum = sum / 10;
        carry = sum;
    }
    else
    {
        temp->data = sum;
    }
    temp = temp->next;
    while (temp != NULL && carry != 0)
    {
        prev = temp;
        int s = temp->data + carry;
        if (s > 9)
        {
            temp->data = s % 10;
            s = s / 10;
            carry = s;
        }
        else
        {
            temp->data = s;
            carry = 0;
        }
        temp = temp->next;
    }
    if (carry > 0)
    {
        Node *neww = new Node(carry);
        prev->next = neww;
        neww->next = NULL;
    }
    head = reverse(ans);
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
    Node *head = TakeInput();
    Node *head1 = addOne(head);
    print(head1);
    return 0;
}