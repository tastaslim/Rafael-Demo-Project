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

/*
int sumOfNodes(TreeNode<int>* root) {
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum=sum+sumOfNodes(root->children[i]);
    }
    return sum;
}
*/

int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = root->data;
    queue<TreeNode<int> *> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            waiting.push(front->children[i]);
            ans = ans + front->children[i]->data;
        }
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int ans1 = sumOfNodes(root);
    cout << ans1 << endl;
    return 0;
}