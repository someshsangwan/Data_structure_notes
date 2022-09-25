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
Node* solve(vector<int>&inorder,vector<int>&postorder,int &index,int inorderstart, int inorderend,int n,map<int,int>&nodetoindex){
     if(index>=n || inorderstart>inorderend){
         return NULL;
     }
     int element=postorder[index];
     index--;
     Node* root=new Node(element);
     int position=nodetoindex[element];
     root->right=solve(inorder,postorder,index,position+1,inorderend,n,nodetoindex);
     root->left=solve(inorder,postorder,index,inorderstart,position-1,n,nodetoindex);
      
     return root;
}
Node* constructBST(vector<int> &A) {
    int n=A.size();
    vector<int>inorder=A;
    sort(inorder.begin(),inorder.end());
    map<int,int>nodetoindex;
    for(int i=0;i<n;i++){
        nodetoindex[inorder[i]]=i;
    }
    int index=n-1;
    
    return  solve(inorder,A,index,0,n-1,n,nodetoindex);
     
}