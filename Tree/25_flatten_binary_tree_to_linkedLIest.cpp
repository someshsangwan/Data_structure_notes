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
/*
Given a binary tree, flatten it to a linked list in-place.

Example :

Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.*/
Node* flatten(Node *root)
{
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node* prev=curr->left;
            while(prev->right!=NULL){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }   
            
        curr=curr->right;
    }
    return root;
}