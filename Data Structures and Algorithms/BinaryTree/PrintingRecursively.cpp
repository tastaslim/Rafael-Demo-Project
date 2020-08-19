#include "CommonTemplate.h"

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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *h1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *h2 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *h3 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *h4 = new BinaryTreeNode<int>(5);
    root->left = h1;
    root->right = h2;
    h1->left = h3;
    h2->right = h4;
    print(root);
    delete root;
}