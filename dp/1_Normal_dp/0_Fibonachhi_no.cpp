#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fibnachhi(int n,vector<int>dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fibnachhi(n-1,dp)+fibnachhi(n-2,dp);
}

//tabulation 
int fibnachhi_1(int n){
       vector<int>dp(n+1);
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];

       }
       return dp[n];
}

// we can reduce space complexity here by just using 2 variable ;
int fibnachhi_2(int n){
    int prev1=0;
    int prev2=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev1=prev2;
        prev2=curr;
    }
    return prev2;
}
int main(){
    int n=8;
    vector<int>dp(n+1,-1);
    cout<<fibnachhi_2(n);
}