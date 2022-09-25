#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
     
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class Stack{
    public:
    Node* head;
    int sz;
    Stack(){
        head=NULL;
        sz=0;
    }
    void push(int x){
        Node* temp= new Node(x);
        if(head==NULL){
            head=temp;
        }
        temp->next=head;
        head=temp;
        sz++;
    }
    void pop(){
        if(head==NULL){
            cout<<"yes its empty"<<endl;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        sz--;
    }
    int peak(){
        if(head==NULL){
            return -1;
        }
        else{
            return head->data;
        }
    }
    bool isempty(){
        if(sz==0){
            return true;
        }
        return false;
    }

};
int main(){
    Stack st;
    st.push(3);
    st.push(6);
    st.push(9);
    st.push(12);
    st.pop();
    cout<<st.peak() <<endl;
    cout<<st.isempty()<<endl;
}
