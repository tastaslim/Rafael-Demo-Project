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

BinaryTreeNode<int> *constructTree(int *input, int n, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTree(input, n, start, mid - 1);
    root->right = constructTree(input, n, mid + 1, end);
    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    return constructTree(input, n, 0, n - 1);
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
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    BinaryTreeNode<int> *root = constructTree(arr, n);
    print(root);
}