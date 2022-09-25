#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//problem name maximum subarray-
// we have given an array and we have to  find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

*/
int max_subarray(vector<int>num){
    int n=num.size();
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+num[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;

}