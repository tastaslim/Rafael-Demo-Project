/*
Given a binary tree, check if its balanced i.e. depth of left and 
right subtrees of every node differ by at max 1. 
Return true if given binary tree is balanced, false otherwise.
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

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = max(height(root->left), height(root->right));
    return ans + 1;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int ans = h1 - h2;
    if (ans != 0 && ans != -1 && ans != 1)
    {
        return false;
    }
    bool m = isBalanced(root->left);
    bool n = isBalanced(root->right);
    return m && n;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    bool ans = isBalanced(root);
    if (ans)
    {
        cout << "Balanced Binary Tree" << endl;
    }
    else
    {
        cout << "Not Balanced Binary Tree" << endl;
    }
    return 0;
}