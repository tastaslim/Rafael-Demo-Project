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
int Height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1 + max(Height(root->left), Height(root->right));
    return ans;
}

int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int a = Height(root->left) + Height(root->right);
    int b = diameter(root->left);
    int c = diameter(root->right);
    int ans = max(a, max(b, c));
    return ans;
}
*/

//O(n) approach
pair<int, int> diameterHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = diameterHelper(root->left);
    pair<int, int> rightAns = diameterHelper(root->right);
    int leftheight = leftAns.first;
    int rightheight = rightAns.first;
    int height = max(leftheight, rightheight) + 1;

    int leftdiameter = leftAns.second;
    int rightdiameter = rightAns.second;

    pair<int, int> p;
    p.first = height;
    p.second = max(leftheight + rightheight, max(leftdiameter, rightdiameter));
    return p;
}
int diameter(BinaryTreeNode<int> *root)
{
    pair<int, int> p = diameterHelper(root);
    return p.second;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int ans = diameter(root);
    cout << ans << endl;
    delete root;
}