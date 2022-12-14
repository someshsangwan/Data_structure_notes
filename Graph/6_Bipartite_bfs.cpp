#include<bits/stdc++.h>
using namespace std;
#include<iostream>
bool bipartite(int src,vector<int>adj[],int color[]){
    queue<int>q;
    q.push(src);
    color[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                q.push(it);

            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
}

bool checkbipartite(vector<int>adj[],int n){
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!bipartite(i,adj,color)){
                return false;
            }
        }
    }
    return true;

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