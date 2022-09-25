#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// isme frog can jump k time like i+1,i+2,i+3,i+4........k times;
int solve(int n,int k,vector<int>&dp,vector<int>height){
    if(n==0){
        return 0;
    }
    int minstep=INT_MAX;
    for(int j=1;j<=k;j++){
        if(n-j>=0){
            int jump=solve(n-j,k,dp,height)+abs(height[n]-height[n-j]);
            minstep=min(minstep,jump);
        }
    }
    return minstep;

}