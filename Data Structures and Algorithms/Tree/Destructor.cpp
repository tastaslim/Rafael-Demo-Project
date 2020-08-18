// Since after completing our work, we should free memeory as weel.
//And we need to do it manually because
// We have created nodes dynamically
// Hence To delete nodes of tree: We will first delete
// their child and then delete them

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            delete this->children[i];
        }
    }
};
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

/*void DeleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        DeleteTree(root->children[i]);
    }
    delete root;
}
*/

int main()
{
    TreeNode<int> *root = takeInput();
    print(root);

    //One way is to use post order to delete

    /*DeleteTree(root);*/

    // But you see we are using extra function.
    //Like previous chapter we want to use just
    // delete root and we want tree to be deleted
    // What to do :   We will use destructor for this task;
    // Since we know as soon as we use delete
    // keyward a destructor is called
    // hence we will make our destructor in such a way to delete tree
    delete root;
}