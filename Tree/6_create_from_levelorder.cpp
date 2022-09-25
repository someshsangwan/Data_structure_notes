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

void buildfromlevel(Node* root){
    cout<<"enter data for root node"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"enter the data left of "<<temp->key<<endl;
        int left;
        cin>>left;
        if(left!=-1){
        temp->left=new Node(left);
        q.push(temp->left);
        }

        cout<<"enter the data right of "<<temp->key<<endl;
        int right;
        cin>>right;
        if(right!=-1){
            temp->right=new Node(right);
            q.push(temp->right);
        }


    }
}