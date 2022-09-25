using namespace std;
#include<bits/stdc++.h>
#include<iostream>
bool checkcycle(int node,vector<int>adj[],int vis[],int dfsvis[]){
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            if(checkcycle(it,adj,vis,dfsvis)){
                return true;
            }
        }
        else if(dfsvis[it]){
            return true;
        }
        
    }
    dfsvis[node]=0;
    return false;
}
bool iscycle(int n,vector<int>adj[]){
    int vis[n];
    int dfsvis[n];
    memset(vis,0,sizeof(vis));
    memset(dfsvis,0,sizeof(dfsvis));
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(checkcycle(i,adj,vis,dfsvis)){
                return true;
            }
        }
    }
    return false;
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
    return 0;

}