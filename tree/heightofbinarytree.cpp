#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* BuildBinaryTree(){
    int x; cin>>x;
    int first,second;
    queue<Node*> q;
    Node* root=new Node(x);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cin>>first;
        if(first!=-1){
            temp->left=new Node(first);
            q.push(temp->left);
        }

        cin>>second;
        if(second!=-1){
            temp->right=new Node(second);
            q.push(temp->right);
        }


    }
    return root;

}

int heightofBinaryTree(Node* root, int& count){
    if(root==NULL){
        return 0;
    }
    int left=heightofBinaryTree(root->left,count);
    int right=heightofBinaryTree(root->right,count);

    return 1+max(left,right);
}

void LevelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){

    Node* root=BuildBinaryTree();  
    LevelOrderTraversal(root);

    int count=0;
    cout<<"height is "<<heightofBinaryTree(root,count);
    return 0;
}
