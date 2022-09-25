#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//inversion meaning - find a pair in array such that i<j && arr[i]>arr[j];
// we will use here merge sort ;
long long merge(long long *arr,int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int arr1[len1];
    int arr2[len2];
    int mainindex=start;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainindex++];
    }
    mainindex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainindex++];
    }
    int k=start;
    long long count=0;
    int i=0;
    int j=0;
    while(i<len1 && j<len2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr[k]=arr2[j];
            count=count+(len1-i);
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
long long mergesort(long long *arr,int s,int e){
    long long count=0;
    if(s<e){
        int mid=s+(e-s)/2;  
        count+=mergesort(arr,s,mid);   //global variable bhi use kr skte h ;
        count+=mergesort(arr,mid+1,e);
        count+=merge(arr,s,e);
    }
    return count; 
}
long long getInversions(long long *arr, int n){
     return mergesort(arr,0,n-1);
}

