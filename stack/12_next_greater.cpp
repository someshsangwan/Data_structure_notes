#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//next smaller ke jaisa hi code h;
vector<int>func2(vector<int>&arr){
    stack<int>s;
    int n=arr.size();
    vector<int>ans(n);
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int ch=arr[i];
        while(s.top()>=ch){ //s.top()<=ch
            s.pop();
        }
        ans[i]=s.top();
        s.push(ch);
    }
    return ans;

}
// prev smaller -- int i=0;i<n;i++       while(s.top()>=curr);
// prev greater -- int i=0;i<n;i++       while(s.top()<=curr);