
// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *head1 = inputList(n);

        cin >> m;
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
    // code here
    // return the head of intersection list
    Node *ansT = NULL;
    Node *ansH = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    unordered_map<int, int> mp;
    while (temp2 != NULL)
    {
        mp[temp2->data]++;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        if (mp[temp1->data] > 0)
        {
            if (ansH == NULL)
            {
                ansH = temp1;
                ansT = temp1;
            }
            else
            {
                ansT->next = temp1;
                ansT = ansT->next;
            }
            mp[temp1->data]--;
        }
        temp1 = temp1->next;
    }
    ansT->next = NULL;
    return ansH;
}