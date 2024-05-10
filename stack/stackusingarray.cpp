#include<iostream>
using namespace std;

class Stack{
    int* arr;
    int top;
    int capacity;
    public:
        Stack(int c){
            arr=new int[c];
            top=-1;
            capacity=c;
        }

        void push(int x){
            if(top==capacity-1){
                cout<<"stack overflow"<<endl;
            }
            top++;
            arr[top]=x;
        }

        void pop(){
            if(top==-1){
                cout<<"stack underflow"<<endl;
                return;
            }
            top--;
        }

        int peak(){
            if(top==-1){
                return -1;
            }
            return arr[top];

        }

        bool isEmpty(){
            return top==-1;
            // if empty then true otherwise false
        }

        int size(){
            return top+1;
        }

};

int main(){

    Stack s(5);
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    s.push(6);

    while(!s.isEmpty()){

        cout<<s.peak()<<endl;
        s.pop();
    }


            
            
    return 0;
}
