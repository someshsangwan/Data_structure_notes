#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// we are given an integer array cost where cost[i] is the cost of ith stair on a stair,once  you pay the cost you can climb 1 or 2 ;
int solve(vector<int>&dp,int n , vector<int>cost){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=cost[n]+min(solve(dp,n-1,cost),solve(dp,n-2,cost));
}