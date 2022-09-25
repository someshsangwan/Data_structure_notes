using namespace std;
#include<bits/stdc++.h>
#include<iostream>



vector<int>toposort_bfs_kahns(int n , vector<int>adj[]){
    queue<int>q;
    vector<int>indegree(n+1,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node =q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
        
    }
    return topo;


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
        adj[u].push_back(v);//its topo sort that can possible in directed graph;
        //adj[v].push_back(u);

    }
    vector<int>ans;
    ans=toposort_bfs_kahns(n,adj);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;

}