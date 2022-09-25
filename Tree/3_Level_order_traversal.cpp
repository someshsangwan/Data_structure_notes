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
void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){   //if we have to store order in a vector so we dont need write NULL and vice versa
        Node* temp=q.front();           //Node* temp=q.front();         
        q.pop();                        //q.pop();
        if(temp==NULL){                 //v.push_push_back()
            cout<<endl;                 //if(temp->left){
            if(!q.empty()){             // q.push(temp->left);}
                q.push(NULL);           //if(temp->right){
            }                           // q.push(temp->right)}
        }
        else{
            cout<<temp->key<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
int main(){

}