// its code is same as top_view , we will change  just a condditon;
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
// here we will use two data structure one queue for traversal and second one is map to check some imp things
vector<int>solution(Node* root){
    vector<int>ans;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    while(!q.empty()){
        Node* temp=q.front().first;
        q.pop();
        int hd=q.front().second;
        //if(mp.find(hd)==mp.end()){ we dont need to write its conditionn because we want to print bottom view na , so hd will be updated 
            mp[hd]=temp->key;         // till last position ;
        //}
        if(temp->left){
            q.push({temp->left,hd-1});
        }
        if(temp->right){
            q.push({temp->right,hd+1});
        }

    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;

}