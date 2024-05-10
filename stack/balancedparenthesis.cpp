#include<iostream>
#include<stack>
using namespace std;

bool checkparenthesis(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            //if character is a closing bracket
            if(st.empty()) return false;
            if(s[i]=='(' && st.top() !=')' || s[i]=='{' && st.top() !='}' || s[i]=='[' && st.top()!=']'){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main(){
    string s;
    cin>>s;

    cout<<"The parenthesis is : "<<checkparenthesis(s)<<endl;
    return 0;
}