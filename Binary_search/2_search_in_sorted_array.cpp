#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool check(int arr[],int n,int start , int end,int x){
    while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==x){
        return 1;
    }
    else if(arr[mid]>x){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    }
    return 0;
}
int main(){
     int arr[]={1,4,6,34,39,41,45};
     int n=7;
     cout<<check(arr,n,0,n-1,44)<<endl;
}