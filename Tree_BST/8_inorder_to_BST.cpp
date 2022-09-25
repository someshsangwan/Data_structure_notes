// we have given an array / inorder traversal of any tree make a bst from them //
// if we have given any tree and we want to make a bst from that tree first we find any ordered traversal and 
// store them into array and store into a vector then find the following ------------implemetation
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
// first we pass s==0 && e=n-1 where n is size of our inorder vector.
Node* inordertobst(int s,int e,vector<int>&in){
    if(s>e){
        return NULL;
    }
    int mid=(s+(e-s))/2;
    Node* root =new Node(in[mid]); 
    root->left=inordertobst(s,mid-1,in);
    root->right=inordertobst(mid+1,e,in);
    return root;
}