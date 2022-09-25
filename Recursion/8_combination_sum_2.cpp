#include<iostream>
#include<bits/stdc++.h>

/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.



*/

// is bar hm unique element use kenge but out solution must not containt duplicate combinations;
using namespace std;
#include<iostream>
void solve(vector<int>& arr,int target,int idx,vector<int>&temp,vector<vector<int>>&ans,int n){
            if(target==0){
                ans.push_back(temp);
               return;
            }
        for(int i=idx;i<n;i++) {
        if(i>idx &&arr[i]==arr[i-1]) continue; //check duplicate contains 
        if(arr[i]>target) break;
        temp.push_back(arr[i]);
        solve(arr,target-arr[i],i+1,temp,ans,n);
        temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)     { 
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int n=candidates.size();
        solve(candidates,target,0,temp,ans,n);
        return ans;    
    }