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

int countNonLeafNodes(Node* root, int& count){
    if(root==NULL){
        return 0;
    }
    if(!root->left && !root->right){
        return 0;
    }
    return 1+ countNonLeafNodes(root->left,count)+countNonLeafNodes(root->right,count);
}


int main() {
    Node* root = buildTree();

    cout << "Level Order Traversal of the binary tree: ";
    levelOrderTraversal(root);
    cout << endl;

    int count=0;
    cout<<"no of leaf nodes are: "<<countNonLeafNodes(root, count);
    

    return 0;
}
