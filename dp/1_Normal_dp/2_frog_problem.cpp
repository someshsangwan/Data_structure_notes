#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// we have given an array that contains energy . A frog can jump by 1 or by 2 . required min energy to reach final positonn
int solve(int n,vector<int>height,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left=INT_MAX;
    int right=INT_MAX;
    left=abs(height[n]-height[n-1])+solve(n-1,height,dp);
    if(n>1){
        right=abs(height[n]-height[n-2])+solve(n-2,height,dp);
    }
    return dp[n]=min(left,right);
}