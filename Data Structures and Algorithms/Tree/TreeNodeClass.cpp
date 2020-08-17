//Since in a tree a node can have many childs. So implement it:
// What are data structures we know so far:
// 1. Arrays 2. Linked List

// Problem with array is we have issues of size as size is constant here.
// Problem with linked list is access  of an element, since to access any element
// We need to traverese from starting in each case.

// Okay, what can we do then? If we are able to solve size problem of array
// We can use it to implement tree.
//Here comes vector into picture as vector handles size problems
#include "CommonTemplate.h"
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
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *root1 = new TreeNode<int>(2);
    TreeNode<int> *root2 = new TreeNode<int>(3);
    TreeNode<int> *root3 = new TreeNode<int>(4);
    TreeNode<int> *root4 = new TreeNode<int>(5);
    TreeNode<int> *root5 = new TreeNode<int>(6);
    TreeNode<int> *root6 = new TreeNode<int>(7);
    root->children.push_back(root1);
    root->children.push_back(root2);
    root1->children.push_back(root3);
    root2->children.push_back(root5);
    root2->children.push_back(root6);
    root3->children.push_back(root4);
    print(root);
    return 0;
}