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

void inorder(Node* root,int &ct){
    if(root==NULL){
        return ;
    }
    inorder(root->left,ct);
    if(root->left==NULL && root->right==NULL){
        ct++;
    }
    inorder(root->right,ct);
}
int no_of_leaf(Node* root){
    int ct=0;
    inorder(root,ct);
    return ct;
    

}