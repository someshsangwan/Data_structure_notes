/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/ 


/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
// brute force- generate all the subsequence and put all of them in set then we will get only unique sets;
using namespace std;
#include<bits/stdc++.h>
#include<iostream>
 
    void solve(int idx,vector<int>nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);// in every call we are makeing sets na that is why we are adding it in our ans vector;
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(0,nums,temp,ans);
        return ans;
        
    }