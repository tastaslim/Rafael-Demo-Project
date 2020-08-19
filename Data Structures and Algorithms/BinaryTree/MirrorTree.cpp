/*
Mirror the given binary tree. That is, right child of every nodes should 
become left and left should become right.
*/
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

// Using BFS --->> Queue

void MirrorTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        waiting.pop();
        if (front->left)
        {
            waiting.push(front->left);
        }
        if (front->right)
        {
            waiting.push(front->right);
        }
        swap(front->left, front->right);
    }
}
// Using recursion

/*
void MirrorTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    swap(root->left, root->right);
    MirrorTree(root->left);
    MirrorTree(root->right);
}
*/
void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        cout << front->data << ":";
        waiting.pop();
        if (front->left)
        {
            cout << "L:" << front->left->data << ",";
            waiting.push(front->left);
        }
        else
        {
            cout << "L:" << -1 << ",";
        }
        if (front->right)
        {
            cout << "R:" << front->right->data;
            waiting.push(front->right);
        }
        else
        {
            cout << "R:" << -1;
        }
        cout << endl;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);
    delete root;
}