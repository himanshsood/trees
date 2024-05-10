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

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

    
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

int size(Node* root, int& count){
    if(root==NULL){
        return 0;
    }
    count++;
    size(root->left, count);
    size(root->right,count);

    return count;

}


int main() {
    int x;
    cin >> x;

    int first, second;
    queue<Node*> q;
    Node* root = new Node(x);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        
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

    cout << "Level Order Traversal of the binary tree: ";
    levelOrderTraversal(root);
    cout << endl;

    int count=0;

    cout<<"size of tree is "<<size(root,count);

    return 0;
}