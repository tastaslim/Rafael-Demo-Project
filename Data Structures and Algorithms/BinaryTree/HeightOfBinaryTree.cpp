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

// Using BFS Queue

// This method also calculates depth of each
//node and replaces nodes data with it's depth value

/*int Height(BinaryTreeNode<int> *root)
{

    if (root == NULL)
        return 0;
    int count = 0;
    queue<BinaryTreeNode<int> *> waiting;
    root->data = 0;
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        waiting.pop();
        if (front->left)
        {
            front->left->data = front->data + 1;
            waiting.push(front->left);
        }
        if (front->right)
        {
            front->right->data = front->data + 1;
            waiting.push(front->right);
        }
        count = front->data + 1;
    }

    return count;
}
*/
// Using recursion
int Height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1 + max(Height(root->left), Height(root->right));
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int ans = Height(root);
    cout << ans << endl;
    delete root;
}