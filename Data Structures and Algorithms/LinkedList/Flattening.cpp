#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
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



/*  Function which returns the  root of
    the flattened linked list. */
Node *MergeTwoSortedLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *outputTail = NULL;
    Node *outputHead = NULL;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            if (outputHead == NULL)
            {
                outputHead = temp2;
                outputTail = temp2;
            }
            else
            {
                outputTail->next = temp2;
                outputTail = outputTail->next;
            }

            temp2 = temp2->next;
        }
        else
        {
            if (outputTail == NULL)
            {
                outputTail = temp1;
                outputHead = temp1;
            }
            else
            {
                outputTail->next = temp1;
                outputTail = outputTail->next;
            }
            temp1 = temp1->next;
        }
    }

    if (temp1 != NULL)
    {
        outputTail->next = temp1;
        temp1 = temp1->next;
        outputTail = outputTail->next;
    }
    if (temp2 != NULL)
    {
        outputTail->next = temp2;
        temp2 = temp2->next;
        outputTail = outputTail->next;
    }
    return outputHead;
}

//Finding Mid Point

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

// Merge Sort
Node *MergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = MidPoint(head);
    Node *h1 = head;
    Node *h2 = mid->next;
    mid->next = NULL;
    h1 = MergeSort(h1);
    h2 = MergeSort(h2);
    Node *final = MergeTwoSortedLL(h1, h2);
    return final;
}

Node *flatten(Node *root)
{
    if (!root)
    {
        return root;
    }
    Node *temp=root;
    Node *ansH=NULL, *ansT=NULL;
    while (temp!=NULL)
    {
        if (!ansH)
        {
            ansH=temp;
            ansT=temp;
        }
        else
        {
            ansT->next=temp;
            ansT=ansT->next;
        }
        Node *bot=temp->bottom;
        while (bot)
        {
            ansT->next=bot;
            ansT=ansT->next;
            bot=bot->bottom;
        }
        temp=temp->next;
    }
    ansT->next=NULL;
    // ansH=MergeSort(ansH);
     //root=NULL;
     //root=ansH;
    return ansH;
}

