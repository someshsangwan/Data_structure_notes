#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// in kanpsack problem you have given 2 array on weight array and another is value coressponding wiight array;
// also given a bag of fix weight -- max loot you can make;
//                                              ++++++++++++++++++ 
// ezz problem just pick or not pick=== ------try all the combination return max loottt;

int solve(int ind,int w,vector<int>&weight,vector<int>&value){
    if(ind==0){
        if(weight[0]<=w){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int not_take=0+solve(ind-1,w,weight,value);
    int take=INT_MIN;
    if(weight[ind]<=w){
        take=value[ind]+solve(ind-1,w-weight[ind],weight,value);
    }
    return max(not_take,take);
}
//memoization to kr loge bhai tum ezz-pzz rhega 
//tabulation;
// int dp[N][W+1];