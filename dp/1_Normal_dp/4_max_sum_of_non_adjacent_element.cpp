#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//given an array find max sum of non adjacent element ;
int solve(int ind ,vector<int>&num,vector<int>&dp){//ind=n-1
    if(ind==0){
        return num[0];
    }
    if(ind<0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int include=num[ind]+solve(ind-2,num,dp);
    int exclude=0+solve(ind-1,num,dp);
    return dp[ind]=max(include,exclude);
}
//tabulation to  tum kr hi loge bhai just 2 variable bna lena ;