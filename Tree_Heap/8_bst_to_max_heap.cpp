#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
/* question is special 
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left 
subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all
 the nodes in the so converted Max Heap.
 */
// Node>left , Node>right , left<right --- left<right<Node this is postorder travesal so we have to fill with postorder travesal;
// min heap - Node<left , Node<right, left<right --- Node<left<right fill with preorder travesal;
   void inorder(Node* root,vector<int>&ans){
       if(root==NULL){
           return;
       }
       inorder(root->left,ans);
       ans.push_back(root->key);
       inorder(root->right,ans);
       
   }
   void post(Node* &root,vector<int>&in,int &index){
       if(root==NULL){
           return;
       }
       post(root->left,in,index);
       post(root->right,in,index);
       root->key=in[index++];
       
   }
    void convertToMaxHeapUtil(Node* root)
    {
         vector<int>in;
         inorder(root,in);
         int index=0;
         post(root,in,index);
         
    }    