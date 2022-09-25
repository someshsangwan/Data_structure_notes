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

void inorder(Node* root,int &sum){
    if(root==NULL){
        return ;
    }
    inorder(root->left,sum);
    if(root->left==NULL && root->right==NULL){
        sum++;
    }
    inorder(root->right,sum);
}
int no_of_leaf(Node* root){
    int sum=0;
    inorder(root,sum);
    return sum;
    

}