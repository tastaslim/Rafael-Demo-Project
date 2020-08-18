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

int countNodes1(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 1;
    // BFS Traversal Using Queue
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            ans = ans + 1;
        }
    }
    return ans;
}

int countNodes2(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 1;
    // DFS Traversal
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + countNodes2(root->children[i]);
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInput();
    int ans1 = countNodes1(root);
    int ans2 = countNodes2(root);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}