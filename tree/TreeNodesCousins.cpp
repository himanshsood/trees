#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree() {
    int x;
    cin >> x;

    queue<Node*> q;
    Node* root = new Node(x);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int first, second;
        cin >> first;
        if (first != -1) {
            temp->left = new Node(first);
            q.push(temp->left);
        }

        cin >> second;
        if (second != -1) {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }

    return root;
}


void levelOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}



bool TreeNodesCousins(Node* root, int x, int y){
    if(root==NULL) return 0;

    if(root->left && root->right){
        if(root->left->data==x && root->right->data==y){
            return 1;
        }
        if(root->left->data==y && root->right->data==x){
            return 1;
        }

        
    }
    
        return TreeNodesCousins(root->left,x,y)+ TreeNodesCousins(root->right, x,y);
}



int main() {
    Node* root = buildTree();
    int x,y;
    cin>>x>>y;

    cout << "Level Order Traversal of the binary tree: ";
    levelOrderTraversal(root);
    cout << endl;

    TreeNodesCousins(root, x,y);

    return 0;
}
