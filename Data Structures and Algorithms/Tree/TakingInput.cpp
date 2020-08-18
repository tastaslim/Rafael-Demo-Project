#include "CommonTemplate.h"
TreeNode<int> *takeInput()
{
    int value;
    cout << "Enter node data:";
    cin >> value;
    TreeNode<int> *root = new TreeNode<int>(value);

    int n;
    cout << "Enter number of children of node " << value << ":";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

template <typename T>
// DFS Approach to print ---> There are 3 types:
// Inorder, Preorder, Postorder
void print(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children.at(i));
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    print(root);
}