/*
Given a binary tree, print all nodes that don’t have a sibling.
Edit : Print the elements in different lines. And order of elements 
doesn't matter.
Input format :

Elements in level order form (separated by space). If any node does 
not have left or right child, take -1 in its place.

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

void printNodesWithoutSiblings(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    if ((root->left && root->right == NULL) || (root->left == NULL && root->right))
    {
        if (root->left)
            cout << root->left->data << endl;
        else
            cout << root->right->data << endl;
    }
    printNodesWithoutSiblings(root->left);
    printNodesWithoutSiblings(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printNodesWithoutSiblings(root);
}