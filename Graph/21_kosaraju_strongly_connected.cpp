using namespace std;
#include<bits/stdc++.h>
#include<iostream>
void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);

}
void revdfs(int node,vector<int>&vis,vector<int>transpose[]){
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revdfs(it,vis,transpose);
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
    vector<int>vis(n+1,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>transpose[n]; // we create a adjacentry list here we reverse direction;
    for(int i=0;i<n;i++){
        vis[i]=0;// in topo sort we marked 1 in every traversal so to accesss it next time we make it zero;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SCC-";
            revdfs(node,vis,transpose);
        }cout<<endl;
    }





    return 0;

}