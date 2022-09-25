#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};



Node* merge_2_sorted(Node* head_1,Node* head_2){
    Node* res=NULL;
    if(head_1==NULL){
        return head_2;
    }
    if(head_2==NULL){
        return head_1;
    }
    if(head_1->data <= head_2->data){
        res=head_1;
        res->next=merge_2_sorted(head_1->next,head_2);
    }
    else{
        res=head_2;
        res->next=merge_2_sorted(head_1,head_2->next);
    }
    return res;

}