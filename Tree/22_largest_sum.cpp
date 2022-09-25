#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//iven the root of a binary tree, return the maximum path sum of any non-empty path.
// it also contains negative value node ;
//it can be from any node to any node;
    int maxsum(TreeNode* root,int &mx){
        if(root==NULL){
            return 0;
        }
        int leftsum=maxsum(root->left,mx);
        int rightsum=maxsum(root->right,mx);
        if(leftsum<0){
            leftsum=0;
        }
        if(rightsum<0){
            rightsum=0;
        }
        mx=max(mx,root->val+leftsum+rightsum);
        return root->val+max(leftsum,rightsum);        
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        maxsum(root,mx);
        return mx;
    }