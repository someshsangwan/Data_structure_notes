#include<bits/stdc++.h>
using namespace std;
 
/* intern is temporary but placement is permanent*/
#include<iostream>
int bellmen_ford(int n,int m,int src,int dest,vector<vector<int>>edges){
    vector<int>dis(n+1,1e9);
    dis[src]=0;
    //we run loop n-1 time;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            if(dis[u]!=1e9 && (dis[u]+wt<dis[v])){
                dis[v]=dis[u]+wt;
            }
        }
    }
    return dis[dest];
    //if we want to check there is an negative sycle 
    /*
    bool flag=0;
    for(int j=0;j<m;j++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            if(dis[u]!=1e9 && (dis[u]+wt<dis[v])){
                flag=1;
            }
        }
    if(flag==0){
        return 0;
    }
    else{
        return 1; yes there is a  negative cycle in our graph;
    }
    */

}