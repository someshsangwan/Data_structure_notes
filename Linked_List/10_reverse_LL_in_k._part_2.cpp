using namespace std;
#include<bits/stdc++.h>
#include<iostream>
// isme jaise 1 2 3 4 5 to k=3 h to resulntant 3 2 1 4 5 rhna chahiye na ki 5 4;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Solution {
public:
    ListNode* rev(ListNode* head,int k)
    {
        ListNode* prev=NULL;
   
        while(head!=NULL && k>0)
        {
           
            ListNode* nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;
            k--;
        }
       
        return prev;
    }
    ListNode* help(ListNode* head,int k)
    {
        if(head==NULL )
            return NULL;
        ListNode* org_head=head;
        int temp=k;
        while(k>0 && org_head!=NULL)
        {
            org_head=org_head->next;
            k--;
        }
        if(k>0)
            return head;
        
        ListNode* h1=rev(head,temp);
        ListNode* h2=help(org_head,temp);
        head->next=h2;
        return h1;
        
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return help(head,k);
        
    }
};