#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// probelm is that given start time and end time of meet required meet rooom for confrence ;
//same as no. of platform required.
int solve(vector<vector<int> > &A) {
    vector<int>start;
    int n=A.size();
    vector<int>end;
    for(int i=0;i<n;i++){
        start.push_back(A[i][0]);
        end.push_back(A[i][1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=0;
    int j=0;
    int room=0;
    int res=0;
    while(i<n && j<n){
        if(start[i]<end[j]){
            room++;
            i++;
        }
        else{
            room--;
            j++;
        }
        res=max(res,room);
    }
    return res;
