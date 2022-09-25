using namespace std;
#include<bits/stdc++.h>
#include<iostream>

void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int timer,vector<int>adj[]){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        if(vis[it]==0){
            dfs(it,node,vis,tin,low,timer,adj);
            //aate time call se
            low[node]=min(low[node],low[it]);
            if(low[it]<tin[node]){
                cout<<node<<" "<<it<<endl;
            }
        }
        else{
            low[node]=min(low[node],tin[it]);
        }
    }

}


int main(){
    int n,m;// here n is node and m is the no of edges;
    cout<<"enter no. of nodes and edges"<<endl;
    cin>>n>>m;
    vector<int>adj[n+1];
    cout<<"enter the connections"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>vis(n,0);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,tin,low,timer,adj);
        }
    }
    return 0;

}