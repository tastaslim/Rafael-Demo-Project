//Given a tree and an integer x, find and return the number of Nodes which are greater than x.
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

int count(TreeNode<int> *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0; // To include root
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    if (root->data > value)
        count = count + 1;
    while (!waiting.empty())
    {
        int temp = 0;
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            if (front->children[i]->data > value)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int value;
    cin >> value;
    int ans = count(root, value);
    cout << ans << endl;
    return 0;
}