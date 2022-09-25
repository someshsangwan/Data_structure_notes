#include<bits/stdc++.h>
using namespace std;
#include<iostream>
bool checkcycle(int node,int parent ,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            if(checkcycle(it,node,vis,adj)){
                return true;
            }
        }
            else if(it!=parent){
                return true;
            }
        
    }
    return false;

}
bool ischeck(int v, vector<int>adj[]){
    vector<int>vis(v+1,0);
    for(int i=0;i<v;i++){//we will check cycle in every component 
    if(vis[i]==0){
        if(checkcycle(i,-1,vis,adj)){
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
    cout<<ischeck(n,adj)<<endl;
    return 0;

}