
/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.


*/
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
// map se to kr hi skte h bhaio ;
Node* intersection(Node*headA,Node* headB){
    Node* curr1=headA;
    Node* curr2=headB;
    while(curr1!=curr2){
        if(curr1==NULL){
            curr1=headB;
        }
        else{
            curr1=curr1->next;
        }
        if(curr1==NULL){
            curr2=headA;
        }
        else{
            curr2=curr2->next;
        }
    }
    return curr1;

}