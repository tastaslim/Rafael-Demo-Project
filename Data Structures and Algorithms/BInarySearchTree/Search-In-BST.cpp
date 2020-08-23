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

// Generally O(logn) but can go to O(n) if tree is skewed
BinaryTreeNode<int> *searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return NULL;
    if (root->data < k)
        root = searchInBST(root->right, k);
    else if (root->data > k)
        root = searchInBST(root->left, k);
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    BinaryTreeNode<int> *ans = searchInBST(root, k);
    cout << ans << " ";
    delete root;
}
