#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    std::cout << "Inorder traversal before deletion: ";
    inorder(root);
    std::cout << std::endl;

    root = deleteNode(root, 3);

    std::cout << "Inorder traversal after deletion: ";
    inorder(root);
    std::cout << std::endl;

    return 0;
}
