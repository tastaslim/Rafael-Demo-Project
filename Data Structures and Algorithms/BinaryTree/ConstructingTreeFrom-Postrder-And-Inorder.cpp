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

BinaryTreeNode<int> *buildTree(int *postorder, int postS, int postE, int *inorder, int inS, int inE)
{
    if (postS > postE || inS > inE)
        return NULL;
    int rootData = postorder[postE];
    //Indexes to build left part of tree
    int leftpostS = postS;
    int leftinS = inS;
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftinE = rootIndex - 1;
    int leftpostE = leftpostS + leftinE - leftinS;
    // Indexes to build right part of tree
    int rightpostE = postE - 1;
    int rightinS = rootIndex + 1;
    int rightinE = inE;
    int rightpostS = leftpostE + 1;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);                           //  create a root node
    root->left = buildTree(postorder, leftpostS, leftpostE, inorder, leftinS, leftinE);      // join the left recursively
    root->right = buildTree(postorder, rightpostS, rightpostE, inorder, rightinS, rightinE); // join the right
    return root;                                                                             // return root
}

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
    return buildTree(postorder, 0, postLength - 1, inorder, 0, inLength - 1);
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
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(post, size, in, size);
    print(root);
}
