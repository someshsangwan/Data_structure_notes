#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//given that there is array , every ith element represent stock price , you are allowed for anly one transaction(you can buy one times and sell only one time);
// find the max profit;

int main(){
    int arr[]={8,1,4,1,9};
    int n=5;
    int curr=arr[0];
    int res=INT_MIN;
    for(int i=1;i<n;i++){
        int profit=arr[i]-curr;
        res=max(res,profit);
        if(arr[i]<curr){
            curr=arr[i];
        }
    }
    cout<<res<<endl;
}