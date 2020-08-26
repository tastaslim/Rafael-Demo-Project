#include "CommonTemplate.h"
class pairT
{
public:
    int minimum;
    int maximum;
    bool check;
};

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

//Method 1 O(n^2) approach
/*
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int a = maximum(root->left);
    int b = minimum(root->right);
    bool k = (root->data > a) && (root->data <= b) && (isBST(root->left)) && (isBST(root->right));
    return k;
}
*/

// Method 2 O(n) approach using pairs
/*
pairT helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pairT p;
        p.minimum = INT_MAX;
        p.maximum = INT_MIN;
        p.check = true;
        return p;
    }
    pairT leftAns = helper(root->left);
    pairT rightAns = helper(root->right);
    int a = leftAns.maximum;
    int b = rightAns.maximum;
    int maxi = max(root->data, max(a, b));

    int a1 = leftAns.minimum;
    int b1 = rightAns.minimum;
    int mini = min(root->data, min(a1, b1));

    bool ans = (root->data > leftAns.maximum) && (root->data < rightAns.minimum) && (leftAns.check) && (rightAns.check);
    pairT p;
    p.minimum = mini;
    p.maximum = maxi;
    p.check = ans;

    return p;
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    pairT p = helper(root);
    return p.check;
}*/

//Method 3 ---> Best easiest and efficient
bool isBST(BinaryTreeNode<int> *root, int minimum, int maximum)
{
    if (root == NULL)
        return true;
    if (root->data > maximum || root->data < minimum)
        return false;
    bool isLeftOk = isBST(root->left, minimum, root->data - 1);
    bool isRightOk = isBST(root->right, root->data, maximum);
    return isLeftOk && isRightOk;
}

bool isBST(BinaryTreeNode<int> *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    bool m = isBST(root);
    if (m)
        cout << "Binary tree is Binary Search Tree";
    else
    {
        cout << "Binary Tree is not a Binary Search Tree";
    }
    return 0;
}