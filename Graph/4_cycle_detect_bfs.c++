#include<bits/stdc++.h>
using namespace std;
#include<iostream>
bool checkcycle(int s,int v,vector<int>adj[],vector<int>&vis){
    queue<pair<int,int>>q;
    vis[s]=1;
    q.push({s,-1});
    while(!q.empty()){
        int node=q.front().first;
        int prev=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[node]){
                vis[it]=1;
                q.push({it,node});

            }
        
            else if(it!=prev){
                return true;
            }
        }
        
    }
    return false;
}
bool ischeck(int v, vector<int>adj[]){
    vector<int>vis(v+1,0);
    for(int i=0;i<v;i++){//we will check cycle in every component 
    if(vis[i]==0){
        if(checkcycle(i,v,adj,vis)){
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