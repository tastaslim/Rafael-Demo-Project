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

int countNodes(node *n)
{
    int res = 1;
    node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}
bool DetectLoop(node *head)
{
    node *slow = head;
    node *fast = head;
    int ans = 0;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ans = countNodes(slow);
            break;
        }
    }
    cout << ans << endl;
    return false;
}

int main()
{
    node *head = TakeInput();
    bool ans = DetectLoop(head);
    if (ans)
    {
        cout << "Loop Found";
    }
    else
    {
        cout << "Loop Not found";
    }

    return 0;
}