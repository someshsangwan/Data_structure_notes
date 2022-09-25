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
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
}
/*
important formulas-
no. of max element at a level - 2^h , here h is the level of tree;
no. of element before ant level- 2^h-1 here h -----------------;
height of tree=logbase2(n); n is the no. of element in a tree;

*/