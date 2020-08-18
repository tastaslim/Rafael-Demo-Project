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

TreeNode<int> *MaximumDataNode(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    TreeNode<int> *ans = root;
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            if (front->children[i]->data > ans->data)
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
    TreeNode<int> *ans1 = MaximumDataNode(root);
    cout << ans1->data << endl;
    return 0;
}