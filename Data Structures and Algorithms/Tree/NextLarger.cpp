/*
Given a generic tree and an integer n. Find and return the node 
with next larger element in the Tree i.e. 
find a node with value just greater than n.
Return NULL if no node is present with the value greater than n.
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

TreeNode<int> *count(TreeNode<int> *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<TreeNode<int> *> waiting;
    TreeNode<int> *ans = root;
    waiting.push(root);
    if (root->data > value)
        ans = root;
    bool m = true;

    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            if (front->children[i]->data > value && m)
            {
                ans = front->children[i];
                m = false;
            }
            else if (front->children[i]->data < ans->data && front->children[i]->data > value)
            {
                ans = front->children[i];
            }
        }
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int value;
    cin >> value;
    TreeNode<int> *ans = count(root, value);
    cout << ans->data << endl;
    return 0;
}