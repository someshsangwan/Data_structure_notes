#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
i/p ={ 2,1,4,3};
o/p={1,-1,3,-1};
i/p={4,8,5,2,25};
o/p={2,5,2,-1,-1}// 8 ka 5 isliye aaya bcz we just need next smaller na not a smallest;
*/
//brute force use two loop
vector<int>func(vector<int>&arr){
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        int x=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<x){
                x=arr[j];
                break;
            }
        }
        if(x!=arr[i]){
            ans.push_back(x);
        }
        else{
            ans.push_back(-1);
        }
    }
    return ans;
}
vector<int>func2(vector<int>&arr){
    stack<int>s;
    int n=arr.size();
    vector<int>ans(n);
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int ch=arr[i];
        while(s.top()>=ch){
            s.pop();
        }
        ans[i]=s.top();
        s.push(ch);
    }
    return ans;

}
int main(){
    vector<int>ans;
    ans.push_back(4);
    ans.push_back(8);
    ans.push_back(5);
    ans.push_back(2);
    ans.push_back(25);
    vector<int>res=func2(ans);
    for(auto it:res){
        cout<<it<<" ";
    }
}