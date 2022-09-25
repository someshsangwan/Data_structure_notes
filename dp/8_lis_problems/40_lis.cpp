#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//problem :- given an array , find the longest increasing subsequence
//example:- {10,9,2,5,3,7,101,18};
//there are som many possibilities but we are taking some few 
//{2,3,7,101}=4
//{10,101}=2;
//{3,7,101}=3;
 int solve(int ind,int prev,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];  
        }
        int len=0+solve(ind+1,prev,n,nums,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1+solve(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }