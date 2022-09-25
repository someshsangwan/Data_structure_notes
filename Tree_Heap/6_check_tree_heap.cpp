// check binary tree is it heap or not;
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// ezz h heap check krna h to do propert krna pdega first we will check it is complete binary tree and second we need to check it is max heap or not;
 
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
bool checkmaxheap(Node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return (root->key > root->left->key);
    }
    if(root->left==NULL && root->right!=NULL){
        return false;
    }
    bool left=checkmaxheap(root->left);
    bool right=checkmaxheap(root->right);
    if(left && right && root->key > root->left->key && root->key > root->right->key){
        return true;
    }
    else{
        return false;
    }
}
bool iscompletebst(Node* root){
    //have done in last question
}
bool checkheap(Node* root){
    if(iscompletebst(root) && checkmaxheap(root)){
        return true;

    }
    else{
        return false;
    }
}