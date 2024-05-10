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

int heightLeft(Node* root){
    if(root == NULL) return 0;
    return 1 + heightLeft(root->left);
}

int heightRight(Node* root){
    if(root == NULL) return 0;
    return 1 + heightRight(root->right);
}

int diameter(Node* root){
    if(root == NULL) return 0; // Base case

    int leftHeight = heightLeft(root->left);
    int rightHeight = heightRight(root->right);
    
    // Calculate the diameter passing through the current node
    int diameterThroughRoot = leftHeight + rightHeight;
    
    // Recursively find the diameter in left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    
    // Return the maximum of the three diameters
    return max(diameterThroughRoot, max(leftDiameter, rightDiameter));
}


int main(){
    Node* root=BuildTreee();

    cout<<"LEVELORDER TRAVERSAL : ";levelordertraversal(root);
    cout<<endl;

    return 0;

}
