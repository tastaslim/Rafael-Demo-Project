#include "CommonTemplate.h"

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    if (root->left)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);
    delete root;
}