#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
problem statement -partition a set into two subset such that the difference of subset sum is minimum\
example {1,2,3,4}  output will be Zero(0);
subset -{1,2}.{3,4} =>4
      -{1,3},{2,4}  =>2
      -{1,4},{2,3}  =>0   yesssssssssssss;

*/
int solve(vector<int> &A) {
    int n=A.size();
    int target=0;
    for(int i=0;i<n;i++){
        target+=A[i];
    }
    int dp[n][target+1];
    for(int i=0;i<n;i++){
        dp[i][0]=1;
        
    }
    for(int j=1;j<=target;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if(A[i]<=j){
                take=dp[i-1][j-A[i]];
            }
            dp[i][j]=take|nottake;
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<=target;i++){
        if(dp[n-1][i]==1){
            int s1=i;
            int s2=target-i;
            mini=min(mini,abs(s2-s1));
        }
    }
    return mini;
    
}