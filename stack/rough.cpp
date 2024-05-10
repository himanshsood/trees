#include<iostream>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;

    node(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

node* buildTree()
{
    int val;
    cin >> val;
    if(val == -1) // if input value is -1, return NULL
    {
        return NULL;
    }
    // continue building the tree if input value is not -1
    node *root = new node(val);
    root->right = buildTree();
    root->left = buildTree();
    
    return root;
}

int main()
{
    node* root = buildTree();
    inorder(root);
    return 0;
}