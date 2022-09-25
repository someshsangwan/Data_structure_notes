#include<bits/stdc++.h>
using namespace std;
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
Node* sort_LL(Node* head){
    Node* curr=head;
    Node* ptr;
    while(curr->next!=NULL){
        ptr=curr->next;
        while(ptr!=NULL){
            if(ptr->data<curr->data){
                int temp=curr->data;
                curr->data=ptr->data;
                ptr->data=temp;
            }
            ptr=ptr->next;
        }
        curr=curr->next;
    }
    return head;

}
void print_normal(Node *head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
void insert_end(Node*head,int x){
    //cout<<"heloooooooo"<<endl;
    Node* temp=new Node(x); //allocate the memory for new node
    if(head==NULL){
        head=temp;
        return;
    }
    Node* curr=head; //create a temporary node for travesal;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}

int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    insert_end(head,9);
    insert_end(head,3);
    insert_end(head,7);
    insert_end(head,15);
    insert_end(head,9);
    print_normal(head);
    Node* main=sort_LL(head);
    print_normal(main);


}