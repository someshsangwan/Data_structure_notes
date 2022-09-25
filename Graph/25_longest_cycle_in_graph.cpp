#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//probelm
// max size node cycle in dircted graph ;
void checkcycle(int node,vector<int>adj[],vector<int>&vis,int dfsvis[],int &ans,int dist[],int distance){
    vis[node]=1;
    dfsvis[node]=1;
    dist[node]=distance;
    for(auto it:adj[node]){
        if(vis[it]==0){
            
            checkcycle(it,adj,vis,dfsvis,ans,dist,distance+1);   
            return;
        }
        else if(dfsvis[it]){
            ans=dist[node]-dist[it]+1; //important concept
            return ;
        }
        
    } 
    dfsvis[node]=0;
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
      vector<int>vis(n,0);
      int dfsvis[n];
      int dist[n];
      memset(dfsvis,0,sizeof(dfsvis));
      memset(dist,0,sizeof(dist));
        
    int res=-1;
      for(int i=0;i<n;i++){
          int ans=-2;
          if(vis[i]==0){
          checkcycle(i,adj,vis,dfsvis,ans,dist,0);
          }
          res=max(res,ans);  
      }
    return res;
        
      
        
        
    }
