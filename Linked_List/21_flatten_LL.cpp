#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 // problem statement --
using namespace std;
#include<bits/stdc++.h>
#include<iostream>
class Node{
    public:
    int data;
    Node* next;
    Node* bottom;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->bottom=NULL;
    }
};
Node* merge(Node* a, Node* b){
    Node* res=new Node(0);
    Node* temp=res;
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
             
        }
        else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
             
        }
    }
        if(a!=NULL){
            temp->bottom=a;
        }
        if(b!=NULL){
            temp->bottom=b;
        }
        return res->bottom;
    
}
Node *flatten(Node *root)
{
    Node* l1=root;
    Node* l2=root->next;  //phle 2 ko merge phir unke resultant ko 3rd ke sath megre ----
    while(l2!=NULL){
        l1=merge(l1,l2);
        l2=l2->next;
    }
   return l1;
}

// approach 2- using priority queue; same as merge k sorted array
//make a priority queue pair of Node and value;
//priority_queue<pair<Node*,int>>q;
//put first value of every Node;

Node *flattenLinkedList(Node *head) {
    Node *pointer = head;
    Node *result = NULL;

    // Heap to store all the node value pair.
    priority_queue<pair<int,Node*>> pq;  //sorry min heap use krenge 
    // max heap me jo pair me phle hota h uske hisab se sort hota h 
    //to phle value rakhneg;

    // Push the head nodes.
    while (pointer != NULL) {
        pq.push({ pointer->data, pointer});
        pointer = pointer->next;
    }

    // Add child nodes while popping out the minimum.
    while (!pq.empty()) {
        Node *temp = pq.top().second;
        pq.pop();

        // If the child of temp is not null add it to the heap.
        if (temp->bottom != NULL) {
            pq.push({temp->bottom->data,temp->bottom});
        }

        if (result == NULL) {
            result = temp;
            pointer = temp;
            pointer->next = NULL;
        } else {
            pointer->bottom = temp;
            pointer = temp;
            pointer->next = NULL;
        }
    }

    return result;
}
