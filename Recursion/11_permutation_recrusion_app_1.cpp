#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// question is that - print all the possible  permutation (not subsequence ) of an array -
/*
Input: nums = [1,2,3]   total no. of permutations - factorial(n) here n is 3 then no. of permutaions- fact(3)=3*2=6;
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

//Approach-1 that will be using extra space complexity instead of our other approach-2;
// we will make an array of marking that we mark  picking  elemest at which position we pick first or second;
void solve(vector<int>nums,vector<int>&temp,vector<int>&vis,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(nums,temp,vis,ans);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(nums.size(),0);
        solve(nums,temp,vis,ans);
        
        return ans;
        
    }


//Approach_2 here we will not use any extra array/map

void solve1(int index,vector<int>nums,vector<vector<int>>&ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve1(index+1,nums,ans);
        swap(nums[index],nums[i]);  // ate time reswap;


    }
}
vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>>ans;
        solve1(0,nums,ans); 
        return ans;
        
    }


