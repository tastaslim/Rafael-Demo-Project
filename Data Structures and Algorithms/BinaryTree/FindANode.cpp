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

// Using DFS --> Recursion
/*bool FindNode(BinaryTreeNode<int> *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return true;
    bool m = FindNode(root->left, value);
    bool n = FindNode(root->right, value);
    if (m || n)
        return true;
    return false;
}
*/
// Using BFS Queue
bool FindNode(BinaryTreeNode<int> *root, int value)
{

    if (root == NULL)
        return false;
    queue<BinaryTreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        if (front->data == value)
            return true;
        waiting.pop();
        if (front->left)
        {
            if (front->left->data == value)
                return true;
            waiting.push(front->left);
        }
        if (front->right)
        {
            if (front->right->data == value)
                return true;
            waiting.push(front->right);
        }
    }

    return false;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int value;
    cin >> value;
    bool ans = FindNode(root, value);
    cout << ans << endl;
    delete root;
}