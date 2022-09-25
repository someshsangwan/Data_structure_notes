using namespace std;
#include<bits/stdc++.h>
#include<iostream>
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};


int main(){
    Node* head=new Node(3);
    Node* second=new Node(7);
    Node* third=new Node(7);
    Node* forth=new Node(3);
    head->next=second;
    second->next=third;
    third->next=forth;
     
}