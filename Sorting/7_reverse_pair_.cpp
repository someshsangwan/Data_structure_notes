#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* problem statement 
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
*/

  long long merge_sort(vector<int>&arr,int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int arr1[len1];
    int arr2[len2];
    long long count=0;
    int j=mid+1;
    for(int i=start;i<=mid;i++){
        while(j<=end && arr[i]>2LL*arr[j]){
            j++;
        }
        count=count+(j-(mid+1));
    }
    int mainindex=start;
    
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainindex++];
    }
    mainindex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainindex++];
    }
    int k=start;
    int i=0;
    j=0;
    while(i<len1 && j<len2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr[k]=arr2[j];  
            j++;
            k++;
        }
    }
    while(i<len1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<len2){
        arr[k]=arr2[j];
        j++;
        k++;   
    }
    return count;
}
    
    int merge(vector<int>&nums,int s,int e){
        int res=0;
        if(s<e){
            int mid=s+(e-s)/2;
            res+=merge(nums,s,mid);
            res+=merge(nums,mid+1,e);
            res+=merge_sort(nums,s,e);
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return merge(nums,0,n-1);
        
    }