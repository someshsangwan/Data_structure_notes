#include<bits/stdc++.h>
using namespace std;
#include<iostream>
void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&ans){
    ans.push_back(node);   /*phle ek node ke depth me jao */
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,ans);
        }
    }

}
vector<int>Dfs_graph(int n,vector<int>adj[]){
    vector<int>ans;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){ //here we start from 1;
        if(vis[i]==0){
            dfs(i,vis,adj,ans);
        }
    }
    return ans;
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