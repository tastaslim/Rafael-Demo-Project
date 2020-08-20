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

// Constructing Tree

BinaryTreeNode<int> *buildTree(int *preorder, int preS, int preE, int *inorder, int inS, int inE)
{
    if (preS > preE || inS > inE)
        return NULL;

    int rootData = preorder[preS];

    //Indexes to build left part of tree
    int leftpreS = preS + 1;
    int leftinS = inS;
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootData)
            rootIndex = i;
    }
    int leftinE = rootIndex - 1;
    int leftpreE = leftinE - leftinS + leftpreS;

    // Indexes to build right part of tree
    int rightpreS = leftpreE + 1;
    int rightpreE = preE;
    int rightinS = rootIndex + 1;
    int rightinE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(preorder, leftpreS, leftpreE, inorder, leftinS, leftinE);
    root->right = buildTree(preorder, rightpreS, rightpreE, inorder, rightinS, rightinE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildTree(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
}

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
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    print(root);
}
