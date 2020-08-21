/*
Given a binary tree, print the zig zag order i.e print level 1 from 
left to right, level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even 
level right to left.

Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output Format :

Elements are printed level wise, each level in new line (separated 
by space).
Sample Input :

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :

5
10 6
2 3
9


*/
#include "CommonTemplate.h"
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

vector<vector<int>> levelOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        vector<vector<int>> v;
        return v;
    }
    queue<BinaryTreeNode<int> *> q;
    vector<vector<int>> v;
    vector<int> v1;
    q.push(root);
    q.push(NULL);
    int i = 0;
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front)
        {
            v1.push_back(front->data);
        }
        else
        {
            if (q.empty())
            {
                v.push_back(v1);
                break;
            }
            q.push(NULL);
            v.push_back(v1);
            v1.clear();
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

void printzigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    vector<vector<int>> v = levelOrder(root);
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < v[i].size(); j++)
                cout << v[i][j] << " ";
        }
        else
        {
            for (int j = v[i].size() - 1; j >= 0; j--)
                cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printzigZagOrder(root);
    return 0;
}
