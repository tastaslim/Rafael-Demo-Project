// Since in PreOrder we traverse Generic tree in this manner:
// Left Right Root

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

bool SearchANode(TreeNode<int> *root, int value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool k = SearchANode(root->children[i], value);
        if (k)
            return true;
    }
    return false;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int value;
    cin >> value;
    bool m = SearchANode(root, value);
    if (m)
    {
        cout << "Node is present";
    }
    else
    {
        cout << "Node is not present";
    }

    return 0;
}