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


void insertIntoBST(Node* &root, int data){
    if(root==NULL){
        root=new Node(data);
        return;
    }
    if(root->data >data){
        insertIntoBST(root->left,data);
    }
    else{
        insertIntoBST(root->right,data);
    }
}

vector<int> LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    Node* temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
    
}


void takeinput(Node* &root){
    int data; cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}



int main(){
    
    Node* root=NULL;

    takeinput(root);

    vector<int> result = LevelOrderTraversal(root);
    
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
