#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<queue>
//largest - we will make a min heap
// smallest - we will make a max heap;
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }