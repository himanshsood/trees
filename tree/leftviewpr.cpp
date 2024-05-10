#include<iostream>
#include<queue>
#include<vector>
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

vector<int> leftview(Node* root){
    vector<int> ans;
    queue<Node*> q;
    if (root==NULL) return ans ;
    q.push(root);

    while(!q.empty()){
       int n=q.size();
       ans.push_back(q.front()->data);
       while(n--){
        Node* temp=q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
       }

    }
    return ans;

}

vector<int> rightview(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        ans.push_back(q.front()->data);
        while(n--){
           Node* temp=q.front();
           q.pop();
           if(temp->right){
            q.push(temp->right);
           }
           if(temp->left){
            q.push(temp->left);
           }
        }
        

    }
    return ans;
}


int main(){
    Node* root=BuildTreee();

    vector<int> ans;
    ans=rightview(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}
