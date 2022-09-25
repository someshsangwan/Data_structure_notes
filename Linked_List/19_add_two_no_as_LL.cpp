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

/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers 
and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

*/
// question me already reverse dia h order nhi hota to hm phle dono LL ka reverse krna pdta bhai;
void insertattail(Node* &head,Node* &tail,int digit){\
   Node* temp=new Node(digit);
    if(head==NULL){
         head=temp;
         tail=temp;   
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
Node* add(Node* &A,Node* &B ){
    Node* head=NULL;
    Node* tail=NULL;
    int carry=0;
    while(A!=NULL || B!=NULL || carry!=0){
        int data1=0;
        if(A!=NULL){
            data1=A->data;
        }
        int data2=0;
        if(B!=NULL){
            data2=B->data;
        }
        int sum=data1+data2+carry;
        int digit=sum%10;
        carry=sum/10;
        insertattail(head,tail,digit);
        if(A!=NULL){
            A=A->next;
        }
        if(B!=NULL){
            B=B->next;
        }
    }
    return head;
}
Node* addTwoNumbers(Node* A, Node* B) {
    //A=reverse_l(A);
    //B=reverse_l(B);
    Node* ans=add(A,B);
    //ans=reverse_l(ans);
    return ans;
    
    
}