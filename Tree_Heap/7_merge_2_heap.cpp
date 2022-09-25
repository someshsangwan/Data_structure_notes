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
//merge both vector and apply heapify;
    void heapify(vector<int>&ans,int n, int i){
        int longest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && ans[left]>ans[longest]){
            longest=left;
        }
        if(right<n && ans[right]>ans[longest]){
            longest=right;
        }
        if(i!=longest){
            swap(ans[i],ans[longest]);
            heapify(ans,n,longest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b ) {
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int c=ans.size();
        for(int i=c/2-1;i>=0;i--){
            heapify(ans,c,i);
        }
        return ans;
    }