#include "CommonTemplate.h"

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

// Using DFS --> Queue
/*
bool isSame(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (!p && !q)
        return true;
    if ((!p && q) || (p && !q))
        return false;
    if (p->data != q->data)
        return false;
    queue<BinaryTreeNode<int> *> q1;
    queue<BinaryTreeNode<int> *> q2;
    q1.push(p), q2.push(q);
    while (!q1.empty() && !q2.empty())
    {
        BinaryTreeNode<int> *front1 = q1.front();
        BinaryTreeNode<int> *front2 = q2.front();
        q1.pop();
        q2.pop();
        if (front1->data != front2->data)
            return false;

        if ((front1->left && !front2->left) || (front2->left && !front1->left) || (front1->right && !front2->right) || (front2->right && !front1->right))
            return false;
        if (front1->left)
        {
            q1.push(front1->left);
        }
        if (front1->right)
        {
            q1.push(front1->right);
        }
        if (front2->left)
        {
            q2.push(front2->left);
        }
        if (front2->right)
        {
            q2.push(front2->right);
        }
    }
    if (!q1.empty() || !q2.empty())
        return false;

    return true;
}
*/
// Using DFS --->>> recursion

bool isSame(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (!p && !q)
        return true;
    if ((!p && q) || (p && !q))
        return false;
    if (p->data != q->data)
        return false;

    return isSame(p->left, q->left) && isSame(p->right, q->right);
}

int main()
{
    BinaryTreeNode<int> *root1 = takeInput();
    BinaryTreeNode<int> *root2 = takeInput();
    bool m = isSame(root1, root2);
    if (m)
        cout << "Same Binary Tree";
    else
        cout << "Different Binary Tree";

    delete root1;
    delete root2;
}