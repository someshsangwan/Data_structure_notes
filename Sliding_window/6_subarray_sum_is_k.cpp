#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//variale window size problem 

// there are 2 question in question 
// 1st one count total subarray whose sum is equal to k;
// 2nd one find longest size subarray whose sum is k;

//pronlem logest subarray sum is equaal to K;
// Input :
// A[] = {10, 5, 2, 7, 1, 9}
// K = 15
// Output : 4
// Explanation:
// The sub-array is {5, 2, 7, 1}.
// here its not easy to move window
// sath me ye bhi btana h ki kine subaaray h jinka sum k h  or max wala kitne size ka h ; 
// 2 question bn gye sath me;

// BHai nhi ho rha bc sliding se ye negative no. ke liye bakchodi ho rhi h ;

    int subarraySum(vector<int>& nums, int k) {
       int n=nums.size();
        int sum=0;
        int ct=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum==k){
                ct++;
            }
            int y=sum-k;
            if(mp.find(y)!=mp.end()){
                ct=ct+mp[y];
            }
            mp[sum]++;
        }
        return ct;
    }
