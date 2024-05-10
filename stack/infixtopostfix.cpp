#include<iostream>
#include<stack>
using namespace std;

int prec(char op){
    if(op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return -1;
}

string infixtopostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;

}
int main(){
            
    string s;
    cin>>s;
    cout<<infixtopostfix(s)<<endl;
    return 0;
}
