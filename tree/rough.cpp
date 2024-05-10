#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* BuildTreee(){
    
    int x; cin>>x;
    Node* root=new Node(x);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        int left,right;
        cin>>left;
        if(left!=-1){
            temp->left=new Node(left);
            q.push(temp->left);
        }
        cin>>right;
        if(right!=-1){
            temp->right=new Node(right);
            q.push(temp->right);
        }
    }
    return root;

}

void levelordertraversal(Node* root){
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

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    if(root->left) preorder(root->left);
    if(root->right) preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(Node* root){
    if(root==NULL) return;
    
    if(root->left) inorder(root->left);
    cout<<root->data<<" ";
    if(root->right) inorder(root->right);
    
}

int Height(Node* root){
    if(root==NULL) return 0;
    return 1+ max(Height(root->left), Height(root->right));
}


int main(){
    Node* root=BuildTreee();

    cout<<"LEVELORDER TRAVERSAL : ";levelordertraversal(root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL : "; preorder(root);
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL : "; postorder(root);
    cout<<endl;
    cout<<"INORDER TRAVERSAL : "; inorder(root);

    int ht=Height(root);
    cout<<"Height of tree is : "<<ht<<endl;





    return 0;

   

    
}
