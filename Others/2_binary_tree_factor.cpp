#include<bits/stdc++.h>
using namespace std;
#include<iostream>
/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. 
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
*/
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        long long mod=1e9+7;
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=1;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            long long  ways=0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                   long long x=arr[i]/arr[j];
                    if(mp.find(x)!=mp.end()){
                        long long  y=mp[arr[j]]*mp[x];
                        ways+=y;    
                    }
                }
            }
            mp[arr[i]]=mp[arr[i]]+ways;
        }
        long long res=0;
        for(auto i:mp){
            res=(res%mod+(i.second)%mod)%mod;
        }
        return res;
    }