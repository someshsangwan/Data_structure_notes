using namespace std;
#include<bits/stdc++.h>
#include<iostream>

//only for directed non cyclic graph;
//not for undirected graph;
//only for non cyclic graph;
void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);

}
vector<int> toposort( int n, vector<int>adj[]){
    vector<int>vis(n+1,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();

    }
    return ans;
}