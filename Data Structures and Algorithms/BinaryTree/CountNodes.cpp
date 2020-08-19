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
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    count = count + countNodes(root->left) + countNodes(root->right);
    return count + 1;
}
// Using BFS Queue
/*int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    queue<BinaryTreeNode<int> *> waiting;
    waiting.push(root);
    int count = 1;
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        waiting.pop();
        if (front->left)
        {
            waiting.push(front->left);
            count++;
        }
        if (front->right)
        {
            waiting.push(front->right);
            count++;
        }
    }

    return count;
}
*/
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int ans = countNodes(root);
    cout << ans << endl;
    delete root;
}