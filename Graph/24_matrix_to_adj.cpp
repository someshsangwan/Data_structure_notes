using namespace std;
#include<bits/stdc++.h>
#include<iostream>
/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected 
directly with city c, then city a is connected indirectly with city c.A province is a group of directly or indirectly connected cities and
 no other cities outside of the group. You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the 
 jth city are directly connected, and isConnected[i][j] = 0 otherwise.*/
void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {//in this we have 1 indexing 
        int m=isconnected.size();
        int n=isconnected[0].size();
        vector<int>adj[m+1];
        for(int i=0;i<m;i++ ){
            for(int j=0;j<n;j++){
                if(isconnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                    
                }
            }
        }
        vector<int>vis(m+1,0);
        int ct=0;
        for(int i=1;i<=m;i++){
            if(!vis[i]){
                ct++;
                dfs(i,vis,adj);
            }
            
        }
        return ct;
        
    }