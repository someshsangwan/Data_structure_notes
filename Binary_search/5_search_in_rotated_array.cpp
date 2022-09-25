#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//bitonic wale se different h ye bcz bitonic me to increse after decrese  1 2 3 4 5 6 7 5 4 3 2 1 esa tha yha esa nhi h yha sirf rotate kia h array ko
// 2 4 6 8 9 h rotate kr dia by 6 8 9 2 4  yha bhi increase hi ho rha h ek point pe decrease hua h;
// find that point where its down ;
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
int check(vector<int>&arr,int n,int start , int end ){
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
     
    
    
}
    int search(vector<int>& A, int B) {
    int n=A.size();
    int pivot=check(A,A.size(),0,A.size()-1);
    if(A[pivot]==B) return pivot;
    if(B>=A[pivot] && B<=A[n-1]){
    return   binary_asscending(A,A.size(),pivot,A.size()-1,B);                             
    }
    else{
        return binary_asscending(A,A.size(),0,pivot-1,B);
    }
        
    }