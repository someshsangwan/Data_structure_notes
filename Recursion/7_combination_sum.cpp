#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the 
combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at 
least one of the chosen numbers is different.*/


/*Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.*/


//here we can use a number from array  multiple time  to make sum equal to target;

//yha pe hm ek element ko multiple time dalke check krenge bs thoda sa chenge hoga 
    void solve(vector<int>& arr,int target,int idx,int sum,vector<int>&temp,vector<vector<int>>&ans,int n){
        if(idx>=n){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        if(arr[idx]+sum<=target){
        temp.push_back(arr[idx]);
        sum=sum+arr[idx];
        solve(arr,target,idx,sum,temp,ans,n); //idx nhi increase krenge bcz ek element ko multiple times dalke dekhnge 
        temp.pop_back();
        sum=sum-arr[idx];
        }
        solve(arr,target,idx+1,sum,temp,ans,n);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     { 
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        solve(candidates,target,0,0,temp,ans,n);
        return ans;
        
    }