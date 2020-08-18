/*
In a given Generic Tree, replace each node with its depth value.
You need to just update the data of each node, 
no need to return or print anything.
*/
#include "CommonTemplate.h"
TreeNode<int> *takeInput()
{
    int value;
    cout << "Enter node data:";
    cin >> value;
    queue<TreeNode<int> *> waiting;
    TreeNode<int> *root = new TreeNode<int>(value);
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        int num;
        cout << "Enter number of childrens of node " << front->data << ":";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int ch;
            cout << "Enter child " << i + 1 << " data of node " << front->data << ":";
            cin >> ch;
            TreeNode<int> *child = new TreeNode<int>(ch);
            front->children.push_back(child);
            waiting.push(child);
        }
    }
    return root;
}

void ReplaceNodeWithDepthOfTree(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    root->data = 0;
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            front->children[i]->data = front->data + 1;
        }
    }
}

// Method 2
/*
void ReplaceNodeWithDepthOfTree(TreeNode<int> *root, int depth)
{
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        ReplaceNodeWithDepthOfTree(root->children[i], depth + 1);
    }
}
void ReplaceNodeWithDepthOfTree(TreeNode<int> *root)
{
    ReplaceNodeWithDepthOfTree(root, 0);
}
*/
void print(TreeNode<int> *root)
{
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        cout << front->data << ":";
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            waiting.push(front->children[i]);
        }
        cout << endl;
    }
}
int main()
{
    TreeNode<int> *root = takeInput();
    ReplaceNodeWithDepthOfTree(root);
    print(root);
    return 0;
}