#include <bits/stdc++.h>
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

//Length of LinkedList
int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count = count + 1;
    }
    return count;
}

//Remove Consecutive Duplicates in Linked List.
node *removeDuplicates(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head, *ans = NULL;
    node *ansH = NULL;
    unordered_map<int, int> mp;

    for (int i = 0; i < length(head); i++)
    {
        mp[temp->data] = 0;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (mp[temp->data] == 0)
        {
            if (ansH == NULL)
            {
                ansH = temp;
                ans = temp;
            }
            else
            {
                ans->next = temp;
                ans = ans->next;
            }
            mp[temp->data] = 1;
        }
        temp = temp->next;
    }
    ans->next = NULL;
    head = ansH;
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
    head = removeDuplicates(head);
    print(head);
    return 0;
}