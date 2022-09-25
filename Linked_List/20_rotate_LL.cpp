#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// rotate a Linked List By K
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
Node *rotate(Node *head, int k) {
     // Write your code here.
    int len=1;
    Node *temp=head;
    while(temp->next!=NULL){
        len++;
        temp=temp->next;
    }
    temp->next=head;
    k=k%len;
    int ct=len-k;
    while(ct--){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;
    return head;
    
 
    
}