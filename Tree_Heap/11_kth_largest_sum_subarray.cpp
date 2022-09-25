#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getkthlargest(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>>q;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(q.size()<k){
                q.push(sum);
            }
            else{
                if(sum>q.top()){
                    q.pop();
                    q.push(sum);

                }
            }
        }
    }
    return q.top();
}