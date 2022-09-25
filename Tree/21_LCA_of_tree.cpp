
//LCA means lowest common ancestor->
//  we have given to node value and we have to return that bode who is lowest common ancestor of both no.
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
Node* lca(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->key==n1 ||root->key==n2){
        return root;
    }
    Node* leftans=lca(root->left,n1,n2);
    Node* rightans=lca(root->right,n1,n2);
    if(leftans!=NULL && rightans!=NULL){
        return root;
    }
    if(leftans==NULL && rightans!=NULL){
        return rightans;
    }
    if(leftans!=NULL && rightans==NULL){
        return leftans;
    }
    else{
        return NULL;
    }
}
/* there can be possible that the node value n1 and n2 is not present in our tree in that case we will return -1 
so we need to check that the no. present or not in tree;*/
bool find(Node *root, int v) {
    if (root == NULL) return false;
    if (root -> key == v) return true;
    return (find(root -> left, v) || find(root -> right, v));
}

