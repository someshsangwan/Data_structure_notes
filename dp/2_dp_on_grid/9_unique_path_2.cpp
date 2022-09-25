#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//probelm now we have also given m*n matrices if there are 0 in matrix , we can go through this , if there are -1 we cant go through this 
int solve(int i,int j,vector<vector<int>>arr){//i=m-1,j=n-1;
    if(i>=0 && j>=0 && arr[i][j]==-1){
        return 0;
    }
    if(i<=0 || j<=0){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    int up=solve(i-1,j,arr);
    int left=solve(i,j-1,arr);
    return up+left;
}
//tabulation kr lo frnds ezz hoga chlo kr lete h iska ;
int solve_1(vector<vector<int>>arr){
    int m=arr.size();
    int n=arr[0].size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            if(arr[i][j]==-1){
                dp[i][j]=0;
            }
            else{
                int up=0;
                int left=0;
                if(i>=1){
                    up=dp[i-1][j];
                }
                if(j>=1){
                    left=dp[i][j-1];
                }
            }
        }
    }
    return dp[m-1][n-1];
}