#include<bits/stdc++.h>
using namespace std;
void dijkstra(int src,int n, vector<pair<int,int>>adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap
    vector<int>dist(n+1,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int disti=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        // vector<pair<int,int>>::iterator it;
        //auto it=
        for(auto it:adj[prev]){
            int next=it.first; // in adjacentry list pair first have the node and second weight
            int nextdist=it.second;
            if(dist[next]>disti+nextdist){
                dist[next]=disti+nextdist;
                pq.push({dist[next],next});
            }

        }
    }
      ///cout<<dist[i]<<"  ";


}

int main(){
    int n,m;// here n is node and m is the no of edges;
    cout<<"enter no. of nodes and edges"<<endl;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    cout<<"enter the connections"<<endl;
    int src;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cout<<"enter your src node "<<endl;
    cin>>src;

    return 0;

}