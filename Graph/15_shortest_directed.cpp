#include<bits/stdc++.h>
using namespace std;
void findtopo_sort(int i,int vis[],stack<int>&st,vector<pair<int,int>>adj[]){
    //have done before
}
void shortestpath(int src,int n,vector<pair<int,int>>adj[]){
    int vis[n+1]={0};
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            findtopo_sort(i,vis,st,adj);
        }
    }
    int dist[n+1];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX){
            for(auto it:adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }
    //cout<<dist[i]<<end;

}