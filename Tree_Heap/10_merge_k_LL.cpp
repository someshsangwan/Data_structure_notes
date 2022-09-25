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
class comp{
    public:
    bool operator()(Node*a,Node*b){
    return a->data > b->data;
}
};
Node* merge(vector<Node*> &A){
    priority_queue<Node*,vector<Node*>,comp>minheap;
    for(int i=0;i<A.size();i++){
        minheap.push(A[i]);
    }
     
    Node* head=new Node(0);
    Node* temp=head;
    
    while(minheap.size()>0){
        Node* x=minheap.top();
        //cout<<temp->val<<" ";
        minheap.pop();
        temp->next=x;
        temp=temp->next;
        if(x->next!=NULL){
            minheap.push(x->next);
        }   
        
    }
    return head->next;
     
    
}
Node* mergeKLists(vector<Node*> &A) {  // hr index me hr linked list ka head node dia h
    if(A.size()==1){
        return A[0];
    }
    return merge(A);
     
 
}
