using namespace std;
#include<bits/stdc++.h>
#include<iostream>

void bfs_short(vector<int>adj[],int n,int src){// src means the node from where we are check shortest path for another node;
    int dist[n+1]; //is starting index of graph is 0 , so better use n+1 in every case;
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX; /// use vector vector<int>dist(n+1,INT_MAX);
    }
    queue<int>q;
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<"   ";
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

    return 0;

}