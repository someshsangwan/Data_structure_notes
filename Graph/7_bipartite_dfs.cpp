#include<bits/stdc++.h>
using namespace std;
#include<iostream>
bool bipartite(int node,vector<int>adj[],int color[]){
     if(color[node]==-1){
         color[node]=1;
     }
     for(auto it:adj[node]){
         if(color[it]==-1){
             color[it]=1-color[node];
             if(!bipartite(it,adj,color)){
                 return false;
             }
         }
        else if(color[it]==color[node]){
            return false;
        }
         
     }
     return true;
}

bool checkbipartite(vector<int>adj[],int n){
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++){   // for(int i=1;i<=n;i++) if indexing starts from 1 of graph;
        if(color[i]==-1){
            if(!bipartite(i,adj,color)){
                return false;
            }
        }
    }
    return true;

}