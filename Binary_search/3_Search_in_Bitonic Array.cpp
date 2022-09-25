#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
//A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
// first find that point where its changing i mean that bitonic point and  than apply binary search 0 to bitonic point and another for descending array from bitonic+1 
// to n-1;
int binary_asscending(vector<int>&arr,int n,int start,int end,int x){
  while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    }
    return -1;
    
}
int binary_descending(vector<int>&arr,int n,int start,int end,int x){
  while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        start=mid+1; 
    }
    else{
         
        end=mid-1;
    }
    }
    return -1;
    
}
int check(vector<int>&arr,int n,int start , int end ){
    
    int mid=start+(end-start)/2;
    int point =0;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
        return mid;
    }
    else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
        point=check(arr,n,mid,end);
    }
    else{
        point= check(arr,n,start,mid);
    }
    return point;
    
}
int solve(vector<int> &A, int B) {
    int bitonic=check(A,A.size(),0,A.size()-1);
    if(A[bitonic]==B) return bitonic;
    int as=binary_asscending(A,A.size(),0,bitonic,B);
    int des=binary_descending(A,A.size(),bitonic+1,A.size()-1,B);
    if(as!=-1){
        return as;
    }
    else{
        if(des!=-1){
            return des;
        }
        else{
            return -1;
        }
    }
}