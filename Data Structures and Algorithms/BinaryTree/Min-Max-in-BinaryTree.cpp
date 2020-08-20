/*
Given a binary tree, find and return the min and max data value of given binary tree.
Return the output as an object of PairAns class, which is already created.
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
// O(n^2) approach

/*
int Maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = root->data;
    ans = max(ans, max(Maximum(root->left), Maximum(root->right)));
    return ans;
}

int Minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = root->data;
    ans = min(ans, min(Minimum(root->left), Minimum(root->right)));
    return ans;
}

pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        return p;
    }
    int max1 = root->data, min1 = root->data;
    pair<int, int> leftPart = minMax(root->left);
    pair<int, int> rightPart = minMax(root->right);
    max1 = max(max1, max(leftPart.first, rightPart.first));
    min1 = min(min1, min(leftPart.second, rightPart.second));
    pair<int, int> p;
    p.first = max1;
    p.second = min1;
    return p;
}
*/

//O(n) approach

pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        return p;
    }
    int max1 = root->data, min1 = root->data;
    pair<int, int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);
    int leftMax = leftAns.first;
    int rightMax = rightAns.first;
    max1 = max(max1, max(leftMax, rightMax));

    int leftMin = leftAns.second;
    int rightMin = rightAns.second;

    min1 = min(min1, min(leftMin, rightMin));
    pair<int, int> p;
    p.first = max1;
    p.second = min1;
    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> ans = minMax(root);
    cout << "Maximum: " << ans.first << endl
         << "Minimum:" << ans.second << endl;
    delete root;
}