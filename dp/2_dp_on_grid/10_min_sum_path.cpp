#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//problem statement - you have a 2d matrix iy is filled some values.  from (0,0) to (m-1,n-1)  find a path which minimize sum of cost of all no. along the path 
// and return value ;
// yours moves should be down & right;
// example  
/*  5 9 6
   11 5 2      output will be 5+9+5+2=21 which is minimum among all path ;

*/
int solve(int i,int j,vector<vector<int>>arr){
    if(i==0 && j==0){
        return arr[0][0];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }
    int up=arr[i][j]+solve(i-1,j,arr);
    int left=arr[i][j]+solve(i,j-1,arr);
    return min(up,left);
}

//tabulation
int solve_1(vector<vector<int>>arr){
 
    int m=arr.size();
    int n=arr[0].size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=arr[0][0];
            }
            int left=INT_MAX;
            int up=INT_MAX;
            if(i>0){
                up=dp[i-1][j];
            }
            if(j>0){
                left=dp[i][j-1];
            }
            dp[i][j]=min(up,left);


        }
    }
    return dp[m-1][n-1];
}