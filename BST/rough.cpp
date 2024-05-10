#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    Node(int val){
        left=right=NULL;
        data=val;
    }
};

void insert(Node*& root, int x){
    if(root==NULL){
        root=new Node(x);
        return;
    }
    if(x<root->data){
        insert(root->left,x);
    }
    if(x>root->data){
        insert(root->right,x);
    }
}

Node* BuildBST(){
    int x;
    cin>>x;
    Node* root=NULL;
    while(x!=-1){
        insert(root,x);
        cin>>x;
    }
    return root;
}

void LevelOrderTraversal(Node* root){
    if(root==NULL) return;
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

bool SearchInBSt(Node* root, int key){
    if(root==NULL) return false;
    if(key==root->data){
        return true;
    }
    if(key>root->data){
        return SearchInBSt(root->right,key);
    }
    else{
        return SearchInBSt(root->left,key);
    }
    return false;
}



int main(){

    Node* root=BuildBST();
    

    // int key; cin>>key;
    // bool isElementPresent=SearchInBSt(root,key);
    // cout<<isElementPresent<<endl;

    
            
    return 0;
}
