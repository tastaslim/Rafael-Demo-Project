/*
Given a binary tree, write code to create a separate linked list for each 
level. You need to return the array which contains head of each level linked list.

Input format :

Elements in level order form (separated by space). If any node 
does not have left or right child, take -1 in its place.

Output format : Each level linked list is printed in new line 
(elements separated by space).
Sample Input :

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :

5 
6 10 
2 3 
9
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

vector<node<int> *> createLLForEachLevel(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        vector<node<int> *> v;
        return v;
    }
    queue<BinaryTreeNode<int> *> q;
    vector<node<int> *> v;
    node<int> *head = NULL;
    node<int> *tail = NULL;
    q.push(root);
    q.push(NULL);
    int i = 0;
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front)
        {
            node<int> *newNode = new node<int>(front->data);
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
        }
        else
        {
            if (q.empty())
            {
                v.push_back(head);
                break;
            }
            q.push(NULL);
            v.push_back(head);
            head = NULL;
            tail = NULL;
            continue;
        }

        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
    return v;
}

void print(node<int> *head)
{
    node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<node<int> *> ans = createLLForEachLevel(root);
    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}
