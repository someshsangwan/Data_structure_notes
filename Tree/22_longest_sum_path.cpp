//find the sum of longest path from root to leaf.
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
void solve(Node* root ,int sum,int&maxsum,int len, int&maxlen){
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->key;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}
int maxsumoflength(Node* root){
    int sum=0;
    int maxlen=0;
    int len=0;
    int maxsum=INT_MIN;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}