#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
all opration in o(1) time complexity
*/
class Stack{
    public:
    int *arr;
    int size;
    int top=-1;
    Stack(int size){
        this->size=size;
        arr=new int[size];
    }
    void push(int x){
        if(size-top>1){
            top++;
            arr[top]=x;
        }
        else{
            cout<<"stackoverflow"<<endl;
        }

    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peak(){
        if(top>=0){
            return arr[top];
        }
        else{
            return -1; 
        }

    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }

    }

};
int main(){
    Stack st(5);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<st.peak()<<endl;
    cout<<st.isempty()<<endl;

}