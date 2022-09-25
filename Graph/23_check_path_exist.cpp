#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<vector>
bool check_path(int start,int end,vector<int>adj[],vector<int>&vis){
    vis[start]=1;
    if(start==end){
        return true;
    }
    for(auto it:adj[start]){
        if(!vis[it]){
            if(check_path(it,end,adj,vis)){
                return true;
            }
        }
    }
    return false;
}
int solve(int A, vector<vector<int>>&B) {
    int n=B.size();
    vector<int>adj[A+1]; //we always take it = 1+ no of node in graph
    for(int i=0;i<n;i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<int>vis(A+1,0);
    return check_path(1,A,adj,vis);
}