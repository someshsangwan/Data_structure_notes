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
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
     
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
     
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
     
}
 