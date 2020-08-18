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

// Method 1

/*void PrintAllLeafNodes(TreeNode<int> *root, int depth, int &k)
{
    if (depth == 0)
    {
        k = k + 1;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintAllLeafNodes(root->children[i], depth - 1, k);
    }
}

int HeightOfTree(TreeNode<int> *root)
{
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int k = HeightOfTree(root->children[i]);
        if (k > count)
            count = k;
    }
    return count + 1;
}*/

// Method 2

int PrintAllLeafNodes(TreeNode<int> *root)
{
    // Not a base case it is just here to check ki koi tumhare maje toh nhi le rha empty tree bhej ke
    if (root == NULL)
    {
        return 0;
    }
    int k = 0;
    if (root->children.size() == 0)
    {
        k = k + 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        k = k + PrintAllLeafNodes(root->children[i]);
    }
    return k;
}

int main()
{
    TreeNode<int> *root = takeInput();
    /*int height = HeightOfTree(root);
    int k = 0;
    PrintAllLeafNodes(root, height - 1, k);
    cout << k << endl;
    */
    int ans = PrintAllLeafNodes(root);
    cout << ans << endl;
    return 0;
}