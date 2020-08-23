#include "CommonTemplate.h"
using namespace std;
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    queue<BinaryTreeNode<int> *> waiting;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        waiting.pop();
        int leftChildData;
        cout << "Enter left child data of node " << front->data << ":";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            waiting.push(leftChild);
        }
        int rightChildData;
        cout << "Enter right child data of node " << front->data << ":";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            waiting.push(rightChild);
        }
    }
    return root;
}

// Method 1
vector<int> rightSideView(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    BinaryTreeNode<int> *ans = NULL;
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (!front)
        {
            if (q.empty())
            {
                v.push_back(ans->data);
                break;
            }
            v.push_back(ans->data);
            q.push(NULL);
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
        ans = front;
    }
    return v;
}

//Method 2

/*
vector<int> rightSideView(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n != 0)
        {
            BinaryTreeNode<int> *front = q.front();
            if (n == 1)
            {
                v.push_back(front->data);
            }
            q.pop();

            if (front->left)
            {
                q.push(front->left);
            }

            if (front->right)
            {
                q.push(front->right);
            }
            n--;
        }
    }
    return v;
}
*/
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<int> v = rightSideView(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    return 0;
}