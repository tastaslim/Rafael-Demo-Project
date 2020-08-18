//Given two Generic trees, return true if they are structurally identical i.e.
// they are made of nodes with the same values arranged in the same way.

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
// Way 1 using Queue----> BFS
/*bool checkIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if ((root1 && !root2) || (root2 && !root1) || (root1->data != root2->data))
        return false;
    if (!root1 && !root2)
        return true;
    queue<TreeNode<int> *> waiting1;
    queue<TreeNode<int> *> waiting2;
    waiting1.push(root1);
    waiting2.push(root2);

    while (!waiting1.empty() && !waiting2.empty())
    {
        TreeNode<int> *front1 = waiting1.front();
        TreeNode<int> *front2 = waiting2.front();
        waiting1.pop();
        waiting2.pop();
        if (front1->children.size() != front2->children.size())
        {
            return false;
        }
        for (int i = 0; i < front1->children.size(); i++)
        {
            waiting1.push(front1->children[i]);
            waiting2.push(front2->children[i]);
            if (front1->children[i]->data != front2->children[i]->data)
            {
                return false;
            }
        }
    }
    return true;
}
*/

// Way 2 ----> Using Recursion DFS
bool checkIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if ((root1 && !root2) || (root2 && !root1) || (root1->data != root2->data))
        return false;
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool m = checkIdentical(root1->children[i], root2->children[i]);
        if (!m)
            return false;
    }
    return true;
}

int main()
{
    TreeNode<int> *root1 = takeInput();
    TreeNode<int> *root2 = takeInput();
    bool m = checkIdentical(root1, root2);
    if (m)
        cout << "Both are Identical";
    else
        cout << "Both are not identical";

    return 0;
}