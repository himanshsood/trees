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

vector<int> LevelOrder(Node* root){
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
        return ans;
    }

}


int main(){

    

    
    
    return 0;
}
