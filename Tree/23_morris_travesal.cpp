/* why we need morrris travesal while we have inorder,preorder,postorder and level order traversal */
// these all takes o(n) space and o(n) time compexity;
// but morris travesal takes only o(1) space and  o(n) time  complexity ;
// so this is more efficient than other travesal;
// there is one important question what we will solve by using morris traveral - Flatten a binary tree into Linked list;

//lets start morris traversal
// here we will print inorder using morris traversal ok got it na ? 
// aaj barish ho rhi h yha punjab me mst neend aa rhi h padhne ka mn nhi kr rha h mst soya hu aaj ---18 june 2022
// padh to rhe h kabhi kabhi lgta h ki m success huh paunga ya nhi is field me bcz i started coding in Jan 2022;
// campus me gine chune log hi h bs baki achi achi company me intern kr rhe h koi benguluru gya to koi gurgaon;
// but coding krte rhenge one day i will be a good software engineer---------------------------------------------------------------------
// lets start bahut bakch**i kr li mera padhne ka mn nhi h tb kr rha hu ye sb tum to padh lena ye sb;

// in other traversal generally we use queue and recursion so its easy to come back root but in this traversal to come back we will 
// make temporary links .>>>>>>.....>>>>>>>......>>>>>.....>>>>>.

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

void morris_traversal(Node* root){
    if(root==NULL){
        return;
    }
    Node* current=root;
    Node* predecessor; // predecessor - one left than right untill right !=NULL;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->key<<endl;
            current=current->right;
        }
        else{
            predecessor=current->left;         // go one left than right untill right !=NULL;
            while(predecessor->right!=NULL && predecessor !=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){ // in this section we are making temporary links
                predecessor->right=current;
                current=current->left;
            }
            else{                         // in this section we are removing those temporary Links     =====
                predecessor->right=NULL;
                cout<<current->key<<endl;
                current=current->right;
            }
        }
    }
}
