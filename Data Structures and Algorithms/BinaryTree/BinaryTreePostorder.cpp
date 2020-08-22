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

// Using recursion ---> DFS

/*
void Postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
*/

// Using BFS--> Iterative
void Postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    stack<BinaryTreeNode<int> *> s1;
    s1.push(root);
    stack<BinaryTreeNode<int> *> s2;
    while (!s1.empty())
    {
        BinaryTreeNode<int> *topper = s1.top();
        s2.push(topper);
        s1.pop();
        if (topper->left)
        {
            s1.push(topper->left);
        }
        if (topper->right)
        {
            s1.push(topper->right);
        }
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Postorder(root);
    delete root;
}