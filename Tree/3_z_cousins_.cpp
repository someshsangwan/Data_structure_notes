#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
};
vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    queue<TreeNode*>q;
    q.push(A);
    bool found = false;
    while(!q.empty() && !found){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode *t = q.front();
            q.pop();
            if(t->left && t->left->val == B){ //here we will not push its left because they will be sibling na not cousins.
                found = true;
            }
            else if(t->right && t->right->val == B){//same here
                found = true;
            }
            else{  //here we will push                for better understanding pls dry run code ny taking any example ; ok goodnight its 2:00 am in our county INDIA
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        if(found){
            while(!q.empty()){
                TreeNode *t = q.front();
                q.pop();
                ans.push_back(t->val);
            }
        }
    }
    return ans;

}