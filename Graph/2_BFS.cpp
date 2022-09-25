using namespace std;
#include<bits/stdc++.h>
#include<iostream>
vector<int>bfsgraph(int n, vector<int>adj[]){
    vector<int>bfs;
    vector<int>vis(n+1,0);
    vector<int>bfs;
    for(int i=0;i<n;i++){ //this for loop only used for to know is there any component ot not , to connect these component we use for loop;
        if(vis[i]=0){ 
            queue<int>q;
            q.push(i);  //if this start from 0 else loop also start from 1;
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node]){
                    if(vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }










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
    return 0;

}