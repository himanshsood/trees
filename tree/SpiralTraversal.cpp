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

void SpiralPrint(Node* root, int& count){
    if(!root) return;
    count++;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(count%2==0){
           if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr){
                q.push(temp->right);
        }
        count++;
            
        
        }
        else{
            if (temp->right != nullptr)
            q.push(temp->right);
             if (temp->left != nullptr){
                q.push(temp->left);
             }
            
            count++;
        }
    }




}

int main() {
    Node* root = buildTree();

    cout << "Level Order Traversal of the binary tree: ";
    levelOrderTraversal(root);
    cout << endl;


    cout<<"spiral print is : ";
    int count=0;
    SpiralPrint(root,count);
    

    return 0;
}
