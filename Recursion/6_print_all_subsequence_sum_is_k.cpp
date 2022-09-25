#include<iostream>
using namespace std;
#include<bits/stdc++.h>



void prints(int arr[],int target, int n,int sum ,int idx,vector<int>&ds){
    if(idx>=n){
        if(sum==target){
            for(auto i:ds){
                cout<<i<<" ";
            }cout<<endl;
        }
        return;
    }
    ds.push_back(arr[idx]);
    sum=sum+arr[idx];
    prints(arr,target,n,sum,idx+1,ds);
    ds.pop_back();
    sum=sum-arr[idx];
    prints(arr,target,n,sum,idx+1,ds);
}



int main(){
    int arr[]={1,2,1};
    int target=3;
    int n=3;
    int sum=0;
    int idx=0;
    vector<int>ds;
    prints(arr,target,n,sum,idx,ds);

}