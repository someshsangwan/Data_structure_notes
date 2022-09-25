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
//problem - reverse only even position element in LL
// input = 1->2->3->4->5->6
// output= 1->6->3->4->5->2

//aproach 1- store the even position value and replace them reverse value of stored value;
//we use stack- this approach will take o(n) space complexity;
//code-
Node* solve(Node* A) {
    Node* curr=A;
    int i=1;
    stack<int>s;
    while(curr!=NULL){
        if(i%2==0){
            s.push(curr->data);
        }
        i++;
        curr=curr->next;
    }
    int j=1;
    Node* temp=A;
    while(temp!=NULL){
        if(j%2==0){
            int x=s.top();
            temp->data=x;
            s.pop();
        }
        j++;
        temp=temp->next;
    }
    return A;
}
/* approach 2 make a list of even position and reverse and merge them later*/
 