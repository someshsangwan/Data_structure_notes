#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//problem given a m*n matrix just dimensions are given , find the unique path from top  leftmost to bottom rightmost element;
// you can onlu move right and down;
int solve(int i,int j){ // i =m-1 , j=n-1;
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    // count puche to add krna hota h recursion calls ko;
    int up=solve(i-1,j);
    int left=solve(i,j-1);
    return up+left;
}
//tabulation;
int solve2(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>1){
                    up=dp[i-1][j];
                }
                if(j>1){
                    left=dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}