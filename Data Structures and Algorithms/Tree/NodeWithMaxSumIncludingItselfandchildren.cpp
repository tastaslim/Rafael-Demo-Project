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

pair<TreeNode<int> *, int> NodeWithMaxChildSumIncludingItself(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<TreeNode<int> *, int> p;
        p.first = NULL;
        p.second = 0;
        return p;
    }

    int count = 0;
    TreeNode<int> *ans = root;
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        int temp = 0;
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            temp += front->children[i]->data;
        }
        if (temp + front->data > count)
        {
            ans = front;
            count = temp + front->data;
        }
    }
    pair<TreeNode<int> *, int> p;
    p.first = ans;
    p.second = count;
    return p;
}

int main()
{
    TreeNode<int> *root = takeInput();
    pair<TreeNode<int> *, int> ans1 = NodeWithMaxChildSumIncludingItself(root);
    cout << ans1.first->data << " " << ans1.second << endl;
    return 0;
}