#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// given n integers  , generate all subset ;
// arr[]={2,3,5} -- output -- {2},{3},{5},{2,3},{2,5},{3,5},{2,3,5},{}----2^3=8 subsets h total ;
//time complexity -- n*2^n its not a efficient solution but its an application of bit manipulation;
int main(){
    int arr[]={2,3,5};
    vector<vector<int>>ans;
    int n=3;
    int till=pow(2,n);
    for(int i=0;i<till;i++){
        vector<int>temp;
        for(int bit=0;bit<n;bit++){
            if(i&1<<bit){
                temp.push_back(arr[bit]);
            }
        }
        ans.push_back(temp);

    }
    for(auto num:ans){
        for(int i=0;i<num.size();i++){
             cout<<num[i]<<" ";
        }cout<<endl;
    }
}