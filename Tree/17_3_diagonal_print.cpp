// see jpeg file for better understanding --
#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Node{
    public:
    Node* left;
    Node* right;
    int key;
    Node(int val){
        this->key=val;
        this->left=NULL;
        this->right=NULL;

    }
};

vector<int> solve(Node* A) {
    vector<int>ans;
    queue<Node*>q;
    if(A==NULL){
        return ans;
    }
    q.push(A);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
 
        while(temp!=NULL){
        if(temp->left){
            q.push(temp->left);
            
        }
            ans.push_back(temp->key);
            temp=temp->right;
        }
    }
    return ans;
}