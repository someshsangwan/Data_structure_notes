#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
// which makes it impossible to reach the last index.

bool canJump1(vector<int>& nums) {
    int n=nums.size();
    int check=0;
    for(int i=n-2;i>=0;i--){
        check++;
        if(nums[i]>=check){
            check=0;
            }
        }
    return check==0;
}
// we can also solve this probelm ussing recursive dp;
bool check(int i,int n,vector<int>&nums,vector<int>&dp){
    if(i>=n-1){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int size=nums[i];
    bool ans=false;
    for(int j=1;j<size;j++){
        ans=ans||check(i+j,n,nums,dp);
    }
    return dp[i]=ans;
}
bool canJump2(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(1e5+10,-1);//max size of an eleemt bcz we are run a looop form j=1 to its size();
    return check(0,n,nums,dp);
}
